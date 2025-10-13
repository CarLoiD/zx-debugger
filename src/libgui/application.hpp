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
// File: application.hpp
// ---------------------------------------------------------------------------

#ifndef LIBGUI_APPLICATION_HPP_
#define LIBGUI_APPLICATION_HPP_

#include <gtk/gtk.h>
#include <string_view>

namespace UI {

class Window;

class Application final {
public:
    static GtkApplication* GetDefault();
    static GtkAccelGroup* GetAccelGroup();

private:
    // Depending from where the main executable is called, the application can have it's
    // current working directory modified so that the app resources folders can't be reached.
    // This function removes that behavior in a portable way for Windows and POSIX-based systems.
    void SetCwdToAppPath();

public:
    Application() = delete;
    Application(int argc, char* argv[], const bool dark_theme = true);
    ~Application();

    int Run(Window& window);

private:
    GtkApplication* m_app;
    GtkAccelGroup* m_accel_group; // Used for menu item accelerators in application scope

    // Saved program arguments
    int m_argc;
    char** m_argv;
};

} // namespace UI

#endif // LIBGUI_APPLICATION_HPP_
