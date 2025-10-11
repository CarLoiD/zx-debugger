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
// File: accelerator_target.cc
// ---------------------------------------------------------------------------

#include <regex>
#include <string>

#include "accelerator_target.hpp"
#include "application.hpp"
#include "base/assert.hpp"

namespace UI {

AcceleratorTarget::AcceleratorTarget()
    : m_item(nullptr)
    , m_active(false)
{}

void AcceleratorTarget::SetKeybind(std::string_view keybind) {
    
}

} // namespace UI
