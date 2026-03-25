#include <Arduino.h>
#include <Keyboard.h>
#include <Command.hxx>

bool Command::String(char params[]) {
  return static_cast<bool>(Keyboard.print(params));
}

bool Command::Delay(char params[]) {
  char* endptr;
  long value = strtol(params, &endptr, 10);
  if(params == endptr || (*endptr != '\0' && *endptr != '\r' && *endptr != '\n')) return false;
  delay(value);
  return true;
}
