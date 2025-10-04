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
// File: widget_utils.hpp
// ---------------------------------------------------------------------------

#ifndef CLIENT_UI_WIDGET_UTILS_HPP_
#define CLIENT_UI_WIDGET_UTILS_HPP_

#include <gtk/gtk.h>
#include "base/types.hpp"

// TODO: Maybe later on a refactoring, a Widget class can be implemented
// along with it's subclaassed like ButtonWidget, MenuWidget etc.

namespace UI {

struct MarginSelector {
    enum Options : uint32_t {
        kStart      = (1 << 0),
        kEnd        = (1 << 1),
        kTop        = (1 << 2),
        kBottom     = (1 << 3),
    };
};

void SetWidgetBgColor(GtkWidget* ptr, std::string_view color_str);
void SetWidgetMargin(GtkWidget* ptr, int margin);
void SetWidgetMargin(GtkWidget* ptr, int margin, MarginSelector::Options& flags);
void SetWidgetMarginX(GtkWidget* ptr, int margin);
void SetWidgetMarginY(GtkWidget* ptr, int margin);
void EvalCSS(GtkWidget* context, std::string_view expression);
void GdkEvalCSS(std::string_view expression);

} // namespace UI

#endif // CLIENT_UI_WIDGET_UTILS_HPP_
