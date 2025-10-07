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
# File: CMakeLists.txt
# ---------------------------------------------------------------------------

zx_cc_binary(
    NAME 
        dbgclient
    SRCS 
        "../base/assert.cc"
        "../libgui/application.cc"
        "../libgui/color.cc"
        "../libgui/window.cc"
        "../libgui/widget.cc"
        "main.cc"
    IDIRS ${GTK3_INCLUDE_DIRS} ${CMAKE_CURRENT_LIST_DIR}
    LDIRS ${GTK3_LIBRARY_DIRS}
    LIBS  ${GTK3_LIBRARIES}
    COPTS ${GTK3_CFLAGS_OTHER}
)
