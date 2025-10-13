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
// File: status_bar.hpp
// ---------------------------------------------------------------------------

#ifndef LIBGUI_STATUS_BAR_HPP_
#define LIBGUI_STATUS_BAR_HPP_

#include <libgui/widget.hpp>
#include <libgui/color.hpp>

#include <vector>

namespace UI {

class StatusBar : public Widget {
public:
    StatusBar();

    void AddColor(const Color& color);
    void DeleteColor(const size_t index);

    void SetText(std::string_view text);
    void SetText(std::string_view text, const size_t color_index, const bool animate = false);
    void SetColor(const size_t color_index, const bool animate = false);

private:
    GtkStatusbar* m_bar;

    std::vector<Color> m_colors;
    size_t m_active_color;
};

} // namespace UI

#endif // LIBGUI_STATUS_BAR_HPP_
