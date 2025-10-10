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
// File: box.hpp
// ---------------------------------------------------------------------------

#ifndef LIBGUI_BOX_HPP_
#define LIBGUI_BOX_HPP_

#include "widget.hpp"

namespace UI {

enum class BoxOrientation {
    kHorizontal,
    kVertical,
};

class Box : public Widget {
public:
    Box() = delete;
    Box(const BoxOrientation& orientation);

    void SetOpt(const bool expand, const bool fill);
    void SetSpacing(s32 spacing);
    void Add(Widget& child) override;

private:
    GtkBox* m_box;

    bool m_expand;
    bool m_fill;
};

class HBox : public Box {
public:
    HBox() : Box(BoxOrientation::kHorizontal) {}
};

class VBox : public Box {
public:
    VBox() : Box(BoxOrientation::kVertical) {}
};

} // namespace UI

#endif // LIBGUI_BOX_HPP_
