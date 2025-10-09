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
// File: header_bar.cc
// ---------------------------------------------------------------------------

#include "header_bar.hpp"
#include "base/assert.hpp"

namespace UI {

HeaderBar::HeaderBar() {
    m_handle = gtk_header_bar_new();
    g_object_ref_sink(m_handle);

    m_header_bar = GTK_HEADER_BAR(m_handle);

    // Default behavior is to have a functional close button on the header bar
    // Also without vertical margins
    SetShowCloseButton(true);
    SetMarginY(0);
}

HeaderBar::~HeaderBar() {}

void HeaderBar::SetShowCloseButton(const bool show) {
    ASSERT_PTR(m_header_bar);
    gtk_header_bar_set_show_close_button(m_header_bar, show);
}

void HeaderBar::SetTitle(std::string_view title) {
    ASSERT_PTR(m_header_bar);
    gtk_header_bar_set_title(m_header_bar, title.data());
}

void HeaderBar::Add(Widget& child) {
    ASSERT_PTR(m_header_bar);
    ASSERT_PTR(child.GetHandle());

    gtk_header_bar_pack_start(m_header_bar, child.GetHandle());
}

} // namespace UI
