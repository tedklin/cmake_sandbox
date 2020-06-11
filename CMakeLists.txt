cmake_minimum_required(VERSION 3.14) # 3.11 has FetchContent

project(cmake_sandbox LANGUAGES CXX)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  # c++17 enabled compiler
  set(CMAKE_CXX_STANDARD 17)

  # Let's ensure -std=c++xx instead of -std=g++xx
  set(CMAKE_CXX_EXTENSIONS OFF)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  # Testing only available if this is the main app
  # Note this needs to be done in the main CMakeLists
  # since it calls enable_testing, which must be in the
  # main CMakeLists.
  include(CTest)
endif()

# set the cmake module path of the project
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
# find eigen using FindEigen3.cmake in cmake/ folder
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

# FetchContent
include(FetchContent)
# macro for FetchContent_MakeAvailable (introduced in CMake 3.14)
if(${CMAKE_VERSION} VERSION_LESS 3.14)
  macro(FetchContent_MakeAvailable NAME)
    FetchContent_GetProperties(${NAME})
    if(NOT ${NAME}_POPULATED)
      FetchContent_Populate(${NAME})
      add_subdirectory(${${NAME}_SOURCE_DIR} ${${NAME}_BINARY_DIR})
    endif()
  endmacro()
endif()

# compiled library code is here
add_subdirectory(src)

# executable code is here
add_subdirectory(examples)

# test code is here
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()
