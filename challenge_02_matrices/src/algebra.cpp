/* Copyright [2021] <Ekumen>
 * Matrix Algebra
 * Author: Gerardo Puga
 */

#include <algebra/algebra.hpp>
#include <algorithm>

namespace ekumen {
namespace math {

Matrix::Matrix() = default;

Matrix::Matrix(const size_t rows, const size_t cols) : nrows_{rows}, ncols_{cols}, values_(rows * cols, 0.0) {}

Matrix::Matrix(const size_t rows, const size_t cols, std::initializer_list<double> values)
    : nrows_{rows}, ncols_{cols} {
  const auto size = rows * cols;
  if (size != values.size()) {
    throw std::invalid_argument{"Initializer les does not match matrix size"};
  }
  size_t i = 0;
  values_.resize(size);
  for (auto v : values) {
    values_[i++] = v;
  }
}

size_t Matrix::nrows() const { return nrows_; }
size_t Matrix::ncols() const { return ncols_; }

double Matrix::elem(const size_t row, const size_t col) const {
  if ((row >= nrows_) || (col >= ncols_)) {
    throw std::invalid_argument("Invalid row/col pair");
  }
  return values_[row * ncols_ + col];
}

double &Matrix::elem(const size_t row, const size_t col) {
  if ((row >= nrows_) || (col >= ncols_)) {
    throw std::invalid_argument("Invalid row/col pair");
  }
  return values_[row * ncols_ + col];
}

Matrix Matrix::operator+(const Matrix &rhs) const {
  Matrix result{*this};
  result += rhs;
  return result;
}

Matrix Matrix::operator-(const Matrix &rhs) const {
  Matrix result{*this};
  result -= rhs;
  return result;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
  Matrix result{*this};
  result *= rhs;
  return result;
}

Matrix Matrix::operator+(const double rhs) const {
  Matrix result{*this};
  result += rhs;
  return result;
}

Matrix Matrix::operator-(const double rhs) const {
  Matrix result{*this};
  result -= rhs;
  return result;
}

Matrix Matrix::operator*(const double rhs) const {
  Matrix result{*this};
  result *= rhs;
  return result;
}

Matrix &Matrix::operator+=(const Matrix &rhs) {
  if ((nrows_ != rhs.nrows()) || (ncols_ != rhs.ncols())) {
    throw std::invalid_argument("Operand sizes don't match for addition");
  }
  for (size_t i = 0; i < values_.size(); ++i) {
    values_[i] += rhs.values_[i];
  }
  return *this;
}

Matrix &Matrix::operator-=(const Matrix &rhs) {
  if ((nrows_ != rhs.nrows()) || (ncols_ != rhs.ncols())) {
    throw std::invalid_argument("Operand sizes don't match for subtraction");
  }
  for (size_t i = 0; i < values_.size(); ++i) {
    values_[i] -= rhs.values_[i];
  }
  return *this;
}

Matrix &Matrix::operator*=(const Matrix &rhs) {
  if (ncols_ != rhs.nrows()) {
    throw std::invalid_argument("Operand sizes don't match for product");
  }
  Matrix result{nrows_, rhs.ncols()};
  for (size_t row = 0; row < nrows_; ++row) {
    for (size_t col = 0; col < rhs.ncols(); ++col) {
      result.elem(row, col) = 0.0;
      for (size_t i = 0; i < ncols_; ++i) {
        result.elem(row, col) += elem(row, i) * rhs.elem(i, col);
      }
    }
  }
  *this = result;
  return *this;
}

Matrix Matrix::operator+=(const double rhs) {
  std::for_each(values_.begin(), values_.end(), [rhs](double &v) { v += rhs; });
  return *this;
}

Matrix Matrix::operator-=(const double rhs) {
  std::for_each(values_.begin(), values_.end(), [rhs](double &v) { v -= rhs; });
  return *this;
}

Matrix Matrix::operator*=(const double rhs) {
  std::for_each(values_.begin(), values_.end(), [rhs](double &v) { v *= rhs; });
  return *this;
}

double Matrix::det() const {
  if (nrows_ != ncols_) {
    throw std::invalid_argument("The determinat of a matrix is only defined for square matrices");
  }
  if (nrows_ == 1U) {
    return elem(0, 0);
  }
  if (nrows_ == 2U) {
    return (elem(0, 0) * elem(1, 1)) - (elem(0, 1) * elem(1, 0));
  }
  // recursively calculate other cases
  double determinant{0.0};
  for (size_t col = 0; col < ncols_; ++col) {
    determinant += elem(0, col) * cminor(0, col) * ((col % 2 == 0) ? 1.0 : -1.0);
  }
  return determinant;
}

Matrix Matrix::inv() const {
  if (nrows_ != ncols_) {
    throw std::invalid_argument("The inv of a matrix is only defined for square matrices");
  }
  if (nrows_ == 1U) {
    return Matrix{1, 1, {1.0 / elem(0, 0)}};
  }
  // Get the cofactor matrix
  Matrix cofactor{nrows_, ncols_};
  for (size_t row = 0; row < nrows_; ++row) {
    for (size_t col = 0; col < ncols_; ++col) {
      cofactor.elem(row, col) = cminor(row, col) * (((row + col) % 2 == 0) ? 1.0 : -1.0);
    }
  }
  // Get the determinant
  auto determinant{det()};
  // the inv is the cofactor transposed and divided by determinant.
  return cofactor.trans() * (1.0 / determinant);
}

Matrix Matrix::trans() const {
  Matrix result{ncols_, nrows_};
  for (size_t row = 0; row < nrows_; ++row) {
    for (size_t col = 0; col < ncols_; ++col) {
      result.elem(col, row) = elem(row, col);
    }
  }
  return result;
}

double Matrix::cminor(size_t row, size_t col) const {
  if (nrows_ != ncols_) {
    throw std::invalid_argument("The cminor of a matrix cell is only defined for square matrices");
  }
  if (nrows_ == 1U) {
    return 1.0;
  }
  Matrix minor_matrix{nrows_ - 1, ncols_ - 1};
  for (size_t minor_row = 0; minor_row < minor_matrix.nrows(); ++minor_row) {
    for (size_t minor_col = 0; minor_col < minor_matrix.ncols(); ++minor_col) {
      auto large_matrix_row = minor_row + ((minor_row >= row) ? 1 : 0);
      auto large_matrix_col = minor_col + ((minor_col >= col) ? 1 : 0);
      minor_matrix.elem(minor_row, minor_col) = elem(large_matrix_row, large_matrix_col);
    }
  }
  return minor_matrix.det();
}

Matrix Matrix::Identity(const size_t nrows) {
  auto identity = Matrix::Zero(nrows);
  for (size_t i = 0; i < nrows; ++i) {
    identity.elem(i, i) = 1.0;
  }
  return identity;
}

Matrix Matrix::Zero(const size_t nrows) { return Matrix(nrows, nrows); }

}  // namespace math
}  // namespace ekumen
