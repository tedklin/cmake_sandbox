
add_executable(salto SaltoJumpingRobot.cpp)
target_compile_features(salto PRIVATE cxx_std_17)

# here's where the eigen dependency would go if i split them up, see src/
target_link_libraries(salto PRIVATE cmake_sandbox_lib)
