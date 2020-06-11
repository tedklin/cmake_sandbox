add_executable(salto SaltoJumpingRobot.cpp)
target_compile_features(salto PRIVATE cxx_std_17)

# links cmake_sandbox_lib along with PUBLIC eigen
target_link_libraries(salto PRIVATE cmake_sandbox_lib)
