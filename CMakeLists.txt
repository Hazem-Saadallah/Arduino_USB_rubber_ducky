set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
cmake_minimum_required(VERSION 3.31)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

# ==============================================================================
# 1. SETUP & CLONE TOOLCHAIN
# ==============================================================================
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(COMMON_LIBS core Keyboard SD)
set(COMMON_COMPILE_OPTIONS -Wall -Wextra)
set(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cxx
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Interpreter.cxx
  ${CMAKE_CURRENT_SOURCE_DIR}/src/KeyDef.cxx
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Command.cxx
)

set(EXTERN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/extern")
set(TOOLCHAIN_DIR "${EXTERN_DIR}/Arduino-CMake-Toolchain")

if(NOT EXISTS "${TOOLCHAIN_DIR}")
  message(STATUS "Cloning Arduino-CMake-Toolchain...")
  execute_process(COMMAND git clone https://github.com/technyon/Arduino-CMake-Toolchain.git "${TOOLCHAIN_DIR}")
  
  message(STATUS "Patching Arduino-toolchain.cmake for newer CMake policies...")
  file(READ "${TOOLCHAIN_DIR}/Arduino-toolchain.cmake" TOOLCHAIN_CONTENT)
  string(REPLACE "VERSION 3.0" "VERSION 3.10" PATCHED_CONTENT "${TOOLCHAIN_CONTENT}")
  file(WRITE "${TOOLCHAIN_DIR}/Arduino-toolchain.cmake" "${PATCHED_CONTENT}")
endif()

# ==============================================================================
# 2. THE SURGICAL STRIKE: PATCH THE GLOBAL ARDUINO CORE
# ==============================================================================
file(GLOB_RECURSE GLOBAL_PLATFORM_TXT "$ENV{HOME}/.arduino15/packages/arduino/hardware/avr/*/platform.txt")

foreach(PLATFORM_TXT_FILE IN LISTS GLOBAL_PLATFORM_TXT)
  file(READ "${PLATFORM_TXT_FILE}" PLATFORM_CONTENT)
  if(NOT PLATFORM_CONTENT MATCHES "compiler\\.path=\n")
    message(STATUS "Patching global platform.txt to defer to system avr-gcc 15: ${PLATFORM_TXT_FILE}")
    string(REGEX REPLACE "compiler\\.path=[^\r\n]*" "compiler.path=" PATCHED_PLATFORM "${PLATFORM_CONTENT}")
    file(WRITE "${PLATFORM_TXT_FILE}" "${PATCHED_PLATFORM}")
  endif()
endforeach()

# ==============================================================================
# 3. TRICK THE TOOLCHAIN (THE "FAKE IDE" FIX)
# ==============================================================================
file(MAKE_DIRECTORY "${EXTERN_DIR}/lib")
if(NOT EXISTS "${EXTERN_DIR}/lib/version.txt")
  file(WRITE "${EXTERN_DIR}/lib/version.txt" "1.8.19\n")
endif()
set(ARDUINO_INSTALL_PATH "${EXTERN_DIR}" CACHE PATH "Path to standalone Arduino core" FORCE)

# ==============================================================================
# 4. DEFINE BOARD AND PROJECT
# ==============================================================================
set(CMAKE_TOOLCHAIN_FILE "${TOOLCHAIN_DIR}/Arduino-toolchain.cmake")
set(ARDUINO_BOARD "Arduino Micro [avr.micro]" CACHE STRING "Selected Arduino Board" FORCE)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

list(APPEND CMAKE_TRY_COMPILE_PLATFORM_VARIABLES ARDUINO_INSTALL_PATH ARDUINO_BOARD)

project(USBRubberDucky C CXX ASM)

# ==============================================================================
# 5. BUILD THE EXECUTABLE
# ==============================================================================

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
target_compile_options(${PROJECT_NAME} PRIVATE ${COMMON_COMPILE_OPTIONS})

target_link_arduino_libraries(${PROJECT_NAME} PRIVATE ${COMMON_LIBS})

set_target_properties(${PROJECT_NAME} PROPERTIES ARDUINO_UPLOAD_PORT /dev/ttyACM0)
target_enable_arduino_upload(${PROJECT_NAME})

add_custom_target(upload
  COMMAND stty -F /dev/ttyACM0 1200
  COMMAND sleep 1
  COMMENT "Preparing Arduino for upload ${SERIAL_PORT}..."

  COMMAND avrdude -vvvvv -p atmega32u4 -c avr109 -P /dev/ttyACM0 -b 57600 -D -U flash:w:${PROJECT_NAME}.hex:i
  DEPENDS ${PROJECT_NAME}.hex
  COMMENT "Uploading firmware to ${SERIAL_PORT}..."
)

add_custom_target(monitor
  COMMAND minicom -D /dev/ttyACM0 -b 9600
  USES_TERMINAL
)

add_custom_target(flash
  COMMAND ${CMAKE_COMMAND} --build . --target upload
  COMMAND ${CMAKE_COMMAND} --build . --target monitor
  COMMENT "Flashing and jumping straight to monitor..."
  USES_TERMINAL
)
