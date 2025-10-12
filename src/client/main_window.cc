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
// File: main_window.cc
// ---------------------------------------------------------------------------

#include "main_window.hpp"

constexpr u32 kInitWidth = 1280;
constexpr u32 kInitHeight = 720;

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

void MainWindow::OnMenuCommand(s32 id) {
    MenuOpt opt = static_cast<MenuOpt>(id);
    switch (opt) {
        case MenuOpt::kSessionNew:
        break;

        case MenuOpt::kSessionOpen:
        break;

        case MenuOpt::kSessionRecentExec1:
        case MenuOpt::kSessionRecentExec2:
        case MenuOpt::kSessionRecentExec3:
        case MenuOpt::kSessionRecentExec4:
        case MenuOpt::kSessionRecentExec5:
        break;
        
        case MenuOpt::kSessionRecentSession1:
        case MenuOpt::kSessionRecentSession2:
        case MenuOpt::kSessionRecentSession3:
        case MenuOpt::kSessionRecentSession4:
        case MenuOpt::kSessionRecentSession5:
        break;

        case MenuOpt::kSessionExit:
            Close();
        break;

        default: break;
    }
}

void MainWindow::SetupMenuBar() {
    constexpr auto kCtrlKey   = GDK_CONTROL_MASK;
    constexpr auto kAltKey    = GDK_MOD1_MASK;
    constexpr auto kShiftKey  = GDK_SHIFT_MASK;
    constexpr auto kCtrlShiftKey = kCtrlKey | kShiftKey;
    constexpr auto kShiftAltKey  = kShiftKey | kAltKey;

    // Setup menu bar and it's actions
    m_mb.RegisterAccelGroup(*this);
    m_mb.SetOnCommandCallback(this, &MainWindow::OnMenuCommand);

    m_mb.PushSubmenu("_Session");
        m_mb.AppendItem("_New...", MenuOpt::kSessionNew, { kCtrlKey, GDK_KEY_n });
        m_mb.AppendItem("_Open...", MenuOpt::kSessionOpen, { kCtrlKey, GDK_KEY_o });
        
        m_mb.AppendSeparator();
        m_mb.PushSubmenu("Recent _Executables");
            // TODO: Implement MainWindow::FillRecentExecItems()
            m_mb.AppendItem(R"(_1 C:\projects\game\zx-debug.elf)");
            m_mb.AppendItem(R"(_2 C:\projects\zx-buster\zx-release.elf)");
        m_mb.PopSubmenu();
        m_mb.PushSubmenu("Recent Saved _Sessions");
            // TODO: Implement MainWindow::FillRecentSessionItems()
            m_mb.AppendItem(R"(_1 C:\projects\game\zx-debug.zds)");
        m_mb.PopSubmenu();

        m_mb.AppendSeparator();
        m_mb.AppendItem("Settin_gs...", MenuOpt::kSessionSettings);

        m_mb.AppendSeparator();
        m_mb.AppendItem("E_xit", MenuOpt::kSessionExit, { kAltKey, GDK_KEY_F4 });
    m_mb.PopSubmenu();
    
    // TODO: Edit submenu

    m_mb.PushSubmenu("_View");
        m_mb.PushSubmenu("Appearance");
            m_mb.AppendItem("_Full Screen", MenuOpt::kViewAppearanceFullScreen, { kShiftAltKey , GDK_KEY_Return });
        m_mb.PopSubmenu();

        m_mb.PushSubmenu("Layout");
            // TODO: Layout related functions
        m_mb.PopSubmenu();

        m_mb.AppendSeparator();
        m_mb.AppendItem("_Breakpoints", MenuOpt::kViewBreakpoints, { kCtrlShiftKey, GDK_KEY_b });
        m_mb.AppendItem("_Disassembly", MenuOpt::kViewDisassembly, { kCtrlShiftKey, GDK_KEY_d });
        m_mb.AppendItem("_Memory", MenuOpt::kViewMemory, { kCtrlShiftKey, GDK_KEY_m });
        m_mb.AppendItem("_Log Console", MenuOpt::kViewLogConsole, { kCtrlShiftKey, GDK_KEY_l });
        m_mb.AppendItem("_Registers", MenuOpt::kViewRegisters, { kCtrlShiftKey, GDK_KEY_r });
        m_mb.AppendItem("_Watch", MenuOpt::kViewWatch, { kCtrlShiftKey, GDK_KEY_w });
    m_mb.PopSubmenu();

    m_mb.PushSubmenu("_Debug");
        m_mb.AppendItem("Start _Debugging", MenuOpt::kDebugRun, { 0, GDK_KEY_F5 });
        m_mb.AppendItem("Start _Without Debugging", MenuOpt::kDebugRunWithoutDebugging, { kCtrlKey, GDK_KEY_F5 });

        m_mb.AppendSeparator();
        m_mb.AppendItem("_Continue", MenuOpt::kDebugContinue, { kShiftKey, GDK_KEY_F5 });
        m_mb.AppendItem("Brea_k", MenuOpt::kDebugBreak, { 0, GDK_KEY_Break });
        m_mb.AppendItem("_Restart", MenuOpt::kDebugRestart, { kCtrlShiftKey, GDK_KEY_F5 });

        m_mb.AppendSeparator();
        m_mb.AppendItem("_Step Over", MenuOpt::kDebugStepOver, { 0, GDK_KEY_F10 });
        m_mb.AppendItem("Step _In", MenuOpt::kDebugStepIn, { 0, GDK_KEY_F11 });
        m_mb.AppendItem("Step _Out", MenuOpt::kDebugStepOut, { kShiftKey, GDK_KEY_F11 });

        m_mb.AppendSeparator();
        m_mb.AppendItem("_Toggle Breakpoint", MenuOpt::kDebugToggleBreakpoint, { 0, GDK_KEY_F9 });
        m_mb.PushSubmenu("New Breakpoint");
            m_mb.AppendItem("At _Function...", MenuOpt::kDebugNewBptFunc);
            m_mb.AppendItem("At _Address...", MenuOpt::kDebugNewBptAddr);
        m_mb.PopSubmenu();
        m_mb.AppendItem("Delete _All Breakpoints", MenuOpt::kDebugDeleteAllBrkpts, { kCtrlShiftKey, GDK_KEY_F9 });

        m_mb.AppendSeparator();
        m_mb.AppendItem("E_xport Dump...", MenuOpt::kDebugExportDump);
    m_mb.PopSubmenu();

    m_mb.PushSubmenu("_Help");
        m_mb.AppendItem("User _Manual", MenuOpt::kHelpDebuggerManual, { kCtrlKey, GDK_KEY_F1 });
        
        m_mb.AppendSeparator();
        m_mb.AppendItem("_About", MenuOpt::kHelpAbout);
    m_mb.PopSubmenu();
}

void MainWindow::SetupHeaderBar() {
    UI::HeaderBar header;
    header.SetTitle("zx-debugger"); // Default title while no session is loaded

    UI::Image app_icon("res/icon.png");
    app_icon.SetMargin(UI::MarginOpt::kStart, 8);

    header.Add(app_icon);
    header.Add(m_mb);

    SetHeaderBar(header);
}

void MainWindow::SetupCustomStyle() {
    // Custom header bar styling for this application
    // Needed in order to remove padding from header bar
    // Normal widget SetMargin() won't cut for that...
    UI::Widget::GlobalEvalCSS(R"(
        headerbar {
            min-height: 32px;
            padding-top: 0px;
            padding-bottom: 0px;
            border: none;
            box-shadow: none;
            background: #222222;
            color: white;
        }

        headerbar:backdrop {
            background: #222222;
            color: white;
        }
    )");
    
    // Blend the background colors of content area and header bar
    const auto wnd_style = "window { background-color: #222222; color: white; }";
    UI::Widget::GlobalEvalCSS(wnd_style); 

    // Set menus styles
    UI::Widget::GlobalEvalCSS(R"(
        menubar, menu, menu popup, menuitem {
            box-shadow: none;
        }

        window.menu,
        window.menu.background,
        decoration {
            background: transparent;
            box-shadow: none;
            border: none;
        }

        menu {
            padding: 4px;
            border-radius: 6px;
            border: 1px solid #444; 
            background: #222;
        }

        separator {
            background: #444;
            padding-left: 0px;
            padding-right: 0px;
        }

        menuitem {
            padding-left: 8px;
            padding-right: 8px;
            border-radius: 6px;
        }
        
        /* Set the backdrop so that it doesn't glitch when out of focus */
        menuitem:backdrop {
            background: #222222;
            color: white;
            border-radius: 0px;
        }
    )");

    // Set default font family
    auto font_style = "* { font-family: 'Noto Sans'; font-size: 12.7px; }";
    UI::Widget::GlobalEvalCSS(font_style);
}

void MainWindow::SetupArea() {
    UI::Label placeholder("MAIN AREA (PLACEHOLDER)");
    placeholder.SetExpand(true, true);

    m_vbox.Add(placeholder);
}

void MainWindow::SetupStatusBar() {
    m_status.AddColor(UI::Color(0x007acc)); // Color 0 -> Normal Status
    m_status.AddColor(UI::Color(0xfa0000)); // Color 1 -> Error Status
    m_status.AddColor(UI::Color(0xff00ff)); // Color 2 -> Warning Status
    m_status.SetText("Ready", 0);

    m_vbox.Add(m_status);
}

MainWindow::MainWindow() {
    Resize(kInitWidth, kInitHeight);
    
    // Attach main vertical container
    Add(m_vbox);

    SetupMenuBar();
    SetupHeaderBar();
    SetupCustomStyle();
    SetupArea();
    SetupStatusBar();
}

bool MainWindow::Close() {
    // TODO: Implement ConfirmShutdownDialog
    return Window::Close();
}
