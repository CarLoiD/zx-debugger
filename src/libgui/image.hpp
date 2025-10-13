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
// File: image.hpp
// ---------------------------------------------------------------------------

#ifndef LIBGUI_IMAGE_HPP_
#define LIBGUI_IMAGE_HPP_

#include <libgui/widget.hpp>

namespace UI {

enum class IconSize {
    kInvalid = 0,
    kMenu = 1,          //< 16px
    kSmallToolbar = 2,  //< 16px
    kLargeToolbar = 3,  //< 24px
    kButton = 4,        //< 16px
    kDragAndDrop = 5,   //< 32px
    kDialog = 6,        //< 48px
};

class Image : public Widget {
public:
    Image();
    Image(std::string_view file_path, s32 req_width = -1, s32 req_height = -1);
    Image(std::string_view icon_name, const IconSize& size);

    void SetFromFile(std::string_view file_path);
    void SetFromIconName(std::string_view icon_name, const IconSize& size);

private:
    GtkImage* m_image;
};

} // namespace UI

#endif // LIBGUI_IMAGE_HPP_
