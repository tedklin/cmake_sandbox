# macro for adding executable examples
macro(package_add_example EXAMPLENAME)
  # Create an exectuable in which the example will be stored
  add_executable(${EXAMPLENAME} ${ARGN})

  # Target features and options
  target_compile_features(${EXAMPLENAME} PRIVATE cxx_std_17)
  set_target_properties(${EXAMPLENAME} PROPERTIES CXX_EXTENSIONS OFF)
  target_compile_options(${EXAMPLENAME} PRIVATE "-Wall")

  # Link cmake_sandbox_lib (along with its public dependencies)
  target_link_libraries(${EXAMPLENAME} PRIVATE cmake_sandbox_lib)
endmacro()

package_add_example(salto SaltoJumpingRobot.cpp)
# ^^^ ADD MORE EXAMPLE EXECUTABLES HERE ^^^
