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
// File: window.hpp
// ---------------------------------------------------------------------------

#ifndef LIBGUI_WINDOW_HPP_
#define LIBGUI_WINDOW_HPP_

#include "widget.hpp"

namespace UI {

class HeaderBar;

class Window : public Widget {
public:
    Window();

    // Used to customize the default header bar to contain menus, icons, entries etc.
    void SetHeaderBar(HeaderBar& bar);

    void SetTitle(std::string_view new_title);
    void Resize(int new_width, int new_height);
    virtual bool Close(); // Can overwrite the default behavior on close (e.g: confirm shutdown)

    // A GTK3 Window can have a single child widget bound on it's container
    void Add(Widget& child) override;

private:
    GtkWindow* m_wnd;
};

} // namespace UI

#endif // LIBGUI_WINDOW_HPP_
