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

void MainWindow::SetupHeaderBar() {
    UI::HeaderBar header;
    header.SetTitle("zx-debugger");

    GtkWidget* icon = gtk_image_new_from_file("icon.png");
    gtk_widget_set_size_request(icon, 24, 24);

    Widget box(icon);
    box.SetMargin(UI::MarginOpt::kStart, 8);

    header.Add(box);
    
    SetHeaderBar(header);
}

MainWindow::MainWindow() {
    Resize(kInitWidth, kInitHeight);
    SetupHeaderBar();
}
