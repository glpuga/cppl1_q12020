/* Copyright [2021] <Ekumen>
 * Matrix Algebra
 * Author: Gerardo Puga
 */

// Standard library
#include <iostream>

#include "gtest/gtest.h"

// Project headers
#include <algebra/algebra.hpp>

namespace ekumen {
namespace math {
namespace test {
namespace {

using ::testing::Test;

class MatrixAlgebraTests : public Test {
 public:
  const double tolerance_{1e-3};

  bool isNear(const Matrix &lhs, const Matrix &rhs) const {
    if (lhs.nrows() != rhs.nrows()) {
      return false;
    }
    if (lhs.ncols() != rhs.ncols()) {
      return false;
    }
    for (size_t row = 0; row < lhs.nrows(); ++row) {
      for (size_t col = 0; col < lhs.ncols(); ++col) {
        double error = std::abs(lhs.elem(row, col) - rhs.elem(row, col));
        if (error > tolerance_) {
          return false;
        }
      }
    }
    return true;
  }
};

TEST_F(MatrixAlgebraTests, DefaultConstructor) {
  const auto uut = Matrix{};
  EXPECT_EQ(0U, uut.nrows());
  EXPECT_EQ(0U, uut.ncols());
}

TEST_F(MatrixAlgebraTests, IdentityBuilder1) {
  const auto uut = Matrix::Identity(1);
  EXPECT_EQ(1U, uut.nrows());
  EXPECT_EQ(1U, uut.ncols());
  EXPECT_NEAR(uut.elem(0, 0), 1.0, tolerance_);
}

TEST_F(MatrixAlgebraTests, IdentityBuilder2) {
  const auto uut = Matrix::Identity(2);
  EXPECT_EQ(2U, uut.nrows());
  EXPECT_EQ(2U, uut.ncols());
  EXPECT_NEAR(uut.elem(0, 0), 1.0, tolerance_);
  EXPECT_NEAR(uut.elem(0, 1), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 0), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 1), 1.0, tolerance_);
}

TEST_F(MatrixAlgebraTests, IdentityBuilder3) {
  const auto uut = Matrix::Identity(3);
  EXPECT_EQ(3U, uut.nrows());
  EXPECT_EQ(3U, uut.ncols());
  EXPECT_NEAR(uut.elem(0, 0), 1.0, tolerance_);
  EXPECT_NEAR(uut.elem(0, 1), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(0, 2), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 0), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 1), 1.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 2), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(2, 0), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(2, 1), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(2, 2), 1.0, tolerance_);
}

TEST_F(MatrixAlgebraTests, ZeroBuilder1) {
  const auto uut = Matrix::Zero(1);
  EXPECT_EQ(1U, uut.nrows());
  EXPECT_EQ(1U, uut.ncols());
  EXPECT_NEAR(uut.elem(0, 0), 0.0, tolerance_);
}

TEST_F(MatrixAlgebraTests, ZeroBuilder2) {
  const auto uut = Matrix::Zero(2);
  EXPECT_EQ(2U, uut.nrows());
  EXPECT_EQ(2U, uut.ncols());
  EXPECT_NEAR(uut.elem(0, 0), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(0, 1), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 0), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 1), 0.0, tolerance_);
}

TEST_F(MatrixAlgebraTests, ZeroBuilder3) {
  const auto uut = Matrix::Zero(3);
  EXPECT_EQ(3U, uut.nrows());
  EXPECT_EQ(3U, uut.ncols());
  EXPECT_NEAR(uut.elem(0, 0), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(0, 1), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(0, 2), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 0), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 1), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 2), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(2, 0), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(2, 1), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(2, 2), 0.0, tolerance_);
}

TEST_F(MatrixAlgebraTests, DefaultSquareMatrix) {
  const auto uut = Matrix(3, 3);
  EXPECT_EQ(3U, uut.nrows());
  EXPECT_EQ(3U, uut.ncols());
  EXPECT_TRUE(isNear(Matrix::Zero(3), uut));
}

TEST_F(MatrixAlgebraTests, DefaultHighRectangularMatrix) {
  const auto uut = Matrix(3, 2);
  EXPECT_EQ(3U, uut.nrows());
  EXPECT_EQ(2U, uut.ncols());
  EXPECT_NEAR(uut.elem(0, 0), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(0, 1), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 0), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 1), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(2, 0), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(2, 1), 0.0, tolerance_);
}

TEST_F(MatrixAlgebraTests, DefaultWideRectangularMatrix) {
  const auto uut = Matrix(2, 3);
  EXPECT_EQ(2U, uut.nrows());
  EXPECT_EQ(3U, uut.ncols());
  EXPECT_NEAR(uut.elem(0, 0), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(0, 1), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(0, 2), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 0), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 1), 0.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 2), 0.0, tolerance_);
}

TEST_F(MatrixAlgebraTests, InitializedSquareMatrix) {
  const auto uut = Matrix(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  EXPECT_EQ(3U, uut.nrows());
  EXPECT_EQ(3U, uut.ncols());
  EXPECT_NEAR(uut.elem(0, 0), 1.0, tolerance_);
  EXPECT_NEAR(uut.elem(0, 1), 2.0, tolerance_);
  EXPECT_NEAR(uut.elem(0, 2), 3.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 0), 4.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 1), 5.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 2), 6.0, tolerance_);
  EXPECT_NEAR(uut.elem(2, 0), 7.0, tolerance_);
  EXPECT_NEAR(uut.elem(2, 1), 8.0, tolerance_);
  EXPECT_NEAR(uut.elem(2, 2), 9.0, tolerance_);
}

TEST_F(MatrixAlgebraTests, InitializedHighRectangularMatrix) {
  const auto uut = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  EXPECT_EQ(3U, uut.nrows());
  EXPECT_EQ(2U, uut.ncols());
  EXPECT_NEAR(uut.elem(0, 0), 1.0, tolerance_);
  EXPECT_NEAR(uut.elem(0, 1), 2.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 0), 3.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 1), 4.0, tolerance_);
  EXPECT_NEAR(uut.elem(2, 0), 5.0, tolerance_);
  EXPECT_NEAR(uut.elem(2, 1), 6.0, tolerance_);
}

TEST_F(MatrixAlgebraTests, InitializedWideRectangularMatrix) {
  const auto uut = Matrix(2, 3, {1, 2, 3, 4, 5, 6});
  EXPECT_EQ(2U, uut.nrows());
  EXPECT_EQ(3U, uut.ncols());
  EXPECT_NEAR(uut.elem(0, 0), 1.0, tolerance_);
  EXPECT_NEAR(uut.elem(0, 1), 2.0, tolerance_);
  EXPECT_NEAR(uut.elem(0, 2), 3.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 0), 4.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 1), 5.0, tolerance_);
  EXPECT_NEAR(uut.elem(1, 2), 6.0, tolerance_);
}

TEST_F(MatrixAlgebraTests, WriteMatrixElements) {
  auto uut = Matrix(3, 2);
  EXPECT_EQ(3U, uut.nrows());
  EXPECT_EQ(2U, uut.ncols());
  uut.elem(0, 0) = 77;
  uut.elem(2, 1) = 88;
  EXPECT_NEAR(uut.elem(0, 0), 77.0, tolerance_);
  EXPECT_NEAR(uut.elem(2, 1), 88.0, tolerance_);
}

TEST_F(MatrixAlgebraTests, MismatchedConstructorArguments) {
  EXPECT_THROW({ auto uut = Matrix(3, 2, {1, 2, 3, 4, 5, 6, 7, 8, 9}); }, std::invalid_argument);
  EXPECT_THROW({ auto uut = Matrix(3, 4, {1, 2, 3, 4, 5, 6, 7, 8, 9}); }, std::invalid_argument);
}

TEST_F(MatrixAlgebraTests, InvalidRowColValuesConst) {
  const auto uut = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  EXPECT_THROW(uut.elem(3, 0), std::invalid_argument);
  EXPECT_THROW(uut.elem(0, 2), std::invalid_argument);
  EXPECT_THROW(uut.elem(-1, 0), std::invalid_argument);
  EXPECT_THROW(uut.elem(0, -1), std::invalid_argument);
}

TEST_F(MatrixAlgebraTests, InvalidRowColValuesNonConst) {
  auto uut = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  EXPECT_THROW(uut.elem(3, 0), std::invalid_argument);
  EXPECT_THROW(uut.elem(0, 2), std::invalid_argument);
  EXPECT_THROW(uut.elem(-1, 0), std::invalid_argument);
  EXPECT_THROW(uut.elem(0, -1), std::invalid_argument);
}

TEST_F(MatrixAlgebraTests, HighRectangularTranspose) {
  const auto uut = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  const auto expected = Matrix(2, 3, {1, 3, 5, 2, 4, 6});
  EXPECT_TRUE(isNear(expected, uut.trans()));
}

TEST_F(MatrixAlgebraTests, WideRectangularTranspose) {
  const auto uut = Matrix(2, 3, {1, 3, 5, 2, 4, 6});
  const auto expected = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  EXPECT_TRUE(isNear(expected, uut.trans()));
}

TEST_F(MatrixAlgebraTests, SquareTranspose) {
  const auto uut = Matrix(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
  const auto expected = Matrix(3, 3, {1, 4, 7, 2, 5, 8, 3, 6, 9});
  EXPECT_TRUE(isNear(expected, uut.trans()));
}

TEST_F(MatrixAlgebraTests, ValidAddition) {
  const auto op1 = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  const auto op2 = Matrix(3, 2, {11, 12, 13, 14, 15, 16});
  const auto expected = Matrix(3, 2, {12, 14, 16, 18, 20, 22});
  Matrix result;
  EXPECT_NO_THROW({ result = op1 + op2; });
  EXPECT_TRUE(isNear(expected, result));
}

TEST_F(MatrixAlgebraTests, MismatchedAddition) {
  const auto op1 = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  const auto op2 = Matrix(2, 3, {11, 12, 13, 14, 15, 16});
  Matrix result;
  EXPECT_THROW({ result = op1 + op2; }, std::invalid_argument);
}

TEST_F(MatrixAlgebraTests, ValidAssignAddition) {
  const auto op1 = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  auto result = Matrix(3, 2, {11, 12, 13, 14, 15, 16});
  const auto expected = Matrix(3, 2, {12, 14, 16, 18, 20, 22});
  EXPECT_NO_THROW({ result += op1; });
  EXPECT_TRUE(isNear(expected, result));
}

TEST_F(MatrixAlgebraTests, MismatchedAssignAddition) {
  auto result = Matrix(2, 3, {11, 12, 13, 14, 15, 16});
  const auto op = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  EXPECT_THROW({ result += op; }, std::invalid_argument);
}

TEST_F(MatrixAlgebraTests, ValidSubtraction) {
  const auto op1 = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  const auto op2 = Matrix(3, 2, {11, 12, 13, 14, 15, 16});
  const auto expected = Matrix(3, 2, {-10, -10, -10, -10, -10, -10});
  Matrix result;
  EXPECT_NO_THROW({ result = op1 - op2; });
  EXPECT_TRUE(isNear(expected, result));
}

TEST_F(MatrixAlgebraTests, MismatchedSubtraction) {
  const auto op1 = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  const auto op2 = Matrix(2, 3, {11, 12, 13, 14, 15, 16});
  Matrix result;
  EXPECT_THROW(result = op1 - op2, std::invalid_argument);
}

TEST_F(MatrixAlgebraTests, ValidAssignSubtraction) {
  auto result = Matrix(3, 2, {11, 12, 13, 14, 15, 16});
  const auto op = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  const auto expected = Matrix(3, 2, {10, 10, 10, 10, 10, 10});
  EXPECT_NO_THROW({ result -= op; });
  EXPECT_TRUE(isNear(expected, result));
}

TEST_F(MatrixAlgebraTests, MismatchedAssignSubtraction) {
  auto result = Matrix(2, 3, {11, 12, 13, 14, 15, 16});
  const auto op = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  EXPECT_THROW({ result -= op; }, std::invalid_argument);
}

TEST_F(MatrixAlgebraTests, ValidProduct) {
  const auto op1 = Matrix(2, 3, {1, 2, 3, 4, 5, 6});
  const auto op2 = Matrix::Identity(3);
  const auto op3 = Matrix(3, 2, {-1, 2, -3, 4, -5, 6});
  const auto expected = Matrix(2, 2, {-22, 28, -49, 64});
  Matrix result;
  EXPECT_NO_THROW({ result = op1 * op2 * op3; });
  EXPECT_TRUE(isNear(expected, result));
}

TEST_F(MatrixAlgebraTests, MismatchedProduct) {
  const auto op1 = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  const auto op2 = Matrix(3, 2, {11, 12, 13, 14, 15, 16});
  Matrix result;
  EXPECT_THROW(result = op1 * op2, std::invalid_argument);
}

TEST_F(MatrixAlgebraTests, ValidAssignProduct) {
  auto result = Matrix(2, 3, {1, 2, 3, 4, 5, 6});
  const auto op2 = Matrix(3, 2, {-1, 2, -3, 4, -5, 6});
  const auto expected = Matrix(2, 2, {-22, 28, -49, 64});
  EXPECT_NO_THROW({ result *= op2; });
  EXPECT_TRUE(isNear(expected, result));
}

TEST_F(MatrixAlgebraTests, MismatchedAssignProduct) {
  auto result = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  const auto op2 = Matrix(3, 2, {11, 12, 13, 14, 15, 16});
  EXPECT_THROW({ result *= op2; }, std::invalid_argument);
}

TEST_F(MatrixAlgebraTests, ScalarAddition) {
  const auto op = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  const auto sc = 2.0;
  const auto expected = Matrix(3, 2, {3, 4, 5, 6, 7, 8});
  const Matrix result0 = op + sc;
  const Matrix result1 = sc + op;
  Matrix result2{op};
  result2 += sc;
  EXPECT_TRUE(isNear(expected, result0));
  EXPECT_TRUE(isNear(expected, result1));
  EXPECT_TRUE(isNear(expected, result2));
}

TEST_F(MatrixAlgebraTests, ScalarSubtraction) {
  const auto op = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  const auto sc = 2.0;
  const auto expected = Matrix(3, 2, {-1, 0, 1, 2, 3, 4});
  const Matrix result0 = op - sc;
  const Matrix result1 = (sc - op) * (-1);
  Matrix result2{op};
  result2 -= sc;
  EXPECT_TRUE(isNear(expected, result0));
  EXPECT_TRUE(isNear(expected, result1));
  EXPECT_TRUE(isNear(expected, result2));
}

TEST_F(MatrixAlgebraTests, ScalarProduct) {
  const auto op = Matrix(2, 3, {1, 2, 3, 4, 5, 6});
  const auto sc = 2.0;
  const auto expected = Matrix(2, 3, {2, 4, 6, 8, 10, 12});
  const Matrix result0 = op * sc;
  const Matrix result1 = sc * op;
  Matrix result2{op};
  result2 *= sc;
  EXPECT_TRUE(isNear(expected, result0));
  EXPECT_TRUE(isNear(expected, result1));
  EXPECT_TRUE(isNear(expected, result2));
}

TEST_F(MatrixAlgebraTests, SquareMatrixDeterminant1x1) {
  const auto uut = Matrix(1, 1, {9});
  double result;
  uut.det();
  EXPECT_NO_THROW(result = uut.det());
  EXPECT_NEAR(9.0, result, tolerance_);
}

TEST_F(MatrixAlgebraTests, SquareMatrixDeterminant2x2) {
  const auto uut = Matrix(2, 2, {1, 2, 3, 4});
  double result;
  uut.det();
  EXPECT_NO_THROW(result = uut.det());
  EXPECT_NEAR(-2.0, result, tolerance_);
}

TEST_F(MatrixAlgebraTests, SquareMatrixDeterminant3x3a) {
  const auto uut = Matrix(3, 3, {1, 2, 3, 0, 2, 6, 0, 0, 3});
  double result;
  uut.det();
  EXPECT_NO_THROW(result = uut.det());
  EXPECT_NEAR(6.0, result, tolerance_);
}

TEST_F(MatrixAlgebraTests, SquareMatrixDeterminant3x3b) {
  const auto uut = Matrix(3, 3, {1, 2, 3, 4, 1, 6, 7, 8, 1});
  double result;
  uut.det();
  EXPECT_NO_THROW(result = uut.det());
  EXPECT_NEAR(104.0, result, tolerance_);
}

TEST_F(MatrixAlgebraTests, RectangularMatrixDeterminant) {
  const auto uut = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  EXPECT_THROW(uut.det(), std::invalid_argument);
}

TEST_F(MatrixAlgebraTests, SquareMatrixInverse) {
  const auto uut = Matrix(3, 3, {1, 2, 3, 4, 1, 6, 7, 8, 1});
  const auto inv = uut.inv();
  const auto result = uut * inv;
  EXPECT_TRUE(isNear(Matrix::Identity(3), result));
}

TEST_F(MatrixAlgebraTests, RectangularMatrixInverse) {
  const auto uut = Matrix(3, 2, {1, 2, 3, 4, 5, 6});
  EXPECT_THROW(uut.inv(), std::invalid_argument);
}

}  // namespace
}  // namespace test
}  // namespace math
}  // namespace ekumen
