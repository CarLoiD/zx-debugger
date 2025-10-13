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

#include <libgui/accelerator_target.hpp>
#include <libgui/box.hpp>
#include <libgui/image.hpp>

namespace UI {

class MenuItem : public Widget, public AcceleratorTarget {
public:
    MenuItem();
    MenuItem(std::string_view text, std::string_view keybind);

    void SetIconFromName(std::string_view icon_name);
    void SetIconFromPath(std::string_view file_path);
    void SetText(std::string_view text);
    
private:
    GtkMenuItem* m_item;

    HBox m_box;
    Image m_image;
};

} // namespace UI

#endif // LIBGUI_MENU_ITEM_HPP_
