#ifndef EIGEN_WRAP_HPP
#define EIGEN_WRAP_HPP

#include <Eigen/Dense>

// Matrix<ntype>: una matrice di Eigen con elementi di tipo ntype (float o double)
template <typename ntype>
using Matrix = Eigen::Matrix<ntype, Eigen::Dynamic, Eigen::Dynamic>;

#endif
