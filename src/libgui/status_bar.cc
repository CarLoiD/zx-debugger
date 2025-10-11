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
// File: status_bar.cc
// ---------------------------------------------------------------------------

#include "status_bar.hpp"
#include "base/assert.hpp"
#include <cstdio>

namespace UI {

StatusBar::StatusBar()
    : Widget(gtk_statusbar_new())
    , m_active_color(-1)
{
    m_bar = GTK_STATUSBAR(m_handle);
    SetMargin(0); // Somehow by default it has some margins, cut that
    LocalEvalCSS("statusbar { padding-left: 8px; color: white }");
}

void StatusBar::AddColor(const Color& color) {
    m_colors.push_back(color);
}

void StatusBar::DeleteColor(const size_t index) {
    //Color* at = m_colors.begin() + index;

    //ASSERT_PTR(at);
    //m_colors.erase(at);
}

void StatusBar::SetText(std::string_view text) {
    const int ctx = gtk_statusbar_get_context_id(m_bar, "main");
    gtk_statusbar_pop(m_bar, ctx);
    gtk_statusbar_push(m_bar, ctx, text.data());
}

void StatusBar::SetText(std::string_view text, const size_t color_index, const bool animate) {
    SetText(text);
    SetColor(color_index, animate);
}

void StatusBar::SetColor(const size_t color_index, const bool animate) {
    ASSERT(color_index < m_colors.size(), "Color index out of bounds");

    if (!animate) {
        const Color at = m_colors.at(color_index);
        char buffer[64];
        snprintf(buffer, 64, "statusbar { background: rgb(%d, %d, %d); }",
                 static_cast<int>(at.r),
                 static_cast<int>(at.g),
                 static_cast<int>(at.b));
        
        m_active_color = color_index;
        LocalEvalCSS(buffer);
    }
}

} // namespace UI
