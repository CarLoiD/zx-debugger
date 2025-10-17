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
// File: button.cc
// ---------------------------------------------------------------------------

#include "button.hpp"

namespace UI {

Button::Button()
    : Widget(gtk_button_new())
{
    m_btn = GTK_BUTTON(m_handle);
    m_clickable_widget = m_handle; // Better cost than virtual function call on every SetOnClick...
}

Button::Button(std::string_view text, const bool use_mnemonics)
    : Button() 
{
    SetText(text, use_mnemonics);
}

void Button::SetText(std::string_view text, const bool use_mnemonics) {
    gtk_button_set_use_underline(m_btn, use_mnemonics);
    gtk_button_set_label(m_btn, text.data());
}

std::string_view Button::GetText() const {
    return std::string_view(gtk_button_get_label(m_btn));
}

void Button::SetIcon(std::string_view icon_name) {
    SetText("");

    m_icon.SetFromIconName(icon_name, IconSize::kMenu);
    gtk_button_set_image(m_btn, m_icon.GetHandle());
    gtk_button_set_relief(m_btn, GTK_RELIEF_NONE);

    gtk_widget_set_can_focus(m_handle, false);
    gtk_widget_set_focus_on_click(m_handle, false);

    gtk_widget_show(m_icon.GetHandle());
}

} // namespace UI
