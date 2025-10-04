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

#include <iostream>

namespace UI {

constexpr auto kPackageName = "com.carloid.zxdbg";

static void DummyActivate(GtkApplication* app, gpointer udata) {
    auto* thiz = static_cast<Application*>(udata);
    thiz->SetupUI();
}

GtkWidget* SetupGtkWindow(GtkApplication* app) {
    GtkWidget* window = gtk_application_window_new(app);
    
    GtkWindow* wnd = GTK_WINDOW(window);
    gtk_window_set_title(wnd, "zx-debugger");
    gtk_window_set_default_size(wnd, 1280, 720);

    return window;
}

void FlushGtkWindow(GtkWidget* window) {
    gtk_widget_show_all(window);
}

void Application::SetupWindow() {
    m_window = SetupGtkWindow(m_app);
    m_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(m_window), m_vbox);
}

void Application::SetupMenuBar() {

}

void Application::SetupArea() {
    m_area = gtk_label_new("MAIN AREA (PLACEHOLDER)");
    gtk_widget_set_hexpand(m_area, true);
    gtk_widget_set_vexpand(m_area, true);
    gtk_box_pack_start(GTK_BOX(m_vbox), m_area, true, true, 0);

    // TODO: Implement SetWidgetBgColor(m_area, "#222222");
}

void Application::SetupStatusBar() {
    GtkWidget* m_status_frame = gtk_frame_new(nullptr);
    gtk_frame_set_shadow_type(GTK_FRAME(m_status_frame), GTK_SHADOW_NONE);

    GtkWidget* m_status_bar = gtk_statusbar_new();
}

Application::Application(int argc, char* argv[])
    : m_app(nullptr)
    , m_vbox(nullptr)
    , m_area(nullptr)
    , m_window(nullptr)
    , m_argc(argc)
    , m_argv(argv)
{
    m_app = gtk_application_new(kPackageName, G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(m_app, "activate", G_CALLBACK(DummyActivate), this);
}

Application::~Application() {
    g_object_unref(m_app);
}

int Application::Run() {
    return g_application_run(G_APPLICATION(m_app), m_argc, m_argv); 
}

void Application::SetupUI() {
    SetupWindow();
    SetupMenuBar();
    SetupArea();
    SetupStatusBar();
    
    // Force dark theme
    GtkSettings* settings = gtk_settings_get_default();
    g_object_set(settings, "gtk-application-prefer-dark-theme", true, NULL);

    FlushGtkWindow(m_window);
}

} // namespace UI
