## CMake Sandbox

This is a simple CMake project setup made from scratch, following [this excellent guide](https://cliutils.gitlab.io/modern-cmake/) along with tweaks I've observed from other CMake-based libraries.
The plan is to continually add to this and use it as a standardized template for the creation of new personal projects based on CMake.

Note that the C++ code included is irrelevant, the project setup (mostly in the CMakeLists.txt) are the focus of this repository.

### Common dependencies included
- [Eigen3](https://eigen.tuxfamily.org/dox/TopicCMakeGuide.html) 
  - at the moment this needs to be downloaded separately and *installed*, not just copied to the standard header-only library location.
- [GoogleTest](https://github.com/google/googletest)
