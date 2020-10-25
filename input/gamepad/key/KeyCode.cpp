#include "KeyCode.hpp"
#include <unordered_map>
#include <Siv3D/Keyboard.hpp>
#include <Siv3D/JoyCon.hpp>

namespace dx {
namespace di {

KeyCode keyFromString(const std::string& str) {
    static std::unordered_map<std::string, KeyCode> map {
        { "Cancel"     , KeyCode::Cancel      },
        { "Backspace"  , KeyCode::Backspace   },
        { "Tab"        , KeyCode::Tab         },
        { "Clear"      , KeyCode::Clear       },
        { "Enter"      , KeyCode::Enter       },
        { "Shift"      , KeyCode::Shift       },
        { "Control"    , KeyCode::Control     },
        { "Alt"        , KeyCode::Alt         },
        { "Pause"      , KeyCode::Pause       },
        { "Escape"     , KeyCode::Escape      },
        { "Space"      , KeyCode::Space       },
        { "PageUp"     , KeyCode::PageUp      },
        { "PageDown"   , KeyCode::PageDown    },
        { "End"        , KeyCode::End         },
        { "Home"       , KeyCode::Home        },
        { "Left"       , KeyCode::Left        },
        { "Up"         , KeyCode::Up          },
        { "Right"      , KeyCode::Right       },
        { "Down"       , KeyCode::Down        },
        { "PrintScreen", KeyCode::PrintScreen },
        { "Insert"     , KeyCode::Insert      },
        { "Delete"     , KeyCode::Delete      },
        { "0", KeyCode::_0 },
        { "1", KeyCode::_1 },
        { "2", KeyCode::_2 },
        { "3", KeyCode::_3 },
        { "4", KeyCode::_4 },
        { "5", KeyCode::_5 },
        { "6", KeyCode::_6 },
        { "7", KeyCode::_7 },
        { "8", KeyCode::_8 },
        { "9", KeyCode::_9 },
        { "A", KeyCode::A },
        { "B", KeyCode::B },
        { "C", KeyCode::C },
        { "D", KeyCode::D },
        { "E", KeyCode::E },
        { "F", KeyCode::F },
        { "G", KeyCode::G },
        { "H", KeyCode::H },
        { "I", KeyCode::I },
        { "J", KeyCode::J },
        { "K", KeyCode::K },
        { "L", KeyCode::L },
        { "M", KeyCode::M },
        { "N", KeyCode::N },
        { "O", KeyCode::O },
        { "P", KeyCode::P },
        { "Q", KeyCode::Q },
        { "R", KeyCode::R },
        { "S", KeyCode::S },
        { "T", KeyCode::T },
        { "U", KeyCode::U },
        { "V", KeyCode::V },
        { "W", KeyCode::W },
        { "X", KeyCode::X },
        { "Y", KeyCode::Y },
        { "Z", KeyCode::Z },
        { "Num0", KeyCode::Num0 },
        { "Num1", KeyCode::Num1 },
        { "Num2", KeyCode::Num2 },
        { "Num3", KeyCode::Num3 },
        { "Num4", KeyCode::Num4 },
        { "Num5", KeyCode::Num5 },
        { "Num6", KeyCode::Num6 },
        { "Num7", KeyCode::Num7 },
        { "Num8", KeyCode::Num8 },
        { "Num9", KeyCode::Num9 },
        { "NumMultiply", KeyCode::NumMultiply },
        { "NumAdd"     , KeyCode::NumAdd      },
        { "NumEnter"   , KeyCode::NumEnter    },
        { "NumSubtract", KeyCode::NumSubtract },
        { "NumDecimal" , KeyCode::NumDecimal  },
        { "NumDivide"  , KeyCode::NumDivide   },
        { "F1", KeyCode::F1 },
        { "F2", KeyCode::F2 },
        { "F3", KeyCode::F3 },
        { "F4", KeyCode::F4 },
        { "F5", KeyCode::F5 },
        { "F6", KeyCode::F6 },
        { "F7", KeyCode::F7 },
        { "F8", KeyCode::F8 },
        { "F9", KeyCode::F9 },
        { "F10", KeyCode::F10 },
        { "F11", KeyCode::F11 },
        { "F12", KeyCode::F12 },
        { "F13", KeyCode::F13 },
        { "F14", KeyCode::F14 },
        { "F15", KeyCode::F15 },
        { "F16", KeyCode::F16 },
        { "F17", KeyCode::F17 },
        { "F18", KeyCode::F18 },
        { "F19", KeyCode::F19 },
        { "F20", KeyCode::F20 },
        { "F21", KeyCode::F21 },
        { "F22", KeyCode::F22 },
        { "F23", KeyCode::F23 },
        { "F24", KeyCode::F24 },
        { "NumLock"  , KeyCode::NumLock   },
        { "LShift"   , KeyCode::LShift    },
        { "RShift"   , KeyCode::RShift    },
        { "LControl" , KeyCode::LControl  },
        { "RControl" , KeyCode::RControl  },
        { "LAlt"     , KeyCode::LAlt      },
        { "RAlt"     , KeyCode::RAlt      },
        { "NextTrack", KeyCode::NextTrack },
        { "PreviousTrack" , KeyCode::PreviousTrack  },
        { "StopMedia"     , KeyCode::StopMedia      },
        { "PlayPauseMedia", KeyCode::PlayPauseMedia },
        { "Colon_JIS"     , KeyCode::Colon_JIS      },
        { "Semicolon_US"  , KeyCode::Semicolon_US   },
        { "Semicolon_JIS" , KeyCode::Semicolon_JIS  },
        { "Equal_US"      , KeyCode::Equal_US       },
        { "Comma"         , KeyCode::Comma          },
        { "Minus"         , KeyCode::Minus          },
        { "Period"        , KeyCode::Period         },
        { "Slash"         , KeyCode::Slash          },
        { "GraveAccent"   , KeyCode::GraveAccent    },
        { "Command"       , KeyCode::Command        },
        { "LeftCommand"   , KeyCode::LeftCommand    },
        { "RightCommand"  , KeyCode::RightCommand   },
        { "LBracket"      , KeyCode::LBracket       },
        { "Yen_JIS"       , KeyCode::Yen_JIS        },
        { "Backslash_US"  , KeyCode::Backslash_US   },
        { "RBracket"      , KeyCode::RBracket       },
        { "Caret_JIS"     , KeyCode::Caret_JIS      },
        { "Apostrophe_US" , KeyCode::Apostrophe_US  },
        { "Underscore_JIS", KeyCode::Underscore_JIS },
    };
    if (map.contains(str)) {
        return map.at(str);
    }
    else {
        return KeyCode::None;
    }
}

s3d::Key keyFromCode(KeyCode code) {
    using namespace s3d;
    switch (code) {
    case KeyCode::Cancel     : return KeyCancel     ;
    case KeyCode::Backspace  : return KeyBackspace  ;
    case KeyCode::Tab        : return KeyTab        ;
    case KeyCode::Clear      : return KeyClear      ;
    case KeyCode::Enter      : return KeyEnter      ;
    case KeyCode::Shift      : return KeyShift      ;
    case KeyCode::Control    : return KeyControl    ;
    case KeyCode::Alt        : return KeyAlt        ;
    case KeyCode::Pause      : return KeyPause      ;
    case KeyCode::Escape     : return KeyEscape     ;
    case KeyCode::Space      : return KeySpace      ;
    case KeyCode::PageUp     : return KeyPageUp     ;
    case KeyCode::PageDown   : return KeyPageDown   ;
    case KeyCode::End        : return KeyEnd        ;
    case KeyCode::Home       : return KeyHome       ;
    case KeyCode::Left       : return KeyLeft       ;
    case KeyCode::Up         : return KeyUp         ;
    case KeyCode::Right      : return KeyRight      ;
    case KeyCode::Down       : return KeyDown       ;
    case KeyCode::PrintScreen: return KeyPrintScreen;
    case KeyCode::Insert     : return KeyInsert     ;
    case KeyCode::Delete     : return KeyDelete     ;
    case KeyCode::_0: return Key0;
    case KeyCode::_1: return Key1;
    case KeyCode::_2: return Key2;
    case KeyCode::_3: return Key3;
    case KeyCode::_4: return Key4;
    case KeyCode::_5: return Key5;
    case KeyCode::_6: return Key6;
    case KeyCode::_7: return Key7;
    case KeyCode::_8: return Key8;
    case KeyCode::_9: return Key9;
    case KeyCode::A: return KeyA;
    case KeyCode::B: return KeyB;
    case KeyCode::C: return KeyC;
    case KeyCode::D: return KeyD;
    case KeyCode::E: return KeyE;
    case KeyCode::F: return KeyF;
    case KeyCode::G: return KeyG;
    case KeyCode::H: return KeyH;
    case KeyCode::I: return KeyI;
    case KeyCode::J: return KeyJ;
    case KeyCode::K: return KeyK;
    case KeyCode::L: return KeyL;
    case KeyCode::M: return KeyM;
    case KeyCode::N: return KeyN;
    case KeyCode::O: return KeyO;
    case KeyCode::P: return KeyP;
    case KeyCode::Q: return KeyQ;
    case KeyCode::R: return KeyR;
    case KeyCode::S: return KeyS;
    case KeyCode::T: return KeyT;
    case KeyCode::U: return KeyU;
    case KeyCode::V: return KeyV;
    case KeyCode::W: return KeyW;
    case KeyCode::X: return KeyX;
    case KeyCode::Y: return KeyY;
    case KeyCode::Z: return KeyZ;
    case KeyCode::Num0: return KeyNum0;
    case KeyCode::Num1: return KeyNum1;
    case KeyCode::Num2: return KeyNum2;
    case KeyCode::Num3: return KeyNum3;
    case KeyCode::Num4: return KeyNum4;
    case KeyCode::Num5: return KeyNum5;
    case KeyCode::Num6: return KeyNum6;
    case KeyCode::Num7: return KeyNum7;
    case KeyCode::Num8: return KeyNum8;
    case KeyCode::Num9: return KeyNum9;
    case KeyCode::NumMultiply: return KeyNumMultiply;
    case KeyCode::NumAdd     : return KeyNumAdd     ;
    case KeyCode::NumEnter   : return KeyNumEnter   ;
    case KeyCode::NumSubtract: return KeyNumSubtract;
    case KeyCode::NumDecimal : return KeyNumDecimal ;
    case KeyCode::NumDivide  : return KeyNumDivide  ;
    case KeyCode::F1: return KeyF1;
    case KeyCode::F2: return KeyF2;
    case KeyCode::F3: return KeyF3;
    case KeyCode::F4: return KeyF4;
    case KeyCode::F5: return KeyF5;
    case KeyCode::F6: return KeyF6;
    case KeyCode::F7: return KeyF7;
    case KeyCode::F8: return KeyF8;
    case KeyCode::F9: return KeyF9;
    case KeyCode::F10: return KeyF10;
    case KeyCode::F11: return KeyF11;
    case KeyCode::F12: return KeyF12;
    case KeyCode::F13: return KeyF13;
    case KeyCode::F14: return KeyF14;
    case KeyCode::F15: return KeyF15;
    case KeyCode::F16: return KeyF16;
    case KeyCode::F17: return KeyF17;
    case KeyCode::F18: return KeyF18;
    case KeyCode::F19: return KeyF19;
    case KeyCode::F20: return KeyF20;
    case KeyCode::F21: return KeyF21;
    case KeyCode::F22: return KeyF22;
    case KeyCode::F23: return KeyF23;
    case KeyCode::F24: return KeyF24;
    case KeyCode::NumLock  : return KeyNumLock  ;
    case KeyCode::LShift   : return KeyLShift   ;
    case KeyCode::RShift   : return KeyRShift   ;
    case KeyCode::LControl : return KeyLControl ;
    case KeyCode::RControl : return KeyRControl ;
    case KeyCode::LAlt     : return KeyLAlt     ;
    case KeyCode::RAlt     : return KeyRAlt     ;
    case KeyCode::NextTrack: return KeyNextTrack;
    case KeyCode::PreviousTrack : return KeyPreviousTrack ;
    case KeyCode::StopMedia     : return KeyStopMedia     ;
    case KeyCode::PlayPauseMedia: return KeyPlayPauseMedia;
    case KeyCode::Colon_JIS     : return KeyColon_JIS     ;
    case KeyCode::Semicolon_US  : return KeySemicolon_US  ;
    case KeyCode::Semicolon_JIS : return KeySemicolon_JIS ;
    case KeyCode::Equal_US      : return KeyEqual_US      ;
    case KeyCode::Comma         : return KeyComma         ;
    case KeyCode::Minus         : return KeyMinus         ;
    case KeyCode::Period        : return KeyPeriod        ;
    case KeyCode::Slash         : return KeySlash         ;
    case KeyCode::GraveAccent   : return KeyGraveAccent   ;
    case KeyCode::Command       : return KeyCommand       ;
    case KeyCode::LeftCommand   : return KeyLeftCommand   ;
    case KeyCode::RightCommand  : return KeyRightCommand  ;
    case KeyCode::LBracket      : return KeyLBracket      ;
    case KeyCode::Yen_JIS       : return KeyYen_JIS       ;
    case KeyCode::Backslash_US  : return KeyBackslash_US  ;
    case KeyCode::RBracket      : return KeyRBracket      ;
    case KeyCode::Caret_JIS     : return KeyCaret_JIS     ;
    case KeyCode::Apostrophe_US : return KeyApostrophe_US ;
    case KeyCode::Underscore_JIS: return KeyUnderscore_JIS;
    default: return KeyPrintScreen;
    }
}


KeyCodeOfJoyCon keyOfJoyConFromString(const std::string& str) {
    static std::unordered_map<std::string, KeyCodeOfJoyCon> map {
        { "A"         , KeyCodeOfJoyCon::A          },
        { "B"         , KeyCodeOfJoyCon::B          },
        { "X"         , KeyCodeOfJoyCon::X          },
        { "Y"         , KeyCodeOfJoyCon::Y          },
        { "Left"      , KeyCodeOfJoyCon::Left       },
        { "Right"     , KeyCodeOfJoyCon::Right      },
        { "Up"        , KeyCodeOfJoyCon::Up         },
        { "Down"      , KeyCodeOfJoyCon::Down       },
        { "L"         , KeyCodeOfJoyCon::L          },
        { "R"         , KeyCodeOfJoyCon::R          },
        { "ZL"        , KeyCodeOfJoyCon::ZL         },
        { "ZR"        , KeyCodeOfJoyCon::ZR         },
        { "SL"        , KeyCodeOfJoyCon::SL         },
        { "SR"        , KeyCodeOfJoyCon::SR         },
        { "Plus"      , KeyCodeOfJoyCon::Plus       },
        { "Minus"     , KeyCodeOfJoyCon::Minus      },
        { "Home"      , KeyCodeOfJoyCon::Home       },
        { "Screenshot", KeyCodeOfJoyCon::Screenshot },
    };
    if (map.contains(str)) {
        return map.at(str);
    }
    else {
        return KeyCodeOfJoyCon::None;
    }
}

s3d::Key keyFromCodeAtHorizontally(const s3d::JoyCon& joy, KeyCodeOfJoyCon code) {
    using namespace s3d;
    switch (code) {
    case KeyCodeOfJoyCon::A         : return joy.button1;
    case KeyCodeOfJoyCon::B         : return joy.button0;
    case KeyCodeOfJoyCon::X         : return joy.button3;
    case KeyCodeOfJoyCon::Y         : return joy.button2;
 // case KeyCodeOfJoyCon::Left      : return joy.button0;
 // case KeyCodeOfJoyCon::Right     : return joy.button0;
 // case KeyCodeOfJoyCon::Up        : return joy.button0;
 // case KeyCodeOfJoyCon::Down      : return joy.button0;
    case KeyCodeOfJoyCon::L         : return joy.buttonSL;
    case KeyCodeOfJoyCon::R         : return joy.buttonSR;
 // case KeyCodeOfJoyCon::ZL        : return joy.button0;
 // case KeyCodeOfJoyCon::ZR        : return joy.button0;
    case KeyCodeOfJoyCon::SL        : return joy.buttonSL;
    case KeyCodeOfJoyCon::SR        : return joy.buttonSR;
    case KeyCodeOfJoyCon::Plus      : return joy.buttonPlus;
    case KeyCodeOfJoyCon::Minus     : return joy.buttonMinus;
    case KeyCodeOfJoyCon::Home      : return joy.buttonHome;
    case KeyCodeOfJoyCon::Screenshot: return joy.buttonScreenshot;
    default                         : return KeyPrintScreen;
    }
}

s3d::Key keyFromCodeAtFrontally(const s3d::JoyCon& joy_l, const s3d::JoyCon& joy_r, KeyCodeOfJoyCon code) {
    using namespace s3d;
    switch (code) {
    case KeyCodeOfJoyCon::A         : return joy_r.button0;
    case KeyCodeOfJoyCon::B         : return joy_r.button2;
    case KeyCodeOfJoyCon::X         : return joy_r.button1;
    case KeyCodeOfJoyCon::Y         : return joy_r.button3;
    case KeyCodeOfJoyCon::Left      : return joy_l.button0;
    case KeyCodeOfJoyCon::Right     : return joy_l.button3;
    case KeyCodeOfJoyCon::Up        : return joy_l.button2;
    case KeyCodeOfJoyCon::Down      : return joy_l.button1;
    case KeyCodeOfJoyCon::L         : return joy_l.buttonLR;
    case KeyCodeOfJoyCon::R         : return joy_r.buttonLR;
    case KeyCodeOfJoyCon::ZL        : return joy_l.buttonZLZR;
    case KeyCodeOfJoyCon::ZR        : return joy_r.buttonZLZR;
 // case KeyCodeOfJoyCon::SL        : return joy_l.button0;
 // case KeyCodeOfJoyCon::SR        : return joy_r.button0;
    case KeyCodeOfJoyCon::Plus      : return joy_r.buttonPlus;
    case KeyCodeOfJoyCon::Minus     : return joy_l.buttonMinus;
    case KeyCodeOfJoyCon::Home      : return joy_r.buttonHome;
    case KeyCodeOfJoyCon::Screenshot: return joy_l.buttonScreenshot;
    default                         : return KeyPrintScreen;
    }
}

}
}

