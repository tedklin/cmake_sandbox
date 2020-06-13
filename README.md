# CMake Sandbox
[![Build Status](https://travis-ci.com/tedklin/cmake_sandbox.svg?branch=master)](https://travis-ci.com/tedklin/cmake_sandbox)

This is a simple CMake project setup created from scratch, based heavily on [this excellent guide](https://cliutils.gitlab.io/modern-cmake/) along with tweaks I've observed from other CMake-based libraries.
The plan is to continually add to this and use it as a standardized template for the creation of new personal CMake projects.

Note that the C++ code included is irrelevant, the project setup is the focus of this repository.

## Running CMake

Building with [CMake 3.13.5](https://cmake.org/cmake/help/v3.13/manual/cmake.1.html) onwards (otherwise use the manual procedure of creating build directory etc.):
~~~
cmake -S . -B build
cmake --build build
~~~

Assuming you've built the project and are in the project home directory...

To test:
~~~
cmake --build build --target test
~~~

To run examples:
~~~
/build/examples/MyExampleExecutable
~~~

## Common features supported

### External library usage
- [Eigen3](https://eigen.tuxfamily.org/dox/TopicCMakeGuide.html) 
  - tested Ubuntu 18.04 installation methods including both apt ([libeigen3-dev](https://packages.ubuntu.com/bionic/libeigen3-dev)) and the [manual download and install](http://eigen.tuxfamily.org/index.php?title=Main_Page).
- [GoogleTest](https://github.com/google/googletest)
  - this is accessed via FetchContent, which was introduced in CMake 3.11.

### Misc features
- [ccache](https://github.com/ccache/ccache)
- [Travis-CI](https://travis-ci.com/github/tedklin/cmake_sandbox) (continuous integration) with GoogleTest

### Misc possible things to try / test
- interfacing with different editors and IDEs, including VSCode / SublimeText / QtCreator / CLion
  - figure out how various code completion tools work for referenced external libraries works through CMake.
      - referencing a local installation or even a project-internal installation works, but that can be unreliable for various reasons.
      - see branches for VSCode and Sublime (but note that those may be outdated wrt the master branch. refer to respective readmes for specific differences from master).
- formally packaging projects as libraries for others to use
