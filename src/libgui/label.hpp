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
// File: label.hpp
// ---------------------------------------------------------------------------

#ifndef LIBGUI_LABEL_HPP_
#define LIBGUI_LABEL_HPP_

#include <libgui/widget.hpp>

namespace UI {

class Label : public Widget {
public:
    Label();
    Label(std::string_view text);

    void SetText(std::string_view text);

private:
    GtkLabel* m_label;
};

} // namespace UI

#endif // LIBGUI_LABEL_HPP_
