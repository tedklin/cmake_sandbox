## CMake Sandbox

This is a simple CMake project setup created from scratch, based heavily on [this excellent guide](https://cliutils.gitlab.io/modern-cmake/) along with tweaks I've observed from other CMake-based libraries.
The plan is to continually add to this and use it as a standardized template for the creation of new personal CMake projects.

Note that the C++ code included is irrelevant, the project setup (mostly in the CMakeLists.txt) are the focus of this repository.

### Common dependencies supported
- [Eigen3](https://eigen.tuxfamily.org/dox/TopicCMakeGuide.html) 
  - at the moment this needs to be downloaded separately and *installed*, not just copied to the standard header-only library location in your operating system.
  - eventually want to support the more convenient method of installation via libeigen3-dev.
- [GoogleTest](https://github.com/google/googletest)
  - this is accessed via FetchContent, which was introduced in CMake 3.11.
