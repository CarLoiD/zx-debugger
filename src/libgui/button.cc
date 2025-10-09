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
#include "base/assert.hpp"

namespace UI {

Button::Button() {
    m_handle = gtk_button_new();

    g_object_ref_sink(m_handle);
    m_btn = GTK_BUTTON(m_handle);
}

Button::Button(std::string_view label, const bool use_mnemonics) {
    if (use_mnemonics) {
        m_handle = gtk_button_new_with_mnemonic(label.data());
    } else {
        m_handle = gtk_button_new_with_label(label.data());
    }

    g_object_ref_sink(m_handle);
    m_btn = GTK_BUTTON(m_handle);
}

void Button::SetLabel(std::string_view label, const bool use_mnemonics) {
    ASSERT_PTR(m_btn);

    gtk_button_set_use_underline(m_btn, use_mnemonics);
    gtk_button_set_label(m_btn, label.data());
}

std::string_view Button::GetLabel() const {
    ASSERT_PTR(m_btn);
    return std::string_view(gtk_button_get_label(m_btn));
}

} // namespace UI
