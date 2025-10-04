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

#include <string_view>
#include <gtk/gtk.h>

#include "base/types.hpp"

void SetWidgetBgColor(GtkWidget* widget, const char* color_str);
void SetWidgetMargin(GtkWidget* widget, int32_t margin);
void SetWidgetMarginX(GtkWidget* widget, int32_t margin);
void SetWidgetMarginY(GtkWidget* widget, int32_t margin);
void SetWidgetTopLeftMargin(GtkWidget* widget, int32_t margin);
void SetWidgetBottomRightMargin(GtkWidget* widget, int32_t margin);
void WidgetEvalCSS(GtkWidget* context, const std::string_view expression);
void GdkEvalCSS(const std::string_view expression);

#endif // CLIENT_UI_WIDGET_UTILS_HPP_
