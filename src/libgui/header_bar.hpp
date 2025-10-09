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
// File: header_bar.hpp
// ---------------------------------------------------------------------------

#ifndef LIBGUI_HEADER_BAR_HPP_
#define LIBGUI_HEADER_BAR_HPP_

#include "widget.hpp"

namespace UI {

class HeaderBar : public Widget {
public:
    HeaderBar();
    ~HeaderBar();

    void SetShowCloseButton(const bool show);
    void SetTitle(std::string_view title);

    void Add(Widget& child) override;

private:
    GtkHeaderBar* m_header_bar;
};

} // namespace UI

#endif // LIBGUI_HEADER_BAR_HPP_
