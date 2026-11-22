cmake_minimum_required(VERSION 3.16)
project(RungeKuttaButcherTable LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Emit compile_commands.json for clangd / IDE tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# deal.II DebugRelease installs expect Debug or Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Prefer an explicit DEAL_II_DIR when present
if(DEFINED ENV{DEAL_II_DIR} AND NOT DEAL_II_DIR)
  set(DEAL_II_DIR "$ENV{DEAL_II_DIR}")
endif()

# Default macOS deal.II.app bundle (official Tahoe/Sequoia packages)
set(_DEAL_II_APP_PREFIX "/Applications/deal.II.app/Contents/Resources/Libraries")
if(NOT DEAL_II_DIR AND EXISTS "${_DEAL_II_APP_PREFIX}/lib/cmake/deal.II/deal.IIConfig.cmake")
  set(DEAL_II_DIR "${_DEAL_II_APP_PREFIX}")
endif()

find_package(deal.II 9.5 REQUIRED
  HINTS ${DEAL_II_DIR} ${DEAL_II_DIR}/lib/cmake/deal.II
  PATHS ${_DEAL_II_APP_PREFIX}
)

deal_ii_initialize_cached_variables()

add_executable(rk_butcher_table src/main.cpp)
deal_ii_setup_target(rk_butcher_table)
