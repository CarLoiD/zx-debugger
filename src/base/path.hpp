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
// File: path.hpp
// ---------------------------------------------------------------------------

#ifndef BASE_PATH_HPP_
#define BASE_PATH_HPP_

#include <base/types.hpp>
#include <string>

namespace Base::Path {

std::string GetDirectoryName(std::string_view file_path);

} // namespace Base::Path

#endif // BASE_PATH_HPP_
