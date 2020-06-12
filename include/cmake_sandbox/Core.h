#pragma once

// common includes across header files

// dirty solution to the fact that EasyClangComplete for Sublime doesn't
// recognize external libraries in .h files (.cpp works fine though).

// for guaranteed CMake build success across systems, use "Eigen/Eigen".
// #include "Eigen/Eigen"

// this references my local install of Eigen (/usr/local/include/eigen3),
// purely for the purpose of autocomplete.
#include "eigen3/Eigen/Eigen"
