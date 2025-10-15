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
#include "base/ascii.hpp"
#include "base/assert.hpp"

namespace {

constexpr auto s_modifiers[] = {
    "CTRL", 
    "SHIFT", 
    "ALT",
};

[[nodiscard]] bool ProcessKeybind(std::string_view keybind, u32& mods, u32& key) {
    std::string upper = Base::ASCII::ToUpper(keybind);
}

} // namespace

namespace UI {

AcceleratorTarget::AcceleratorTarget()
    : m_accel_item(nullptr)
    , m_active(false)
{}

void AcceleratorTarget::SetKeybind(std::string_view keybind) {
    u32 mods = 0;
    u32 key = 0;
    
    if (ProcessKeybind(upper, mods, key)) {
        gtk_widget_add_accelerator(
            m_accel_item,
            "activate",
            Application::GetAccelGroup(),
            key,
            static_cast<GdkModifierType>(mods), 0);
        
        // If can't process keybind, no harm is done (fatally)...
        // However, the accelerator preview is also not set.
        m_accel_label.SetText(keybind);    
    }
}

} // namespace UI
