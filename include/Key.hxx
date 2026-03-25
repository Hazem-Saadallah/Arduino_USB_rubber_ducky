#pragma once

#include <Keyboard.h>
#include <KeyDef.hxx>
#include <avr/pgmspace.h>

namespace Key {
  // Modifiers
  static constexpr KeyDef KEY_DEF_GUI = KeyDef(KEY_LEFT_GUI, "GUI");
  static constexpr KeyDef KEY_DEF_LGUI = KeyDef(KEY_LEFT_GUI, "LGUI");;
  static constexpr KeyDef KEY_DEF_RGUI = KeyDef(KEY_RIGHT_GUI, "RGUI");
  static constexpr KeyDef KEY_DEF_WINDOWS = KeyDef(KEY_LEFT_GUI, "WINDOWS");
  static constexpr KeyDef KEY_DEF_LWINDOWS = KeyDef(KEY_LEFT_GUI, "LWINDOWS");;
  static constexpr KeyDef KEY_DEF_RWINDOWS = KeyDef(KEY_RIGHT_GUI, "RWINDOWS");
  static constexpr KeyDef KEY_DEF_COMMAND = KeyDef(KEY_LEFT_GUI, "COMMAND");
  static constexpr KeyDef KEY_DEF_LCOMMAND = KeyDef(KEY_LEFT_GUI, "LCOMMAND");;
  static constexpr KeyDef KEY_DEF_RCOMMAND = KeyDef(KEY_RIGHT_GUI, "RCOMMAND");
  static constexpr KeyDef KEY_DEF_SHIFT = KeyDef(KEY_LEFT_SHIFT, "SHIFT");
  static constexpr KeyDef KEY_DEF_LSHIFT = KeyDef(KEY_LEFT_SHIFT, "LSHIFT");
  static constexpr KeyDef KEY_DEF_RSHIFT = KeyDef(KEY_RIGHT_SHIFT, "RSHIFT");
  static constexpr KeyDef KEY_DEF_CTRL = KeyDef(KEY_LEFT_CTRL, "CTRL");
  static constexpr KeyDef KEY_DEF_LCTRL = KeyDef(KEY_LEFT_CTRL, "LCTRL");
  static constexpr KeyDef KEY_DEF_RCTRL = KeyDef(KEY_RIGHT_CTRL, "RCTRL");
  static constexpr KeyDef KEY_DEF_CONTROL = KeyDef(KEY_LEFT_CTRL, "CONTROL");
  static constexpr KeyDef KEY_DEF_LCONTROL = KeyDef(KEY_LEFT_CTRL, "LCONTROL");
  static constexpr KeyDef KEY_DEF_RCONTROL = KeyDef(KEY_RIGHT_CTRL, "RCONTROL");
  static constexpr KeyDef KEY_DEF_ALT = KeyDef(KEY_LEFT_ALT, "ALT");
  static constexpr KeyDef KEY_DEF_LALT = KeyDef(KEY_LEFT_ALT, "LALT");
  static constexpr KeyDef KEY_DEF_RALT = KeyDef(KEY_RIGHT_ALT, "RALT");

  // Misc keys
  static constexpr KeyDef KEY_DEF_ARROW_UP = KeyDef(KEY_UP_ARROW, "UPARROW");
  static constexpr KeyDef KEY_DEF_UP = KeyDef(KEY_UP_ARROW, "UP");
  static constexpr KeyDef KEY_DEF_ARROW_DOWN = KeyDef(KEY_DOWN_ARROW, "DOWNARROW");
  static constexpr KeyDef KEY_DEF_DOWN = KeyDef(KEY_DOWN_ARROW, "DOWN");
  static constexpr KeyDef KEY_DEF_ARROW_LEFT = KeyDef(KEY_LEFT_ARROW, "LEFTARROW");
  static constexpr KeyDef KEY_DEF_LEFT = KeyDef(KEY_LEFT_ARROW, "LEFT");
  static constexpr KeyDef KEY_DEF_ARROW_RIGHT = KeyDef(KEY_RIGHT_ARROW, "RIGHTARROW");
  static constexpr KeyDef KEY_DEF_RIGHT = KeyDef(KEY_RIGHT_ARROW, "RIGHT");
  static constexpr KeyDef KEY_DEF_BACKSPACE = KeyDef(KEY_BACKSPACE, "BACKSPACE");
  static constexpr KeyDef KEY_DEF_TAB = KeyDef(KEY_TAB, "TAB");
  static constexpr KeyDef KEY_DEF_ENTER = KeyDef(KEY_RETURN, "ENTER");
  static constexpr KeyDef KEY_DEF_MENU = KeyDef(KEY_MENU, "MENU");
  static constexpr KeyDef KEY_DEF_APP = KeyDef(KEY_MENU, "APP"); // Extra
  static constexpr KeyDef KEY_DEF_ESC = KeyDef(KEY_ESC, "ESC");
  static constexpr KeyDef KEY_DEF_INSERT = KeyDef(KEY_INSERT, "INSERT");
  static constexpr KeyDef KEY_DEF_DELETE = KeyDef(KEY_DELETE, "DELETE");
  static constexpr KeyDef KEY_DEF_PAGE_UP = KeyDef(KEY_PAGE_UP, "PAGEUP");
  static constexpr KeyDef KEY_DEF_PAGE_DOWN = KeyDef(KEY_PAGE_DOWN, "PAGEDOWN");
  static constexpr KeyDef KEY_DEF_HOME = KeyDef(KEY_HOME, "HOME");
  static constexpr KeyDef KEY_DEF_END = KeyDef(KEY_END, "END");
  static constexpr KeyDef KEY_DEF_CAPS_LOCK = KeyDef(KEY_CAPS_LOCK, "CAPSLOCK");
  static constexpr KeyDef KEY_DEF_PRINT_SCREEN = KeyDef(KEY_PRINT_SCREEN, "PRINT");
  static constexpr KeyDef KEY_DEF_SCROLL_LOCK = KeyDef(KEY_SCROLL_LOCK, "SCROLLLOCK");
  static constexpr KeyDef KEY_DEF_PAUSE = KeyDef(KEY_PAUSE, "PAUSE");
  static constexpr KeyDef KEY_DEF_BREAK = KeyDef(KEY_PAUSE, "BREAK");

  // Numeric keypad
  static constexpr KeyDef KEY_DEF_NUM_LOCK = KeyDef(KEY_NUM_LOCK, "NUMLOCK");
  static constexpr KeyDef KEY_DEF_KP_SLASH = KeyDef(KEY_KP_SLASH, "KP_SLASH");
  static constexpr KeyDef KEY_DEF_KP_ASTERISK = KeyDef(KEY_KP_ASTERISK, "KP_ASTERISK");
  static constexpr KeyDef KEY_DEF_KP_MINUS = KeyDef(KEY_KP_MINUS, "KP_MINUS");
  static constexpr KeyDef KEY_DEF_KP_PLUS = KeyDef(KEY_KP_PLUS, "KP_PLUS");
  static constexpr KeyDef KEY_DEF_KP_ENTER = KeyDef(KEY_KP_ENTER, "KP_ENTER");
  static constexpr KeyDef KEY_DEF_KP_1 = KeyDef(KEY_KP_1, "KP_1");
  static constexpr KeyDef KEY_DEF_KP_2 = KeyDef(KEY_KP_2, "KP_2");
  static constexpr KeyDef KEY_DEF_KP_3 = KeyDef(KEY_KP_3, "KP_3");
  static constexpr KeyDef KEY_DEF_KP_4 = KeyDef(KEY_KP_4, "KP_4");
  static constexpr KeyDef KEY_DEF_KP_5 = KeyDef(KEY_KP_5, "KP_5");
  static constexpr KeyDef KEY_DEF_KP_6 = KeyDef(KEY_KP_6, "KP_6");
  static constexpr KeyDef KEY_DEF_KP_7 = KeyDef(KEY_KP_7, "KP_7");
  static constexpr KeyDef KEY_DEF_KP_8 = KeyDef(KEY_KP_8, "KP_8");
  static constexpr KeyDef KEY_DEF_KP_9 = KeyDef(KEY_KP_9, "KP_9");
  static constexpr KeyDef KEY_DEF_KP_0 = KeyDef(KEY_KP_0, "KP_0");
  static constexpr KeyDef KEY_DEF_KP_DOT = KeyDef(KEY_KP_DOT, "KP_DOT");

  // Function keys
  static constexpr KeyDef KEY_DEF_F1 = KeyDef(KEY_F1, "F1");
  static constexpr KeyDef KEY_DEF_F2 = KeyDef(KEY_F2, "F2");
  static constexpr KeyDef KEY_DEF_F3 = KeyDef(KEY_F3, "F3");
  static constexpr KeyDef KEY_DEF_F4 = KeyDef(KEY_F4, "F4");
  static constexpr KeyDef KEY_DEF_F5 = KeyDef(KEY_F5, "F5");
  static constexpr KeyDef KEY_DEF_F6 = KeyDef(KEY_F6, "F6");
  static constexpr KeyDef KEY_DEF_F7 = KeyDef(KEY_F7, "F7");
  static constexpr KeyDef KEY_DEF_F8 = KeyDef(KEY_F8, "F8");
  static constexpr KeyDef KEY_DEF_F9 = KeyDef(KEY_F9, "F9");
  static constexpr KeyDef KEY_DEF_F10 = KeyDef(KEY_F10, "F10");
  static constexpr KeyDef KEY_DEF_F11 = KeyDef(KEY_F11, "F11");
  static constexpr KeyDef KEY_DEF_F12 = KeyDef(KEY_F12, "F12");
  static constexpr KeyDef KEY_DEF_F13 = KeyDef(KEY_F13, "F13");
  static constexpr KeyDef KEY_DEF_F14 = KeyDef(KEY_F14, "F14");
  static constexpr KeyDef KEY_DEF_F15 = KeyDef(KEY_F15, "F15");
  static constexpr KeyDef KEY_DEF_F16 = KeyDef(KEY_F16, "F16");
  static constexpr KeyDef KEY_DEF_F17 = KeyDef(KEY_F17, "F17");
  static constexpr KeyDef KEY_DEF_F18 = KeyDef(KEY_F18, "F18");
  static constexpr KeyDef KEY_DEF_F19 = KeyDef(KEY_F19, "F19");
  static constexpr KeyDef KEY_DEF_F20 = KeyDef(KEY_F20, "F20");
  static constexpr KeyDef KEY_DEF_F21 = KeyDef(KEY_F21, "F21");
  static constexpr KeyDef KEY_DEF_F22 = KeyDef(KEY_F22, "F22");
  static constexpr KeyDef KEY_DEF_F23 = KeyDef(KEY_F23, "F23");
  static constexpr KeyDef KEY_DEF_F24 = KeyDef(KEY_F24, "F24");
}
