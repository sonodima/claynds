# This file is part of the ClayNDS project.
#
# (c) 2025 Tommaso Dimatore
#
# For the full copyright and license information, please view the LICENSE
# file that was distributed with this source code.

cmake_minimum_required(VERSION 3.14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(claynds
  VERSION 1.0.0 
  DESCRIPTION "Single-header Clay renderer for the NDS using GL2D"
  HOMEPAGE_URL "https://github.com/sonodima/claynds"
  LANGUAGES C)

# ================================
# Options
# ================================

option(CLAYNDS_BUILD_EXAMPLES "Build Examples" OFF)

# ================================
# Configuration & Installation
# ================================

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

add_library(claynds INTERFACE)
add_library(claynds::claynds ALIAS claynds)
target_compile_features(claynds INTERFACE c_std_99)
target_include_directories(claynds
INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/ClayNDSConfig.cmake.in"
  "${PROJECT_BINARY_DIR}/ClayNDSConfig.cmake"
  INSTALL_DESTINATION "${CMAKE_INSTALL_DATADIR}/cmake/ClayNDS")
write_basic_package_version_file(
  "${PROJECT_BINARY_DIR}/ClayNDSConfigVersion.cmake"
  COMPATIBILITY SameMajorVersion
  ARCH_INDEPENDENT)

install(TARGETS claynds EXPORT ClayNDSTargets)
install(EXPORT ClayNDSTargets
  DESTINATION "${CMAKE_INSTALL_DATADIR}/cmake/ClayNDS"
  NAMESPACE claynds::
  FILE "ClayNDSTargets.cmake")

install(FILES
  "${PROJECT_BINARY_DIR}/ClayNDSConfigVersion.cmake"
  "${PROJECT_BINARY_DIR}/ClayNDSConfig.cmake"
  DESTINATION "${CMAKE_INSTALL_DATADIR}/cmake/ClayNDS")
install(DIRECTORY "include/" TYPE INCLUDE)

# ================================
# Examples
# ================================

if(CLAYNDS_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()
