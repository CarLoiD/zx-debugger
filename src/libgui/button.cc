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
}

Button::Button(std::string_view label, const bool use_mnemonics)
    : Button() 
{
    SetLabel(label, use_mnemonics);
}

void Button::SetLabel(std::string_view label, const bool use_mnemonics) {
    gtk_button_set_use_underline(m_btn, use_mnemonics);
    gtk_button_set_label(m_btn, label.data());
}

std::string_view Button::GetLabel() const {
    return std::string_view(gtk_button_get_label(m_btn));
}

} // namespace UI
