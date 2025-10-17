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
// File: stack.hpp
// ---------------------------------------------------------------------------

#ifndef LIBGUI_STACK_HPP_
#define LIBGUI_STACK_HPP_

#include <libgui/widget.hpp>

namespace UI {

class Stack final : public Widget {
public:
    Stack();

    //void Add(Widget& child) override; For now, only supporting named children.
    void AddNamed(Widget& child, std::string_view name);
    
    void SetVisible(std::string_view name);

private:
    GtkStack* m_stack;
};

} // namespace UI

#endif // LIBGUI_STACK_HPP_
