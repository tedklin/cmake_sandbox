# CMake Sandbox
[![Build Status](https://travis-ci.com/tedklin/cmake_sandbox.svg?branch=master)](https://travis-ci.com/tedklin/cmake_sandbox)

This is a CMake project setup created from scratch, based heavily on [this excellent introduction to Modern CMake](https://cliutils.gitlab.io/modern-cmake/) along with tweaks I've observed from other CMake-based libraries.
The plan is to continually add to this and use it as a standardized template for the creation of new personal projects and libraries.

Note that the C++ code included is irrelevant, the project setup is the focus of this repository.


## Quick setup

Assuming all dependencies (CMake, relevant libraries, ccache, etc.) are installed, simply add newly created files in their respective folder's CMakeLists.txt. In each CMakeLists.txt, look for comments with three carets (**^^^**) to find where to do this.


## Running CMake

Building with [CMake 3.13.5](https://cmake.org/cmake/help/v3.13/manual/cmake.1.html) onwards (otherwise use the manual procedure of creating the build directory, etc.):
~~~
cmake -S . -B build
cmake --build build
~~~

Assuming you've built the project and are in the project home directory...

To run all tests:
~~~
cmake --build build --target test
~~~

To run examples or specific tests:
~~~
build/examples/MyExampleExecutable

build/tests/MyTestExecutable
~~~


## Integration with other CMake projects

This template was designed such that a library based on this template can be easily integrated in other CMake projects that want to use the library.

Suppose I want to use the *cmake_sandbox* library in another CMake project *MyProject*. I can simply download the entire *cmake_sandbox* repository, nest it in a folder under MyProject (e.g. "MyProject/thirdparty/cmake_sandbox"), and call add_subdirectory (e.g. *add_subdirectory(thirdparty/cmake_sandbox)* in MyProject's main CMakeLists.txt before building the code that relies on it.

Including a library this way would then skip building the library's tests and avoid setting environment variables for MyProject.

Note that the [default build type](https://cmake.org/cmake/help/v3.11/variable/CMAKE_BUILD_TYPE.html) will be set to "Debug" if this is the top-level CMake project. This means if if you're doing dev directly on the project, you can use gdb on executables in the build folder. If you're simply using this library through add_subdirectory, CMake does an optimized "Release" build instead. You can also follow this idea for enabling tools like sanitizers and adding other compiler flags.


## Common features supported

### External library usage
- [Eigen3](https://eigen.tuxfamily.org/dox/TopicCMakeGuide.html) 
  - tested Ubuntu 18.04 installation methods including both apt ([libeigen3-dev](https://packages.ubuntu.com/bionic/libeigen3-dev)) and the [manual download and install](http://eigen.tuxfamily.org/index.php?title=Main_Page).
- [GoogleTest](https://github.com/google/googletest)
  - this is accessed via FetchContent, which was introduced in CMake 3.11.

### Misc features
- [ccache](https://github.com/ccache/ccache)
- [Travis-CI](https://travis-ci.com/github/tedklin/cmake_sandbox) (continuous integration) with GoogleTest
