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
// File: color.cc
// ---------------------------------------------------------------------------

#include "color.hpp"

#include <gtk/gtk.h>

namespace UI {

Color::Color()
    : r(0), g(0), b(0), a(255)
{}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

Color::Color(uint32_t wcolor) {
    // TBD
}

GdkRGBA Color::GetGdkColor() const {
    GdkRGBA c;
    c.red   = static_cast<float>(r) / 255.0f;
    c.green = static_cast<float>(g) / 255.0f;
    c.blue  = static_cast<float>(b) / 255.0f;
    c.alpha = static_cast<float>(a) / 255.0f;
    return c;
}

uint32_t Color::GetWordColor() const {
    return 0;
}

} // namespace UI
