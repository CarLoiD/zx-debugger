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
        kFileNew = 0,
        kFileOpen,
        kFileRecentExec1,
        kFileRecentExec2,
        kFileRecentExec3,
        kFileRecentExec4,
        kFileRecentExec5,
        kFileRecentSession1,
        kFileRecentSession2,
        kFileRecentSession3,
        kFileRecentSession4,
        kFileRecentSession5,
        kFileExit,

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
        case MenuOpt::kFileNew:
        break;

        case MenuOpt::kFileOpen:
        break;

        case MenuOpt::kFileRecentExec1:
        case MenuOpt::kFileRecentExec2:
        case MenuOpt::kFileRecentExec3:
        case MenuOpt::kFileRecentExec4:
        case MenuOpt::kFileRecentExec5:
        break;
        
        case MenuOpt::kFileRecentSession1:
        case MenuOpt::kFileRecentSession2:
        case MenuOpt::kFileRecentSession3:
        case MenuOpt::kFileRecentSession4:
        case MenuOpt::kFileRecentSession5:
        break;

        case MenuOpt::kFileExit:
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
        m_mb.AppendItem("_New...", MenuOpt::kFileNew, { kCtrlKey, GDK_KEY_n });
        m_mb.AppendItem("_Open...", MenuOpt::kFileOpen, { kCtrlKey, GDK_KEY_o });
        
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
        
        m_mb.AppendItem("E_xit", MenuOpt::kFileExit, { kAltKey, GDK_KEY_F4 });
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

    UI::Image app_icon("icon.png");
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
            color: #cccccc;
        }
    )");
    
    // Blend the background colors of content area and header bar
    const auto wnd_style = "window { background-color: #222222; color: white; }";
    UI::Widget::GlobalEvalCSS(wnd_style); 

    // Set menus styles
    UI::Widget::GlobalEvalCSS(R"(
        menubar, menu, menu popup, menuitem {
            box-shadow: none;
            border: none;
        }

        menu {
            padding-top: 4px;
            padding-bottom: 4px;
        }

        menuitem {
            padding-left: 8px;
            padding-right: 8px;
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
    Widget sb(gtk_statusbar_new());
    sb.SetMargin(0);
    sb.LocalEvalCSS("statusbar { background: #007acc; color: white; }");
    sb.LocalEvalCSS("statusbar { padding-left: 8px; }");

    int ctx = gtk_statusbar_get_context_id(GTK_STATUSBAR(sb.GetHandle()), "main");
    gtk_statusbar_pop(GTK_STATUSBAR(sb.GetHandle()), ctx);
    gtk_statusbar_push(GTK_STATUSBAR(sb.GetHandle()), ctx, "Ready");

    m_vbox.Add(sb);
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
