include(GoogleTest)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)

# macro for adding gtests
macro(package_add_test TESTNAME)
  # Create an exectuable in which test(s) will be stored
  add_executable(${TESTNAME} ${ARGN})

  # Target features and options
  target_compile_features(${TESTNAME} PRIVATE cxx_std_17)
  set_target_properties(${TESTNAME} PROPERTIES CXX_EXTENSIONS OFF)
  target_compile_options(${TESTNAME} PRIVATE "-Wall")

  # Link the Google test infrastructure, mocking library, and a default main
  # function to the test executable.
  # Remove g_test_main if writing your own main function.
  target_link_libraries(${TESTNAME} gtest gmock gtest_main)
  
  # Link our own library cmake_sandbox_lib (along with its public dependencies)
  target_link_libraries(${TESTNAME} cmake_sandbox_lib)

  # gtest_discover_tests replaces gtest_add_tests,
  # See https://cmake.org/cmake/help/v3.10/module/GoogleTest.html
  # for more options to pass to it.
  gtest_discover_tests(${TESTNAME}
    # Set a working directory to your project root so that you can find test
    # data via paths relative to project root.
    WORKING_DIRECTORY ${PROJECT_DIR}
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
  )
set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(ContinuousSystemTest ContinuousSystemTest.cpp)
# ^^^ ADD NEW TESTS HERE
