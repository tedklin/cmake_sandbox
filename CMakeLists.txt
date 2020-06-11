cmake_minimum_required (VERSION 3.10)

project(cmake_sandbox LANGUAGES CXX)

# set the cmake module path of the project
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
# find eigen using FindEigen3.cmake in cmake/ folder
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

# the compiled library code is here
add_subdirectory(src)

# the executable code is here
add_subdirectory(examples)
