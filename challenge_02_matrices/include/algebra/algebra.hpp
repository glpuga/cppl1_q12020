/* Copyright [2021] <Ekumen>
 * Matrix Algebra
 * Author: Gerardo Puga
 */

#pragma once

#include <initializer_list>
#include <stdexcept>
#include <vector>

namespace ekumen {

namespace math {

class Matrix {
 public:
  /* \brief Identity - Static method to create an NxN identity matrix.
   * \param nrows Matrix rank.
   * \return Matrix object with 1s on the main diagonal */
  static Matrix Identity(const size_t nrows);

  /* \brief Zero - Static method to create an NxN zero matrix.
   * \param nrows Matrix rank.
   * \return Matrix object with only zeroes */
  static Matrix Zero(const size_t nrows);

  /* \brief Default constructor. Builds a null matrix (rank zero) */
  Matrix();

  /* \brief Constructor. Creates a matrix of a given size, filled with 0s.
   * \param nrows height of the matrix.
   * \param ncols width of the matrix. */
  Matrix(const size_t nrows, const size_t ncols);

  /* \brief Constructor. Creates a matrix of a given size, preinitialized with values.
   * \param nrows height of the matrix.
   * \param ncols width of the matrix.
   * \param values List of nrows*ncols elements use to initialize the matrix in
   *        row-first order.
   * \throw std::invalid_argument if the initialization list length does not match the
   *        matrix size.*/
  Matrix(const size_t nrows, const size_t ncols, std::initializer_list<double> values);

  /* \brief Returns the height of the matrix.
   * \return Matrix height */
  size_t nrows() const;

  /* \brief Returns the width of the matrix.
   * \return Matrix width */
  size_t ncols() const;

  /* \brief Accessor method to access the element at position (row, col).
   * \return Copy or reference to the element, depending on constness of this.
   * \throw std::invalid_argument if the coordinates are invalid. */
  double elem(const size_t row, const size_t col) const;
  double &elem(const size_t row, const size_t col);

  /* \brief Determinant of the matrix.
   * \return Calculated determinant value of the matrix.
   * \throw std::invalid_argument if the matrix is not square. */
  double det() const;

  /* \brief Inverse of the matrix.
   * \return Matrix object containing the inverse of the matrix.
   * \throw std::invalid_argument if the matrix is not invertible. */
  Matrix inv() const;

  /* \brief Matrix transpose.
   * \return Matrix object containing the transpose of the matrix. */
  Matrix trans() const;

  /* \brief Minor matrix for cell (row, col).
   * \return Matrix object containing the minor matrix calculated for cell (row, col).
   * \throw std::invalid_argument if the minor matrix is not square or the coordinates
   *        are invalid.*/
  double cminor(size_t row, size_t col) const;

  /* Operation overloads shall allow:
   * - Matrix op Matrix for addition, subtraction and product.
   * - Matrix op Double for addition, subtraction and product.
   * - Double op Matrix for addition, subtraction and product. */

  Matrix operator+(const Matrix &rhs) const;
  Matrix operator-(const Matrix &rhs) const;
  Matrix operator*(const Matrix &rhs) const;

  Matrix operator+(const double rhs) const;
  Matrix operator-(const double rhs) const;
  Matrix operator*(const double rhs) const;

  Matrix &operator+=(const Matrix &rhs);
  Matrix &operator-=(const Matrix &rhs);
  Matrix &operator*=(const Matrix &rhs);

  Matrix operator+=(const double rhs);
  Matrix operator-=(const double rhs);
  Matrix operator*=(const double rhs);

 private:
  size_t nrows_{0};
  size_t ncols_{0};
  std::vector<double> values_;
};

inline Matrix operator+(const double lhs, const Matrix &rhs) { return rhs + lhs; }

inline Matrix operator-(const double lhs, const Matrix &rhs) { return (rhs - lhs) * (-1); }

inline Matrix operator*(const double lhs, const Matrix &rhs) { return rhs * lhs; }

}  // namespace math

}  // namespace ekumen
