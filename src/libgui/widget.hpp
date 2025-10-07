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
// File: widget.hpp
// ---------------------------------------------------------------------------

#ifndef CLIENT_UI_WIDGET_HPP_
#define CLIENT_UI_WIDGET_HPP_

#include <gtk/gtk.h> 
#include "color.hpp"

namespace UI {

class Widget {
public:
    struct MarginMask {
        enum Options : uint32_t {
            kStart      = (1 << 0),
            kEnd        = (1 << 1),
            kTop        = (1 << 2),
            kBottom     = (1 << 3),
        };
    };

protected:
    Widget() : m_handle(nullptr) {}

public:
    virtual ~Widget() = 0;
    
    void SetBackgroundColor(const Color& color);
    void SetMarginX(int offset);
    void SetMarginY(int offset);
    void SetMargin(const MarginMask::Options& mask, int offset);
    void SetMargin(int offset);
    void SetExpand(bool h_expand, bool v_expand);

    virtual void Add(Widget& child);

    GtkWidget* GetHandle() const { return m_handle; }

protected:
    GtkWidget* m_handle;
};

} // namespace UI

#endif // CLIENT_UI_WIDGET_HPP_
