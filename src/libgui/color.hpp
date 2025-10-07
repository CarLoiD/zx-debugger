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
// File: color.hpp
// ---------------------------------------------------------------------------

#ifndef LIBGUI_COLOR_HPP_
#define LIBGUI_COLOR_HPP_

#include "base/types.hpp"

typedef struct _GdkRGBA GdkRGBA;

namespace UI {

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    
    Color();
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
    Color(uint32_t wcolor);

    GdkRGBA   GetGdkColor() const;
    uint32_t  GetWordColor() const;
};

} // namespace UI

#endif // LIBGUI_COLOR_HPP_
