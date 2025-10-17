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
// File: notebook.cc
// ---------------------------------------------------------------------------

#include "notebook.hpp"

#include <libgui/box.hpp>
#include <libgui/button.hpp>
#include <libgui/label.hpp>

namespace UI {

Notebook::Notebook()
    : Widget(gtk_notebook_new())
{
    m_notebook = GTK_NOTEBOOK(m_handle);

    //SetExpand(true, true); // Making sure notebook expands itself
    ShowTabs();
}

void Notebook::AddTab(Widget& child, std::string_view title) {
    Label text(title);

    Button close;
    close.SetIcon("window-close-symbolic");
    gtk_widget_set_tooltip_text(close.GetHandle(), "Close Tab");

    HBox box;
    box.SetOpt(true, true);
    box.Add(text);
    box.Add(close);

    box.ShowAll();

    gtk_notebook_append_page(
        m_notebook, 
        child.GetHandle(),
        box.GetHandle());
}

void Notebook::HideTabs() {
    gtk_notebook_set_show_tabs(m_notebook, false);
}

void Notebook::ShowTabs() {
    gtk_notebook_set_show_tabs(m_notebook, true);
}

} // namespace UI
