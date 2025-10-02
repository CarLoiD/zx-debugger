# ---------------------------------------------------------------------------
#   Copyright 2025 Carlos Gurgel
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
# ---------------------------------------------------------------------------
# File: target_macros.cmake
# ---------------------------------------------------------------------------
# Brief: Generalized macros inspired by abseil-cpp helpers to simplify
# library and executable compilation.
# ---------------------------------------------------------------------------

include(CMakeParseArguments)

# Parameters for library/binary cc functions:
# NAME: Name of library target (default output is static library)
# HDRS: Optional list of public headers of the library
# SRCS: List of source files of the library
# LIBS: Optional list of other libraries to be linked into binary target
# COPTS: Optional list of private compilation options
# DEFINES: Optional list of public preprocessor defines
# LINKOPTS: Optional list of linker options
# IDIRS: Optional list of include directories
# LDIRS: Optional list of linked library directories

function(zx_cc_library)
    cmake_parse_arguments(ZX_CC_LIB
        ""                  # No options currently
        "NAME"
        "HDRS;SRCS;COPTS;DEFINES;LINKOPTS;LIBS"
        ${ARGN})
    
    if(NOT ZX_CC_LIB_NAME)
        message(FATAL_ERROR "zx_cc_library() requires NAME")
    endif()

    if(NOT ZX_CC_LIB_SRCS)
        message(FATAL_ERROR "zx_cc_library() requires SRCS")
    endif()

    set(_NAME "zx_${ZX_CC_LIB_NAME}")
    add_library(${_NAME} "")
    target_sources(${_NAME} PRIVATE ${ZX_CC_LIB_SRCS} ${ZX_CC_LIB_HDRS})

    target_link_libraries(${_NAME} 
        PUBLIC  ${ZX_CC_LIB_LIBS}
        PRIVATE ${ZX_CC_LIB_LINKOPTS})

    target_compile_options(${_NAME} PRIVATE ${ZX_CC_LIB_COPTS})
    target_compile_definitions(${_NAME} PUBLIC ${ZX_CC_LIB_DEFINES})

    # Finally...
    add_library(zx::${ZX_CC_LIB_NAME} ALIAS ${_NAME})
endfunction()

function(zx_cc_binary)
    cmake_parse_arguments(ZX_CC_BIN
        ""                  # No options currently
        "NAME"
        "HDRS;SRCS;COPTS;DEFINES;LINKOPTS;LIBS;IDIRS;LDIRS"
        ${ARGN})

    if(NOT ZX_CC_BIN_NAME)
        message(FATAL_ERROR "zx_cc_binary() requires NAME")
    endif()

    if(NOT ZX_CC_BIN_SRCS)
        message(FATAL_ERROR "zx_cc_binary() requires SRCS")
    endif()

    set(_NAME "zx-${ZX_CC_BIN_NAME}")
    add_executable(${_NAME} ${ZX_CC_BIN_SRCS} ${ZX_CC_BIN_HDRS})

    # Optional stuff
    target_include_directories(${_NAME} PRIVATE ${ZX_CC_BIN_IDIRS})
    target_compile_options(${_NAME} PRIVATE ${ZX_CC_BIN_COPTS})
    target_compile_definitions(${_NAME} PRIVATE ${ZX_CC_BIN_DEFINES})
    target_link_libraries(${_NAME} PRIVATE ${ZX_CC_BIN_LIBS})
    target_link_options(${_NAME} PRIVATE ${ZX_CC_BIN_LINKOPTS})
    target_link_directories(${_NAME} PRIVATE ${ZX_CC_BIN_LDIRS})

    add_executable(zx::${ZX_CC_BIN_NAME} ALIAS ${_NAME})
endfunction()

function(zx_add_run TARGET_ALIAS)
    add_custom_target(run
        COMMAND $<TARGET_FILE:${TARGET_ALIAS}>
        DEPENDS zx::dbgclient
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        COMMENT "Running target (${TARGET_ALIAS})")
endfunction()
