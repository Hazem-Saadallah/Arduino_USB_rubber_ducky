#include "KeyDef.hxx"
#include <string.h>
#include <Keyboard.h>
#include <Command.hxx>
#include <Key.hxx>
#include <Interpreter.hxx>


Interpreter::Interpreter() { Keyboard.begin(KeyboardLayout_en_US); }
Interpreter::~Interpreter() { Keyboard.end(); }

void Interpreter::command_error() {
  while (1) {
    Serial.println("ERROR");
    delay(1000);
  }
}

inline bool Interpreter::has_params(char params[]) {
  return params != nullptr;
}

void Interpreter::exec_line(char line[]) {
  char *saveptr;
  char *command = strtok_r(line, " ", &saveptr);
  if(!command || !strcmp(command, Command::CMD_REM_STR) || !strncmp(command, "//", 2)) return;
  if(!strcmp(command, Command::CMD_DELAY_STR)) {
    char *params = strtok_r(nullptr, "", &saveptr);
    if(has_params(params)) if(!Command::Delay(params)) command_error();
  } else if(!strcmp(command, Command::CMD_STRING_STR)) {
    char *params = strtok_r(nullptr, "", &saveptr);
    if(has_params(params)) if(!Command::String(params)) command_error();
  } else {
    do {
      press(command);
      command = strtok_r(nullptr, " ", &saveptr);
    } while(command);
    Keyboard.releaseAll();
  }
}

void Interpreter::exec_script(char data[]) {
  char* saveptr;
  char* line = strtok_r(data, "\r\n", &saveptr);
  while (line != nullptr) {
    exec_line(line);
    line = strtok_r(nullptr, "\r\n", &saveptr);
  }
}

void Interpreter::press(char key[]) {
  if(strlen(key) == 1) {
    Keyboard.press(key[0]);
    return;
  }

  uint32_t hash = KeyDef::hash_string_runtime(key);
  switch (hash) {
		case Key::KEY_DEF_GUI.get_hash(): Keyboard.press(Key::KEY_DEF_GUI.get_id()); break;
		case Key::KEY_DEF_LGUI.get_hash(): Keyboard.press(Key::KEY_DEF_LGUI.get_id()); break;
		case Key::KEY_DEF_RGUI.get_hash(): Keyboard.press(Key::KEY_DEF_RGUI.get_id()); break;
		case Key::KEY_DEF_SHIFT.get_hash(): Keyboard.press(Key::KEY_DEF_SHIFT.get_id()); break;
		case Key::KEY_DEF_LSHIFT.get_hash(): Keyboard.press(Key::KEY_DEF_LSHIFT.get_id()); break;
		case Key::KEY_DEF_RSHIFT.get_hash(): Keyboard.press(Key::KEY_DEF_RSHIFT.get_id()); break;
		case Key::KEY_DEF_CTRL.get_hash(): Keyboard.press(Key::KEY_DEF_CTRL.get_id()); break;
		case Key::KEY_DEF_LCTRL.get_hash(): Keyboard.press(Key::KEY_DEF_LCTRL.get_id()); break;
		case Key::KEY_DEF_RCTRL.get_hash(): Keyboard.press(Key::KEY_DEF_RCTRL.get_id()); break;
		case Key::KEY_DEF_ALT.get_hash(): Keyboard.press(Key::KEY_DEF_ALT.get_id()); break;
		case Key::KEY_DEF_LALT.get_hash(): Keyboard.press(Key::KEY_DEF_LALT.get_id()); break;
		case Key::KEY_DEF_RALT.get_hash(): Keyboard.press(Key::KEY_DEF_RALT.get_id()); break;

// Misc keys
		case Key::KEY_DEF_ARROW_UP.get_hash(): Keyboard.press(Key::KEY_DEF_ARROW_UP.get_id()); break;
		case Key::KEY_DEF_UP.get_hash(): Keyboard.press(Key::KEY_DEF_UP.get_id()); break;
		case Key::KEY_DEF_ARROW_DOWN.get_hash(): Keyboard.press(Key::KEY_DEF_ARROW_DOWN.get_id()); break;
		case Key::KEY_DEF_DOWN.get_hash(): Keyboard.press(Key::KEY_DEF_DOWN.get_id()); break;
		case Key::KEY_DEF_ARROW_LEFT.get_hash(): Keyboard.press(Key::KEY_DEF_ARROW_LEFT.get_id()); break;
		case Key::KEY_DEF_LEFT.get_hash(): Keyboard.press(Key::KEY_DEF_LEFT.get_id()); break;
		case Key::KEY_DEF_ARROW_RIGHT.get_hash(): Keyboard.press(Key::KEY_DEF_ARROW_RIGHT.get_id()); break;
		case Key::KEY_DEF_RIGHT.get_hash(): Keyboard.press(Key::KEY_DEF_RIGHT.get_id()); break;
		case Key::KEY_DEF_BACKSPACE.get_hash(): Keyboard.press(Key::KEY_DEF_BACKSPACE.get_id()); break;
		case Key::KEY_DEF_TAB.get_hash(): Keyboard.press(Key::KEY_DEF_TAB.get_id()); break;
		case Key::KEY_DEF_ENTER.get_hash(): Keyboard.press(Key::KEY_DEF_ENTER.get_id()); break;
		case Key::KEY_DEF_RETURN.get_hash(): Keyboard.press(Key::KEY_DEF_RETURN.get_id()); break;
		case Key::KEY_DEF_MENU.get_hash(): Keyboard.press(Key::KEY_DEF_MENU.get_id()); break;
		case Key::KEY_DEF_APP.get_hash(): Keyboard.press(Key::KEY_DEF_APP.get_id()); break;

		case Key::KEY_DEF_ESC.get_hash(): Keyboard.press(Key::KEY_DEF_ESC.get_id()); break;
		case Key::KEY_DEF_INSERT.get_hash(): Keyboard.press(Key::KEY_DEF_INSERT.get_id()); break;
		case Key::KEY_DEF_DELETE.get_hash(): Keyboard.press(Key::KEY_DEF_DELETE.get_id()); break;
		case Key::KEY_DEF_PAGE_UP.get_hash(): Keyboard.press(Key::KEY_DEF_PAGE_UP.get_id()); break;
		case Key::KEY_DEF_PAGE_DOWN.get_hash(): Keyboard.press(Key::KEY_DEF_PAGE_DOWN.get_id()); break;
		case Key::KEY_DEF_HOME.get_hash(): Keyboard.press(Key::KEY_DEF_HOME.get_id()); break;
		case Key::KEY_DEF_END.get_hash(): Keyboard.press(Key::KEY_DEF_END.get_id()); break;
		case Key::KEY_DEF_CAPS_LOCK.get_hash(): Keyboard.press(Key::KEY_DEF_CAPS_LOCK.get_id()); break;
		case Key::KEY_DEF_PRINT_SCREEN.get_hash(): Keyboard.press(Key::KEY_DEF_PRINT_SCREEN.get_id()); break;
		case Key::KEY_DEF_SCROLL_LOCK.get_hash(): Keyboard.press(Key::KEY_DEF_SCROLL_LOCK.get_id()); break;
		case Key::KEY_DEF_PAUSE.get_hash(): Keyboard.press(Key::KEY_DEF_PAUSE.get_id()); break;

// Numeric keypad
		case Key::KEY_DEF_NUM_LOCK.get_hash(): Keyboard.press(Key::KEY_DEF_NUM_LOCK.get_id()); break;
		case Key::KEY_DEF_KP_SLASH.get_hash(): Keyboard.press(Key::KEY_DEF_KP_SLASH.get_id()); break;
		case Key::KEY_DEF_KP_ASTERISK.get_hash(): Keyboard.press(Key::KEY_DEF_KP_ASTERISK.get_id()); break;
		case Key::KEY_DEF_KP_MINUS.get_hash(): Keyboard.press(Key::KEY_DEF_KP_MINUS.get_id()); break;
		case Key::KEY_DEF_KP_PLUS.get_hash(): Keyboard.press(Key::KEY_DEF_KP_PLUS.get_id()); break;
		case Key::KEY_DEF_KP_ENTER.get_hash(): Keyboard.press(Key::KEY_DEF_KP_ENTER.get_id()); break;
		case Key::KEY_DEF_KP_1.get_hash(): Keyboard.press(Key::KEY_DEF_KP_1.get_id()); break;
		case Key::KEY_DEF_KP_2.get_hash(): Keyboard.press(Key::KEY_DEF_KP_2.get_id()); break;
		case Key::KEY_DEF_KP_3.get_hash(): Keyboard.press(Key::KEY_DEF_KP_3.get_id()); break;
		case Key::KEY_DEF_KP_4.get_hash(): Keyboard.press(Key::KEY_DEF_KP_4.get_id()); break;
		case Key::KEY_DEF_KP_5.get_hash(): Keyboard.press(Key::KEY_DEF_KP_5.get_id()); break;
		case Key::KEY_DEF_KP_6.get_hash(): Keyboard.press(Key::KEY_DEF_KP_6.get_id()); break;
		case Key::KEY_DEF_KP_7.get_hash(): Keyboard.press(Key::KEY_DEF_KP_7.get_id()); break;
		case Key::KEY_DEF_KP_8.get_hash(): Keyboard.press(Key::KEY_DEF_KP_8.get_id()); break;
		case Key::KEY_DEF_KP_9.get_hash(): Keyboard.press(Key::KEY_DEF_KP_9.get_id()); break;
		case Key::KEY_DEF_KP_0.get_hash(): Keyboard.press(Key::KEY_DEF_KP_0.get_id()); break;
		case Key::KEY_DEF_KP_DOT.get_hash(): Keyboard.press(Key::KEY_DEF_KP_DOT.get_id()); break;

// Function keys
		case Key::KEY_DEF_F1.get_hash(): Keyboard.press(Key::KEY_DEF_F1.get_id()); break;
		case Key::KEY_DEF_F2.get_hash(): Keyboard.press(Key::KEY_DEF_F2.get_id()); break;
		case Key::KEY_DEF_F3.get_hash(): Keyboard.press(Key::KEY_DEF_F3.get_id()); break;
		case Key::KEY_DEF_F4.get_hash(): Keyboard.press(Key::KEY_DEF_F4.get_id()); break;
		case Key::KEY_DEF_F5.get_hash(): Keyboard.press(Key::KEY_DEF_F5.get_id()); break;
		case Key::KEY_DEF_F6.get_hash(): Keyboard.press(Key::KEY_DEF_F6.get_id()); break;
		case Key::KEY_DEF_F7.get_hash(): Keyboard.press(Key::KEY_DEF_F7.get_id()); break;
		case Key::KEY_DEF_F8.get_hash(): Keyboard.press(Key::KEY_DEF_F8.get_id()); break;
		case Key::KEY_DEF_F9.get_hash(): Keyboard.press(Key::KEY_DEF_F9.get_id()); break;
		case Key::KEY_DEF_F10.get_hash(): Keyboard.press(Key::KEY_DEF_F10.get_id()); break;
		case Key::KEY_DEF_F11.get_hash(): Keyboard.press(Key::KEY_DEF_F11.get_id()); break;
		case Key::KEY_DEF_F12.get_hash(): Keyboard.press(Key::KEY_DEF_F12.get_id()); break;
		case Key::KEY_DEF_F13.get_hash(): Keyboard.press(Key::KEY_DEF_F13.get_id()); break;
		case Key::KEY_DEF_F14.get_hash(): Keyboard.press(Key::KEY_DEF_F14.get_id()); break;
		case Key::KEY_DEF_F15.get_hash(): Keyboard.press(Key::KEY_DEF_F15.get_id()); break;
		case Key::KEY_DEF_F16.get_hash(): Keyboard.press(Key::KEY_DEF_F16.get_id()); break;
		case Key::KEY_DEF_F17.get_hash(): Keyboard.press(Key::KEY_DEF_F17.get_id()); break;
		case Key::KEY_DEF_F18.get_hash(): Keyboard.press(Key::KEY_DEF_F18.get_id()); break;
		case Key::KEY_DEF_F19.get_hash(): Keyboard.press(Key::KEY_DEF_F19.get_id()); break;
		case Key::KEY_DEF_F20.get_hash(): Keyboard.press(Key::KEY_DEF_F20.get_id()); break;
		case Key::KEY_DEF_F21.get_hash(): Keyboard.press(Key::KEY_DEF_F21.get_id()); break;
		case Key::KEY_DEF_F22.get_hash(): Keyboard.press(Key::KEY_DEF_F22.get_id()); break;
		case Key::KEY_DEF_F23.get_hash(): Keyboard.press(Key::KEY_DEF_F23.get_id()); break;
		case Key::KEY_DEF_F24.get_hash(): Keyboard.press(Key::KEY_DEF_F24.get_id()); break;

    default: command_error();
  }
}
