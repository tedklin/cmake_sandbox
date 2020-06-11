#include "cmake_sandbox/ContinuousSystem.h"

#include <complex>
#include "Eigen/Eigen"

// in retrospect probably should've inlined the getters
const Eigen::Matrix3d& ContinuousSystem::GetSystem() const {
	return system_;
}

const Eigen::EigenSolver<Eigen::Matrix3d>::EigenvalueType& ContinuousSystem::GetEigenvalues() const {
	return eigenvalues_;
}

bool ContinuousSystem::IsStable() const {
	for (unsigned row = 0; row < eigenvalues_.rows(); ++row) {
		if (eigenvalues_(row, 0).real() > 0) {
			return false;
		}

		// discrete stability implementation for fun
		// if (std::abs(eigenvalues_(row, 0)) >= 1) {
		// 	return false;
		// }
	}
	return true;
}
