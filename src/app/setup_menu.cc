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
// File: setup_menu.cc
// ---------------------------------------------------------------------------

#include "setup_menu.hpp"
#include <libgui/menu_bar.hpp>

// TODO: Edit submenu

void SetupSessionMenu(UI::MenuBar& bar) {
    UI::MenuItem session_new("_New...", "Ctrl+N");
    UI::MenuItem session_open("_Open...", "Ctrl+O");
    UI::MenuItem session_settings("Settin_gs...");
    UI::MenuItem session_exit("E_xit", "Alt+F4");

    bar.PushSubmenu("_Session");
        bar.AppendItem(session_new, MenuOpt::kSessionNew);
        bar.AppendItem(session_open, MenuOpt::kSessionOpen);
        
        bar.AppendSeparator();
        bar.PushSubmenu("Recent _Executables");
            // TODO: Implement MainWindow::FillRecentExecItems()
        bar.PopSubmenu();
        bar.PushSubmenu("Recent Saved _Sessions");
            // TODO: Implement MainWindow::FillRecentSessionItems()
        bar.PopSubmenu();

        bar.AppendSeparator();
        bar.AppendItem(session_settings, MenuOpt::kSessionSettings);

        bar.AppendSeparator();
        bar.AppendItem(session_exit, MenuOpt::kSessionExit);
    bar.PopSubmenu();
}

void SetupViewMenu(UI::MenuBar& bar) {
    UI::MenuItem view_fullscreen("_Full Screen", "Shift+Alt+Enter");
    UI::MenuItem view_breakpoints("_Breakpoints", "Ctrl+Shift+B");
    UI::MenuItem view_disassembly("_Disassembly", "Ctrl+Shift+D");
    UI::MenuItem view_memory("_Memory", "Ctrl+Shift+M");
    UI::MenuItem view_log_console("_Log Console", "Ctrl+Shift+L");
    UI::MenuItem view_registers("_Registers", "Ctrl+Shift+R");
    UI::MenuItem view_watch("_Watch", "Ctrl+Shift+W");

    bar.PushSubmenu("_View");
        bar.PushSubmenu("Appearance");
            bar.AppendItem(view_fullscreen, MenuOpt::kViewAppearanceFullScreen);
        bar.PopSubmenu();

        bar.PushSubmenu("Layout");
            // TODO: Layout related functions
        bar.PopSubmenu();

        bar.AppendSeparator();
        bar.AppendItem(view_breakpoints, MenuOpt::kViewBreakpoints);
        bar.AppendItem(view_disassembly, MenuOpt::kViewDisassembly);
        bar.AppendItem(view_memory, MenuOpt::kViewMemory);
        bar.AppendItem(view_log_console, MenuOpt::kViewLogConsole);
        bar.AppendItem(view_registers, MenuOpt::kViewRegisters);
        bar.AppendItem(view_watch, MenuOpt::kViewWatch);
    bar.PopSubmenu();
}

void SetupDebugMenu(UI::MenuBar& bar) {
    UI::MenuItem debug_start("Start _Debugging", "F5");

    bar.PushSubmenu("_Debug");
        bar.AppendItem("Start _Debugging", MenuOpt::kDebugRun, { 0, GDK_KEY_F5 });
        bar.AppendItem("Start _Without Debugging", MenuOpt::kDebugRunWithoutDebugging, { kCtrlKey, GDK_KEY_F5 });

        bar.AppendSeparator();
        bar.AppendItem("_Continue", MenuOpt::kDebugContinue, { kShiftKey, GDK_KEY_F5 });
        bar.AppendItem("Brea_k", MenuOpt::kDebugBreak, { 0, GDK_KEY_Break });
        bar.AppendItem("_Restart", MenuOpt::kDebugRestart, { kCtrlShiftKey, GDK_KEY_F5 });

        bar.AppendSeparator();
        bar.AppendItem("_Step Over", MenuOpt::kDebugStepOver, { 0, GDK_KEY_F10 });
        bar.AppendItem("Step _In", MenuOpt::kDebugStepIn, { 0, GDK_KEY_F11 });
        bar.AppendItem("Step _Out", MenuOpt::kDebugStepOut, { kShiftKey, GDK_KEY_F11 });

        bar.AppendSeparator();
        bar.AppendItem("_Toggle Breakpoint", MenuOpt::kDebugToggleBreakpoint, { 0, GDK_KEY_F9 });
        bar.PushSubmenu("New Breakpoint");
            bar.AppendItem("At _Function...", MenuOpt::kDebugNewBptFunc);
            bar.AppendItem("At _Address...", MenuOpt::kDebugNewBptAddr);
        bar.PopSubmenu();
        bar.AppendItem("Delete _All Breakpoints", MenuOpt::kDebugDeleteAllBrkpts, { kCtrlShiftKey, GDK_KEY_F9 });

        bar.AppendSeparator();
        bar.AppendItem("E_xport Dump...", MenuOpt::kDebugExportDump);
    bar.PopSubmenu();
}

void SetupHelpMenu(UI::MenuBar& bar) {
    UI::MenuItem help_user_manual("User _Manual", "Ctrl+F1");
    UI::MenuItem help_about("_About");

    bar.PushSubmenu("_Help");
        bar.AppendItem(help_user_manual, MenuOpt::kHelpDebuggerManual);
        
        bar.AppendSeparator();
        bar.AppendItem(help_about, MenuOpt::kHelpAbout);
    bar.PopSubmenu();
}

