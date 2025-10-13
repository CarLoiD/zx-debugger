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
// File: attributes.hpp
// ---------------------------------------------------------------------------

#ifndef BASE_ATTRIBUTES_HPP_
#define BASE_ATTRIBUTES_HPP_

#include <base/config.hpp>

// __has_attribute is defined by GCC 5+ and Clang to evaluate attribute support

#ifdef __has_attribute
 #define ZX_HAVE_ATTRIBUTE(x) __has_attribute(x)
#else
 #define ZX_HAVE_ATTRIBUTE(x) 0
#endif // __has_attribute

// Attributes for controlling inlining

#if ZX_HAVE_ATTRIBUTE(always_inline) || ZX_CONFIG_TOOLCHAIN_GCC
 #define ZX_ATTRIBUTE_ALWAYS_INLINE __attribute__((always_inline))
#else
 #define ZX_ATTRIBUTE_ALWAYS_INLINE 
#endif

#if ZX_HAVE_ATTRIBUTE(noinline) || ZX_CONFIG_TOOLCHAIN_GCC
 #define ZX_ATTRIBUTE_NOINLINE __attribute__((always_inline))
#else
 #define ZX_ATTRIBUTE_NOINLINE 
#endif

// Alignment and packing

// This is meant to single byte pack structures where serial I/O is useful
#if ZX_HAVE_ATTRIBUTE(packed) || ZX_CONFIG_TOOLCHAIN_GCC 
 #define ZX_ATTRIBUTE_PACKED __attribute__((packed))
#else
 #define ZX_ATTRIBUTE_PACKED 
#endif

// Meant to use for functions, hence the explicit direction, for data, prefer using C++11 alignas()
#if ZX_HAVE_ATTRIBUTE(aligned) || ZX_CONFIG_TOOLCHAIN_GCC
 #define ZX_ATTRIBUTE_FUNC_ALIGN(bytes) __attribute__((aligned(bytes)))
#else
 #define ZX_ATTRIBUTE_FUNC_ALIGN(bytes) 
#endif

#endif // BASE_ATTRIBUTES_HPP_
