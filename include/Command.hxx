#pragma once

namespace Command {
  static constexpr char* CMD_REM_STR = "REM";;
  static constexpr char* CMD_STRING_STR = "STRING";;
  static constexpr char* CMD_DELAY_STR = "DELAY";;

  [[nodiscard]] bool String(char params[]);
  [[nodiscard]] bool Delay(char params[]);
};
