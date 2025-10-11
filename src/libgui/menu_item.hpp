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
// File: menu_item.hpp
// ---------------------------------------------------------------------------

#ifndef LIBGUI_MENU_ITEM_HPP_
#define LIBGUI_MENU_ITEM_HPP_

#include "widget.hpp"

namespace UI {

class HBox;
class Image;

class MenuItem : Widget {
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

public:
    MenuItem() = delete;
    MenuItem(const MenuItem::Type& type);

    void SetIconFromName(std::string_view icon_name);
    void SetIconFromPath(std::string_view file_path);
    
private:
    GtkMenuItem* m_item;

    bool m_registered_accel;
    bool m_checked; // Used for checked icon/status

    HBox m_box;
    Image m_image;
};

} // namespace UI

#endif // LIBGUI_MENU_ITEM_HPP_
