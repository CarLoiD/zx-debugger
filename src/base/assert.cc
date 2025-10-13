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
// File: assert.cc
// ---------------------------------------------------------------------------

#include "assert.hpp"

#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>

#if defined(__MINGW32__) || defined(_WIN32)
#include <windows.h>
#endif

static void MessageError(std::string_view msg, const char* fl, int ln, const char* f) {
    std::string path = std::string(fl);
    
    size_t sl_idx = path.find_last_of('/');
    if (sl_idx != std::string::npos) {
        path = path.substr(sl_idx + 1);
    }

    std::stringstream err_msg;
    err_msg << path << ':' << ln;
    err_msg << " \'" << f << "()\': Assertion Failed!\nmsg: \"";
    err_msg << msg.data() << "\"\n";

    msg = err_msg.str();

#if defined(__MINGW32__) || defined(_WIN32)
    MessageBox(nullptr, msg.data(), "Error", MB_OK | MB_ICONERROR);
#else
    std::cout << msg.data();
#endif
}

void __InternalAssert(bool condition, std::string_view msg, const char* fl, int ln, const char* f) {
    if (!condition) {
        MessageError(msg, fl, ln, f);
        exit(-1);
    }
}

void __InternalAssertPtr(const void* ptr, const char* fl, int ln, const char* f) {
    if (!ptr) {
        __InternalAssert(false, "ASSERT_PTR", fl, ln, f);
    }
}
