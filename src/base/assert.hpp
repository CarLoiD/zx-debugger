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
// File: assert.hpp
// ---------------------------------------------------------------------------

#ifndef BASE_ASSERT_HPP_
#define BASE_ASSERT_HPP_

#include "base/types.hpp"

#ifdef NDEBUG
 #define ASSERT(condition, msg) 
 #define ASSERT_PTR(ptr) 
#else
 #define ASSERT(condition, msg) __InternalAssert(condition, msg, __FILE__, __LINE__, __func__)
 #define ASSERT_PTR(ptr) __InternalAssertPtr(ptr, __FILE__, __LINE__, __func__)

 void __InternalAssert(bool condition, std::string_view msg, const char* fl, int ln, const char* f);
 void __InternalAssertPtr(const void* ptr, const char* fl, int ln, const char* f);
#endif

#endif // BASE_ASSERT_HPP_
