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
// File: menu_bar.hpp
// ---------------------------------------------------------------------------

#ifndef LIBGUI_MENU_BAR_HPP_
#define LIBGUI_MENU_BAR_HPP_

#include <functional>
#include <vector>

#include "widget.hpp"

namespace UI {

class Window;

class MenuBar : public Widget {
public:
    struct AccelKey {
        u32 mods;
        u32 key;

        AccelKey();
        AccelKey(u32 key);
        AccelKey(u32 mods, u32 key);

        // Implicit conversion operator to check if properly initialized
        operator bool() const;
    };

private:
    // Used to navigate through submenu data in a linear way
    struct SubmenuHolder {
        GtkWidget* instances;
        std::string_view labels;
    };

    // Represents current context in the submenu stack
    struct SubmenuContext {
        GtkWidget* menu_item;
        GtkWidget* menu;
    };

public:
    MenuBar();

    void RegisterAccelGroup(Window& window);

    void PushSubmenu(std::string_view label);
    void PopSubmenu();

    // Instead of manually assigning callbacks for each submenu item,
    // Each submenu will have it's ID, with only a single callback bound via
    // SetOnCommandCallback(), each submenu has it's activate signal set so
    // that it calls the command callback with the item id, if valid.
    void AppendItem(std::string_view label, const s32 id = -1, const AccelKey& keybind = {});
    void AppendSeparator();

    template <typename Callable>
    void SetOnCommandCallback(Callable&& cb) {
        m_cb = std::forward<Callable>(cb);
    }

    template <typename T>
    void SetOnCommandCallback(T* instance, void (T::*method)(s32)) {
        m_cb = [instance, method](s32 id) {
            (instance->*method)(id);
        };
    }

    Widget& operator[](const size_t index); 

private:
    GtkMenuBar* m_mb;

    bool m_registered_accel;
    GtkAccelGroup* m_accel_group;

    std::vector<SubmenuHolder> m_holder;
    std::vector<SubmenuContext> m_stack;

    std::function<void(s32)> m_cb;
};

} // namespace UI

#endif // LIBGUI_MENU_BAR_HPP_
