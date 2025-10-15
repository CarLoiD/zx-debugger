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
// File: ascii.hpp
// ---------------------------------------------------------------------------

#ifndef BASE_ASCII_HPP_
#define BASE_ASCII_HPP_

#include <base/types.hpp>
#include <string>

namespace Base::ASCII {

[[nodiscard]] char CharToUpper(unsigned char c);
[[nodiscard]] char CharToLower(unsigned char c);
[[nodiscard]] std::string StrToLower(std::string_view source);
[[nodiscard]] std::string StrToUpper(std::string_view source);

} // namespace Base::ASCII

#endif // BASE_ASCII_HPP_
