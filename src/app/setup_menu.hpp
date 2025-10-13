// ---------------------------------------------------------------------------
//   Copyright 2025 Carlos Gurgel
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
// ---------------------------------------------------------------------------
// File: setup_menu.hpp
// ---------------------------------------------------------------------------

#ifndef APP_SETUP_MENU_HPP_
#define APP_SETUP_MENU_HPP_

#include <base/types.hpp>

namespace UI {
    class MenuBar;
} // namespace UI

// IDs used when handling menu item commands
struct MenuId {
    enum Options : s32 {
        // File
        kSessionNew = 0,
        kSessionOpen,
        kSessionRecentExec1,
        kSessionRecentExec2,
        kSessionRecentExec3,
        kSessionRecentExec4,
        kSessionRecentExec5,
        kSessionRecentSession1,
        kSessionRecentSession2,
        kSessionRecentSession3,
        kSessionRecentSession4,
        kSessionRecentSession5,
        kSessionSettings,
        kSessionExit,

        // View
        kViewAppearanceFullScreen,
        kViewBreakpoints,
        kViewDisassembly,
        kViewMemory,
        kViewLogConsole,
        kViewRegisters,
        kViewWatch,

        // Debug
        kDebugRun,
        kDebugRunWithoutDebugging,
        kDebugContinue,
        kDebugBreak,
        kDebugRestart,
        kDebugStepOver,
        kDebugStepIn,
        kDebugStepOut,
        kDebugToggleBreakpoint,
        kDebugNewBptFunc,
        kDebugNewBptAddr,
        kDebugDeleteAllBrkpts,
        kDebugExportDump,

        // Help
        kHelpDebuggerManual,
        kHelpR5900Manual,
        kHelpAbout,
    };
};

using MenuOpt = MenuId::Options;

void SetupSessionMenu(UI::MenuBar& bar);
void SetupViewMenu(UI::MenuBar& bar);
void SetupDebugMenu(UI::MenuBar& bar);
void SetupHelpMenu(UI::MenuBar& bar);

#endif // APP_SETUP_MENU_HPP_
