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
#include "base/path.hpp"

#if defined(ZX_CONFIG_PLATFORM_WIN32)
 #include <windows.h>
#elif defined(ZX_CONFIG_PLATFORM_UNIX_BASED)
 #include <unistd.h>
#endif 

namespace {
    GtkApplication* g_app = nullptr;
    GtkAccelGroup* g_accel_group = nullptr;
}

namespace UI {

constexpr auto kPackageName = "com.libgui.application";

GtkApplication* Application::GetDefault() {
    return g_app;
}

GtkAccelGroup* Application::GetAccelGroup() {
    return g_accel_group;
}

void Application::SetCwdToAppPath() {
    char buffer[256];

#if defined(ZX_CONFIG_PLATFORM_WIN32)
    GetModuleFileNameA(nullptr, buffer, sizeof(buffer));
    auto dir = Base::Path::GetDirectoryName(buffer);
    SetCurrentDirectoryA(dir.c_str());
#elif defined(ZX_CONFIG_PLATFORM_UNIX_BASED)
    size_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (len != -1) {
        buffer[len] = '\0';
        auto dir = Base::Path::GetDirectoryName(buffer);
        chdir(dir.c_str());
    }
#endif
}

Application::Application(int argc, char* argv[], const bool dark_theme)
    : m_app(nullptr)
    , m_accel_group(nullptr)
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

    m_accel_group = gtk_accel_group_new();

    g_object_set(
        gtk_settings_get_default(), 
        "gtk-application-prefer-dark-theme", 
        dark_theme, 
        nullptr);

    g_app = m_app;
    g_accel_group = m_accel_group;

    SetCwdToAppPath();
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
