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
// File: button.hpp
// ---------------------------------------------------------------------------

#ifndef LIBGUI_BUTTON_HPP_
#define LIBGUI_BUTTON_HPP_

#include "widget.hpp"
#include "clickable.hpp"

namespace UI {

class Button : public Widget, public Clickable {
public:
    Button();
    Button(std::string_view label, const bool use_mnemonics = false);
    
    void SetLabel(std::string_view label, const bool use_mnemonics = false);
    std::string_view GetLabel() const;

    GtkWidget* GetGtkWidget() const override {
        return m_handle;
    }
    
private:
    GtkButton* m_btn;
};

} // namespace UI

#endif // LIBGUI_BUTTON_HPP_
