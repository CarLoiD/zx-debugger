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
// File: path.cc
// ---------------------------------------------------------------------------

#include "path.hpp"

namespace Base::Path {

std::string GetDirectoryName(std::string_view file_path) {
    std::string str = std::string(file_path);

    size_t at = str.find_last_of("/\\");
    if (at == std::string::npos) {
        return "."; // No directory
    }

    if (at == 0) {
        return str.substr(0, 1);
    }

    return str.substr(0, at);
}

} // namespace Base::Path
