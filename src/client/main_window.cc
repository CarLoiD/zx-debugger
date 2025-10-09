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

#include <iostream>

constexpr u32 kInitWidth = 1280;
constexpr u32 kInitHeight = 720;

void MainWindow::SetupHeaderBar() {
    UI::HeaderBar header;
    header.SetTitle("zx-debugger");
    
    UI::Image app_icon("icon.png");
    app_icon.SetMargin(UI::MarginOpt::kStart, 8);
   
    m_mb.SetOnCommandCallback(+[](s32 id){
        switch (id) {
            case 0:
            break;

            default: break;
        }
    });

    m_mb.PushSubmenu("_Session");
        m_mb.AppendItem("_New");
        m_mb.AppendItem("_Open");
        
        m_mb.AppendSeparator();
        m_mb.PushSubmenu("Recent _Executables");
            m_mb.AppendItem(R"(_1 C:\projects\game\zx-debug.elf)");
            m_mb.AppendItem(R"(_2 C:\projects\zx-buster\zx-release.elf)");
        m_mb.PopSubmenu();
        m_mb.AppendSeparator();
        
        m_mb.AppendItem("E_xit", 0);
    m_mb.PopSubmenu();

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
    )");

    // Set default font family
#if defined(__MINGW32__) || defined(_WIN32)
    auto font_style = "* { font-family: 'Segoe UI'; font-size: 14px; }";
#else
    auto font_style = "* { font-family: 'Noto Sans'; font-size: 14px; }";
#endif
    UI::Widget::GlobalEvalCSS(font_style);
}

MainWindow::MainWindow() {
    Resize(kInitWidth, kInitHeight);
    
    SetupHeaderBar();
    SetupCustomStyle();
}
