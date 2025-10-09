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
// File: image.cc
// ---------------------------------------------------------------------------

#include "image.hpp"
#include "base/assert.hpp"

namespace UI {

Image::Image() {
    m_handle = gtk_image_new();
    g_object_ref_sink(m_handle);

    m_image = GTK_IMAGE(m_handle);
}

Image::Image(std::string_view file_path, s32 req_width, s32 req_height) {
    m_handle = gtk_image_new_from_file(file_path.data());
    g_object_ref_sink(m_handle);

    m_image = GTK_IMAGE(m_handle);

    RequestSize(req_width, req_height);
}

Image::Image(std::string_view icon_name, const IconSize& size) {
    m_handle = gtk_image_new_from_icon_name(
        icon_name.data(),
        static_cast<GtkIconSize>(size));

    g_object_ref_sink(m_handle);
    m_image = GTK_IMAGE(m_handle);
}

Image::~Image() {}

void Image::SetFromFile(std::string_view file_path) {
    ASSERT_PTR(m_image);

    gtk_image_clear(m_image);
    gtk_image_set_from_file(m_image, file_path.data());
}

void Image::SetFromIconName(std::string_view icon_name, const IconSize& size) {
    ASSERT_PTR(m_image);

    gtk_image_clear(m_image);
    gtk_image_set_from_icon_name(
        m_image,
        icon_name.data(), 
        static_cast<GtkIconSize>(size));
}

} // namespace UI
