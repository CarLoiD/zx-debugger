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
// File: window.cc
// ---------------------------------------------------------------------------

#include "window.hpp"
#include "application.hpp"
#include "header_bar.hpp"
#include "base/assert.hpp"

namespace UI {

Window::Window() {
    GtkApplication* app = Application::GetDefault();
    ASSERT_PTR(app);

    m_handle = gtk_application_window_new(app);
    g_object_ref_sink(m_handle);

    m_wnd = GTK_WINDOW(m_handle);
    Resize(300, 200);
}

Window::~Window() {}

void Window::SetHeaderBar(HeaderBar& bar) {
    ASSERT_PTR(m_wnd);
    gtk_window_set_titlebar(m_wnd, bar.GetHandle());
}

void Window::SetTitle(std::string_view new_title) {
    ASSERT_PTR(m_wnd);
    gtk_window_set_title(m_wnd, new_title.data());
}

void Window::Resize(int new_width, int new_height) {
    ASSERT_PTR(m_wnd);
    gtk_window_set_default_size(m_wnd, new_width, new_height);
}

void Window::Close() {
    ASSERT_PTR(m_wnd);
    gtk_window_close(m_wnd);
}

void Window::Add(Widget& child) {
    ASSERT_PTR(m_handle);
    ASSERT_PTR(child.GetHandle());

    gtk_container_add(GTK_CONTAINER(m_handle), child.GetHandle());
}

} // namespace UI
