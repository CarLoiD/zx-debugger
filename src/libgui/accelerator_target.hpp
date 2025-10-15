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
// File: accelerator_target.hpp
// ---------------------------------------------------------------------------

#ifndef LIBGUI_ACCELERATOR_TARGET_HPP_
#define LIBGUI_ACCELERATOR_TARGET_HPP_

#include <libgui/label.hpp>

namespace UI {

// Used for compatibility with old way of defining keybinds.
// This will be removed later on in favor of using SetKeybind()
// from AcceleratorTarget.
struct AccelKey {
    u32 mods;
    u32 key;

    AccelKey() : mods(0), key(0) {}
    AccelKey(u32 mods, u32 key) { this->mods = mods; this->key = key; }
    operator bool() const { return this->key != 0; }
};

class AcceleratorTarget {
public:
    AcceleratorTarget();

    // This is a little ambitious since it goes "contrary" to the GTK design.
    // However, it's a matter of taste that "Ctrl+Shift+F5" is more expressive and
    // easier to write rather than { GDK_CONTROL_MASK | GDK_SHIFT_MASK, GDK_KEY_F5 }.
    // Even then, GTK internally maps visible accelerator label to be "Shift+Ctrl+F5"
    // Which can be not too familiar for applications on Windows, so this gives the
    // opportunity to also set the accelerator label exactly how the keybind is defined.
    // keybind is case-insensitive so "SHIFT+CTRL+F5" should work fine, as well as "sHIfT+cTrL+f5".
    // But do keep in mind that's how the visible label will look like.
    void SetKeybind(std::string_view keybind);

protected:
    GtkWidget* m_accel_item;
    Label m_accel_label;

private:
    bool m_active;
};

} // namespace UI

#endif // LIBGUI_ACCELERATOR_TARGET_HPP_
