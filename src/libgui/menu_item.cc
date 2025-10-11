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
// File: menu_item.cc
// ---------------------------------------------------------------------------

#include "menu_item.hpp"
#include "box.hpp"
#include "image.hpp"

namespace UI {

MenuItem::AccelKey::AccelKey()
    : mods(0)
    , key(0)
{}

MenuItem::AccelKey::AccelKey(u32 key) {
    this->mods = 0;
    this->key = key;
}

MenuItem::AccelKey::AccelKey(u32 mods, u32 key) {
    this->mods = mods;
    this->key = key;
}

MenuItem::AccelKey::operator bool() const {
    return this->key != 0;
}

} // namespace UI
