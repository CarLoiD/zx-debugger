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
// File: clickable.hpp
// ---------------------------------------------------------------------------

#ifndef LIBGUI_CLICKABLE_HPP_
#define LIBGUI_CLICKABLE_HPP_

#include <type_traits>
#include <gtk/gtk.h>

#include "base/assert.hpp"

namespace UI {

class Clickable {
public:
    // Pointer to member function (method) version
    template <typename T>
    void SetOnClickCallback(T* instance, void (T::*method)()) {
        // The callback need some non local scope data in order to call the method later
        struct Data {
            T* instance;
            void (T::*method)();
        };

        // Alloc such data on the heap
        auto* udata = new Data;
        udata->instance = instance;
        udata->method = method;

        // Pass as data and set a closure to delete the data when the widget is destroyed
        g_signal_connect_data(
            GetGtkWidget(),
            "clicked",
            G_CALLBACK(+[](GtkWidget*, gpointer user_data) {
                auto* thiz = static_cast<Data*>(user_data);
                (thiz->instance->*(thiz->method))();
            }),
            udata,
            [](gpointer data, GClosure*) { delete static_cast<Data*>(data); },
            static_cast<GConnectFlags>(0)
        );
    }

    // Functor version
    template <typename Callable>
    void SetOnClickCallback(Callable&& cb) {
        // Clean functor type that can be allocated
        using Functor = std::decay_t<Callable>;

        // Same as in pointer to member, non local scope data is needed...
        auto* udata = new Functor(std::forward<Callable>(cb));

        g_signal_connect_data(
            GetGtkWidget(),
            "clicked",
            G_CALLBACK(+[](GtkWidget*, gpointer user_data) {
                auto* f = static_cast<Functor*>(user_data);
                (*f)();
            }),
            udata,
            [](gpointer data, GClosure*) { delete static_cast<Functor*>(data); },
            static_cast<GConnectFlags>(0)
        );
    }

protected:
    virtual GtkWidget* GetGtkWidget() const = 0;
};

} // namespace UI

#endif // LIBGUI_CLICKABLE_HPP_
