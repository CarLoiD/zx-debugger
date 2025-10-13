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
// File: menu_bar.cc
// ---------------------------------------------------------------------------

#include "menu_bar.hpp"
#include "application.hpp"
#include "menu_item.hpp"
#include "window.hpp"
#include "base/assert.hpp"

namespace UI {

MenuBar::MenuBar()
    : Widget(gtk_menu_bar_new())
{
    m_cb = nullptr;
    m_mb = GTK_MENU_BAR(m_handle);
}

void MenuBar::PushSubmenu(std::string_view label) {
    // The normal C api can be confusing, but just to remember:
    // menu_item is the item on the top level menu bar
    // menu is the pop-up list that show up when menu_item is clicked
    GtkWidget* menu_item = gtk_menu_item_new_with_mnemonic(label.data());
    GtkWidget* menu = gtk_menu_new();

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
    m_stack.push_back({ menu_item, menu });
}

void MenuBar::PopSubmenu() {
    ASSERT(!m_stack.empty(), "Submenu stack underflow");
    
    auto submenu = m_stack.back();
    m_stack.pop_back();

    // Currently on top-level, add to the menu bar handle, else, nested submenu
    if (m_stack.empty()) {
        gtk_menu_shell_append(GTK_MENU_SHELL(m_mb), submenu.menu_item);
    } else {
        GtkWidget* gtk_submenu = m_stack.back().menu;
        gtk_menu_shell_append(GTK_MENU_SHELL(gtk_submenu), submenu.menu_item);
    }

    gtk_widget_show_all(submenu.menu_item);
}

void MenuBar::AppendItem(std::string_view label, const s32 id, const AccelKey& keybind) {
    ASSERT(!(id >= 0 && !m_cb), "Trying to append valid id without cmd callback");
    ASSERT(!m_stack.empty(), "Trying to append item to inactive submenu stack");

    // callback should be a pointer to a function of signature void (*)(s32)
    struct Data {
        s32 id;
        std::function<void(s32)> callback;
    };

    auto* udata = new Data;
    udata->id = id;
    udata->callback = m_cb;

    GtkWidget* item = gtk_menu_item_new_with_mnemonic(label.data());

    if (keybind) {
        gtk_widget_add_accelerator(
            item,
            "activate",
            Application::GetAccelGroup(),
            keybind.key,
            static_cast<GdkModifierType>(keybind.mods),
            GTK_ACCEL_VISIBLE);
    }

    g_signal_connect_data(
        item,
        "activate",
        G_CALLBACK(+[](GtkMenuItem*, gpointer user_data) {
            auto* data = static_cast<Data*>(user_data);
            if (data->callback && data->id >= 0) {
                data->callback(data->id);
            }
        }),
        udata,
        [](gpointer data, GClosure*) { delete static_cast<Data*>(data); },
        static_cast<GConnectFlags>(0));

    gtk_menu_shell_append(GTK_MENU_SHELL(m_stack.back().menu), item);
    gtk_widget_show(item);
}

void MenuBar::AppendSeparator() {
    ASSERT(!m_stack.empty(), "Trying to append item to inactive submenu stack");

    GtkWidget* item = gtk_separator_menu_item_new();
    gtk_menu_shell_append(GTK_MENU_SHELL(m_stack.back().menu), item);
    gtk_widget_show(item);
}

} // namespace UI
