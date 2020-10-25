#pragma once
#include <string>
#include <Siv3D/Key.hpp>

namespace dx {
namespace di {

enum class KeyState : int {
    Down, Pressed, Up
};

inline bool isState(const s3d::Key& key, KeyState state) {
    switch (state) {
    case KeyState::Down   : return key.down();
    case KeyState::Pressed: return key.pressed();
    case KeyState::Up     : return key.up();
    }
}


enum class KeyCode : int {
    None,
    Cancel,
    Backspace,
    Tab,
    Clear,
    Enter,
    Shift,
    Control,
    Alt,
    Pause,
    Escape,
    Space,
    PageUp,
    PageDown,
    End,
    Home,
    Left,
    Up,
    Right,
    Down,
    PrintScreen,
    Insert,
    Delete,
    _0, _1, _2, _3, _4, _5, _6, _7, _8, _9,
    A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
    NumMultiply, NumAdd, NumEnter, NumSubtract, NumDecimal, NumDivide,
    F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24,
    NumLock,
    LShift,
    RShift,
    LControl,
    RControl,
    LAlt,
    RAlt,
    NextTrack,
    PreviousTrack,
    StopMedia,
    PlayPauseMedia,
    Colon_JIS,
    Semicolon_US,
    Semicolon_JIS,
    Equal_US,
    Comma,
    Minus,
    Period,
    Slash,
    GraveAccent,
    Command,
    LeftCommand,
    RightCommand,
    LBracket,
    Yen_JIS,
    Backslash_US,
    RBracket,
    Caret_JIS,
    Apostrophe_US,
    Underscore_JIS,
};

KeyCode keyFromString(const std::string& str);
s3d::Key keyFromCode(KeyCode code);

}
}

