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
// File: menu_item.cc
// ---------------------------------------------------------------------------

#include "menu_item.hpp"

namespace UI {

MenuItem::MenuItem() 
    : Widget(gtk_menu_item_new())
{
    m_item = GTK_MENU_ITEM(m_handle);
    m_accel_item = m_handle;

    m_box.SetSpacing(8);
    gtk_container_add(GTK_CONTAINER(m_item), m_box.GetHandle());
    
    m_box.Add(m_icon);
    
    m_text.SetAlignX(0.0f); // Align left
    m_box.SetOpt(true, true);
    m_box.Add(m_text);

    m_accel_label.SetAlignX(1.0f); // Align right
    m_accel_label.SetAlignH(Align::kEnd);
    m_box.AddEnd(m_accel_label);

    // This is quite "hacky", but I don't pretend my libgui is meant to be
    // used by other people anyways XD...
    // By default GTK allocates some extra space for items like GtkImageMenuItem
    // or GtkCheckMenuItem, which doesn't map well to this API.
    // Since there isn't a default way of removing such extra space, this is the
    // current solution. It needs to be carefully checked against box spacing.
    // TODO: Find a more reliable way of doing aligned menu items
    LocalEvalCSS(R"(
        menuitem {
            padding-left: 0px;
            padding-right: 8px;
            margin-left: -18px;
            border-radius: 0px;
        }
    )");

    m_accel_label.SetTextColor(Color(0xAA, 0xAA, 0xAA));
    m_box.ShowAll();
}

MenuItem::MenuItem(std::string_view text) 
    : MenuItem()
{
    SetText(text);
}

MenuItem::MenuItem(std::string_view text, std::string_view keybind)
    : MenuItem()
{
    SetText(text);
    SetKeybind(keybind);
}

void MenuItem::SetIconFromName(std::string_view icon_name) {
    m_icon.SetFromIconName(icon_name, IconSize::kMenu);
}

void MenuItem::SetIconFromPath(std::string_view file_path) {
    m_icon.SetFromFile(file_path);
}

void MenuItem::SetText(std::string_view text) {
    m_text.SetText(text);
}

} // namespace UI
