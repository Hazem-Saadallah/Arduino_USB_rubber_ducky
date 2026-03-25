#pragma once

#include <Arduino.h>
#include <Keyboard.h>
#include <Pair.hxx>

class Interpreter {
public:
  Interpreter();
  ~Interpreter();
  Interpreter(Interpreter &&) noexcept = default;
  Interpreter &operator=(Interpreter &&) noexcept = default;
  Interpreter(const Interpreter &) = default;
  Interpreter &operator=(const Interpreter &) = default;

  void exec_line(char line[]);
  void exec_script(char line[]);

private:
  static void press(char key[]);
  static void command_error();
  inline bool has_params(char params[]);
  void hash_command();
};
