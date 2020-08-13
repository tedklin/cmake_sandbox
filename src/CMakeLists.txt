# Note that headers are optional, and do not affect add_library, but they will not
# show up in some IDEs unless they are listed in add_library.

list(APPEND SOURCE_LIST "${PROJECT_SOURCE_DIR}/src/ContinuousSystem.cpp")
# ^^^ APPEND NEW SOURCE FILES TO THE SOURCE_LIST

# Make an automatic library - will be static or dynamic based on user setting
# add_library(cmake_sandbox_lib ${SOURCE_LIST} ${HEADER_LIST})
add_library(cmake_sandbox_lib ${SOURCE_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(cmake_sandbox_lib PUBLIC ../include)

# Public dependency on Eigen (everything that uses this library is going to need Eigen)
target_link_libraries(cmake_sandbox_lib PUBLIC Eigen3::Eigen)

# All users of this library will need at least C++11
target_compile_features(cmake_sandbox_lib PUBLIC cxx_std_11)
set_target_properties(cmake_sandbox_lib PROPERTIES CXX_EXTENSIONS OFF)

# Compiler flags
target_compile_options(cmake_sandbox_lib PRIVATE ${compiler_options})
