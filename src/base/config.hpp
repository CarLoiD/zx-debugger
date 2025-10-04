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
// File: config.hpp
// ---------------------------------------------------------------------------
// Brief: Macros for general pre-processed configuration
// ---------------------------------------------------------------------------

#ifndef BASE_CONFIG_HPP_
#define BASE_CONFIG_HPP_

#ifdef ZX_CONFIG_TOOLCHAIN_GCC
 #error ZX_CONFIG_TOOLCHAIN_GCC cannot be set manually
#elif defined(__GNUC__) && !defined(__clang__)
 #define ZX_CONFIG_TOOLCHAIN_GCC 1
#endif

#endif // BASE_CONFIG_HPP_
