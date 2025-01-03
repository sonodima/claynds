# This file is part of the ClayNDS project.
#
# (c) 2025 Tommaso Dimatore
#
# For the full copyright and license information, please view the LICENSE
# file that was distributed with this source code.

cmake_minimum_required(VERSION 3.14)

project(clayndse
  DESCRIPTION "Examples for the ClayNDS project"
  LANGUAGES C)

# ================================
# Dependencies
# ================================

include(FetchContent)

FetchContent_Declare(Clay
  GIT_REPOSITORY "https://github.com/nicbarker/clay.git"
  GIT_TAG        "main")
FetchContent_GetProperties(Clay)
if(NOT clay_POPULATED)
  FetchContent_Populate(Clay)
endif()

# ================================
# Examples Definitions
# ================================

function(add_sample FILE)
  add_executable(clayndse_${FILE})
  target_sources(clayndse_${FILE} PRIVATE "${FILE}.c")
  target_compile_features(clayndse_${FILE} INTERFACE c_std_99)
  target_include_directories(clayndse_${FILE} PRIVATE "${clay_SOURCE_DIR}")
  target_link_libraries(clayndse_${FILE} PRIVATE m claynds)

  set_target_properties(clayndse_${FILE} PROPERTIES OUTPUT_NAME "${FILE}")
  nds_create_rom(clayndse_${FILE} NAME "ClayNDS Example")
endfunction()

add_sample(minimal)
