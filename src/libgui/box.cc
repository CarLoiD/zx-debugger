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
// File: box.cc
// ---------------------------------------------------------------------------

#include "box.hpp"

namespace UI {

Box::Box(const BoxOrientation& orientation) 
    : Widget(gtk_box_new(static_cast<GtkOrientation>(orientation), 0))
{
    m_box = GTK_BOX(m_handle);
    m_expand = false;
    m_fill = false;
}

void Box::SetOpt(const bool expand, const bool fill) {
    m_expand = expand;
    m_fill = fill;
}

void Box::SetSpacing(s32 spacing) {
    gtk_box_set_spacing(m_box, spacing);
}

void Box::Add(Widget& child) {
    gtk_box_pack_start(m_box, child.GetHandle(), m_expand, m_fill, 0);
    SetOpt(false, false);
}

} // namespace UI
