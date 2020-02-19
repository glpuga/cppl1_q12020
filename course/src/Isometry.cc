/**
 * @file Isometry.cc
 * @author Gonzalo Cervetti (g.cervetti@creativa77.com)
 * @brief
 * @version 0.1
 * @date 2020-02-03
 *
 * @copyright Copyright (c) 2020
 *
 */

// Challenge libraries.
#include <Isometry.hpp>
#include <array>
#include <tuple>

namespace ekumen {
namespace math {

// Vector3
Vector3::Vector3(const double& x, const double& y, const double& z) : x_(x), y_(y), z_(z) {}

Vector3::Vector3() : Vector3(0.0, 0.0, 0.0) {}

Vector3 Vector3::cross(const Vector3& v) const {
    auto i = (y_ * v.z_) - (v.y_ * z_);
    auto j = (x_ * v.z_) - (v.x_ * z_);
    auto k = (x_ * v.y_) - (v.x_ * y_);

    return Vector3(i, j, k);
}

Vector3 Vector3::operator+(const Vector3& a) const { return Vector3(x_ + a.x_, y_ + a.y_, z_ + a.z_); }

Vector3 Vector3::operator-(const Vector3& a) const { return Vector3(x_ - a.x_, y_ - a.y_, z_ - a.z_); }

Vector3 Vector3::operator*(const double& a) const { return Vector3(x_ * a, y_ * a, z_ * a); }

Vector3 Vector3::operator*(const Vector3& vect) const { return Vector3(x_ * vect.x(), y_ * vect.y(), z_ * vect.z()); }

Vector3 Vector3::operator/(const Vector3& a) const { return Vector3(x_ / a.x_, y_ / a.y_, z_ / a.z_); }

const double& Vector3::operator[](int val) const {
    switch (val) {
        case 0:
            return x_;
        case 1:
            return y_;
        case 2:
            return z_;
        default:
            throw std::overflow_error("value too big");
    }
}

double& Vector3::operator[](int val) {
    switch (val) {
        case 0:
            return x_;
        case 1:
            return y_;
        case 2:
            return z_;
        default:
            throw std::overflow_error("value too big");
    }
}

bool Vector3::operator==(const std::initializer_list<double>& rhs) const {
    if (rhs.size() != 3) return false;
    auto it = rhs.begin();
    if (!almost_equal(x_, *it, resolution)) {
        return false;
    }
    ++it;
    if (!almost_equal(y_, *it, resolution)) {
        return false;
    }
    ++it;
    if (!almost_equal(z_, *it, resolution)) {
        return false;
    }
    return true;
}

bool Vector3::operator==(const Vector3& a) const {
    return (Vector3(x_, y_, z_) == std::initializer_list<double>({a.x_, a.y_, a.z_}));
}

bool Vector3::operator!=(const std::initializer_list<double>& rhs) const { return !(Vector3(x_, y_, z_) == rhs); }

bool Vector3::operator!=(const Vector3& a) const { return !(Vector3(x_, y_, z_) == a); }

const Vector3 Vector3::kUnitX(1.0, 0.0, 0.0);
const Vector3 Vector3::kUnitY(0.0, 1.0, 0.0);
const Vector3 Vector3::kUnitZ(0.0, 0.0, 1.0);
const Vector3 Vector3::kZero(0.0, 0.0, 0.0);

// Matrix3

Matrix3::Matrix3(const std::initializer_list<double>& row_1, const std::initializer_list<double>& row_2,
                 const std::initializer_list<double>& row_3) {
    mat_.resize(3);
    for (unsigned item = 0; item < 3; item++) {
        mat_[item].resize(3, 0);
    }
    if ((row_1.size() < 3) || (row_2.size() < 3) || (row_3.size() < 3)) {
        return;
    }
    auto it = row_1.begin();
    mat_[0][0] = *it;
    ++it;
    mat_[0][1] = *it;
    ++it;
    mat_[0][2] = *it;
    ++it;

    it = row_2.begin();
    mat_[1][0] = *it;
    ++it;
    mat_[1][1] = *it;
    ++it;
    mat_[1][2] = *it;
    ++it;

    it = row_3.begin();
    mat_[2][0] = *it;
    ++it;
    mat_[2][1] = *it;
    ++it;
    mat_[2][2] = *it;
    ++it;
}
Matrix3::Matrix3(const double m00, const double m01, const double m02, const double m10, const double m11,
                 const double m12, const double m20, const double m21, const double m22)
    : Matrix3{{m00, m01, m02}, {m10, m11, m12}, {m20, m21, m22}} {}

Matrix3::Matrix3() : Matrix3{{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}} {}

bool Matrix3::operator==(const Matrix3& a) const {
    for (auto x = 0; x < 3; ++x) {
        for (auto y = 0; y < 3; ++y) {
            if (!almost_equal(mat_[x][y], a[x][y], resolution)) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix3::operator==(const std::initializer_list<double>& rhs) const {
    if (rhs.size() < 9) {
        return false;
    }
    auto it = rhs.begin();
    for (auto x = 0; x < 3; ++x) {
        for (auto y = 0; y < 3; ++y) {
            if (!almost_equal(mat_[x][y], *it, resolution)) {
                return false;
            }
            ++it;
        }
    }
    return true;
}

Matrix3 Matrix3::operator+(const Matrix3& a) const {
    Matrix3 result;
    for (uint32_t x = 0; x < 3; ++x) {
        for (uint32_t y = 0; y < 3; ++y) {
            result[x][y] = mat_[x][y] + a.mat_[x][y];
        }
    }
    return result;
}

Matrix3 Matrix3::operator-(const Matrix3& a) const {
    Matrix3 result;
    for (uint32_t x = 0; x < 3; ++x) {
        for (uint32_t y = 0; y < 3; ++y) {
            result[x][y] = mat_[x][y] - a.mat_[x][y];
        }
    }
    return result;
}

Matrix3 Matrix3::operator*(const Matrix3& a) const {
    Matrix3 result;
    for (uint32_t x = 0; x < 3; ++x) {
        for (uint32_t y = 0; y < 3; ++y) {
            result[x][y] = a[x][y] * mat_[x][y];
        }
    }
    return result;
}

Matrix3 Matrix3::operator*(const double& a) const {
    Matrix3 result;
    for (uint32_t x = 0; x < 3; ++x) {
        for (uint32_t y = 0; y < 3; ++y) {
            result[x][y] = a * mat_[x][y];
        }
    }
    return result;
}

Matrix3 Matrix3::operator/(const Matrix3& a) const {
    Matrix3 result;
    for (uint32_t x = 0; x < 3; ++x) {
        for (uint32_t y = 0; y < 3; ++y) {
            result[x][y] = mat_[x][y] / a[x][y];
        }
    }
    return result;
}

const std::vector<double>& Matrix3::operator[](int val) const {
    if (val > 3) {
        return mat_[3];
    }
    return mat_[val];
}

std::vector<double>& Matrix3::operator[](int val) { return mat_[val]; }

double Matrix3::det() {
    return ((mat_[0][0] * mat_[1][1] * mat_[2][2]) + (mat_[0][1] * mat_[1][2] * mat_[2][0]) +
            (mat_[0][2] * mat_[1][0] * mat_[2][1]) - (mat_[0][2] * mat_[1][1] * mat_[2][0]) -
            (mat_[0][0] * mat_[1][2] * mat_[2][1]) - (mat_[0][1] * mat_[1][0] * mat_[2][2]));
}

Vector3 Matrix3::row(uint8_t row) const {
    if (row < 2) {
        return Vector3(mat_[row][0], mat_[row][1], mat_[row][2]);
    }
    return Vector3(mat_[2][0], mat_[2][1], mat_[2][2]);
}

Vector3 Matrix3::col(uint8_t col) const {
    if (col < 2) {
        return Vector3(mat_[0][col], mat_[1][col], mat_[2][col]);
    }
    return Vector3(mat_[0][2], mat_[1][2], mat_[2][2]);
}

const Matrix3 Matrix3::kIdentity({1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0});
const Matrix3 Matrix3::kZero({0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0});
const Matrix3 Matrix3::kOnes({1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0});

}  // namespace math
}  // namespace ekumen
