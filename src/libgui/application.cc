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
// File: application.cc
// ---------------------------------------------------------------------------

#include "application.hpp"
#include "window.hpp"
#include "base/assert.hpp"

namespace {
    GtkApplication* g_app = nullptr;
}

namespace UI {

constexpr auto kPackageName = "com.libgui.application";

GtkApplication* Application::GetDefault() {
    return g_app;
}

Application::Application(int argc, char* argv[], const bool dark_theme)
    : m_app(nullptr)
    , m_argc(argc)
    , m_argv(argv)
{
    // Need GTK3.6+ in order to support widget tick callbacks for smooth animations
    ASSERT(gtk_get_major_version() >= 3, "GTK major version less than 3");
    ASSERT(gtk_get_minor_version() >= 6, "GTK minor version less than 6");

    m_app = gtk_application_new(kPackageName, G_APPLICATION_DEFAULT_FLAGS);
    
    // Register the application in order to construct windows at demand before Run()
    GError* error = nullptr;
    if (!g_application_register(G_APPLICATION(m_app), nullptr, &error)) {
        ASSERT(!error, error->message);
        if (error) g_error_free(error);
    }

    g_object_set(gtk_settings_get_default(), "gtk-application-prefer-dark-theme", dark_theme, nullptr);
    g_app = m_app;
}

Application::~Application() {
    g_object_unref(G_OBJECT(m_app));
}

int Application::Run(UI::Window& wnd) {
    g_signal_connect(m_app, "activate", G_CALLBACK(+[](GtkApplication* app, gpointer udata) {
        UI::Window* window = static_cast<UI::Window*>(udata);
        window->ShowAll();
    }), &wnd);

    // Needed in order to detect quit events
    g_signal_connect(
        GTK_WINDOW(wnd.GetHandle()), 
        "delete-event",
        G_CALLBACK(+[](GtkWidget*, GdkEvent*, gpointer udata) -> bool {
            UI::Window* window = static_cast<UI::Window*>(udata);
            return window->Close();
        }), &wnd);

    return g_application_run(G_APPLICATION(m_app), m_argc, m_argv); 
}

} // namespace UI
