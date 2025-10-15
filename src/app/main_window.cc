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
#include "setup_menu.hpp"

constexpr u32 kInitWidth = 1280;
constexpr u32 kInitHeight = 720;

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
    // Setup menu bar and it's actions
    m_mb.SetOnCommandCallback(this, &MainWindow::OnMenuCommand);

    SetupSessionMenu(m_mb);
    SetupViewMenu(m_mb);
    SetupDebugMenu(m_mb);
    SetupHelpMenu(m_mb);
}

void MainWindow::SetupHeaderBar() {
    UI::HeaderBar header;
    header.SetTitle("zx-debugger"); // Default title while no session is loaded

    UI::Image app_icon("res/icon/app.png");
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
            margin-left: 30px;
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
