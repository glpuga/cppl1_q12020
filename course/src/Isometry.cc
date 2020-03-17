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
    if ((row_1.size() < 3) || (row_2.size() < 3) || (row_3.size() < 3)) {
        throw "Size of the matrix isn't correct";
    }
    auto it = row_1.begin();
    mat_[0][0] = *it++;
    mat_[0][1] = *it++;
    mat_[0][2] = *it++;

    it = row_2.begin();
    mat_[1][0] = *it++;
    mat_[1][1] = *it++;
    mat_[1][2] = *it++;

    it = row_3.begin();
    mat_[2][0] = *it++;
    mat_[2][1] = *it++;
    mat_[2][2] = *it++;
}
Matrix3::Matrix3(const double m00, const double m01, const double m02, const double m10, const double m11,
                 const double m12, const double m20, const double m21, const double m22)
    : Matrix3{{m00, m01, m02}, {m10, m11, m12}, {m20, m21, m22}} {}

Matrix3::Matrix3() : Matrix3{{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}} {}

Matrix3::Matrix3(const Matrix3& mat)
    : Matrix3{mat[0][0], mat[0][1], mat[0][2], mat[1][0], mat[1][1], mat[1][2], mat[2][0], mat[2][1], mat[2][2]} {}

Matrix3::Matrix3(Matrix3&& mat)
    : Matrix3{mat[0][0], mat[0][1], mat[0][2], mat[1][0], mat[1][1], mat[1][2], mat[2][0], mat[2][1], mat[2][2]} {}

Matrix3& Matrix3::operator=(Matrix3&& mat) {
    mat_ = std::move(mat.mat_);
    return *this;
}

Matrix3& Matrix3::operator=(const Matrix3& mat) {
    // check for self-assignment
    if (&mat == this) return *this;
    // reuse storage when possible
    mat_ = mat.mat_;
    return *this;
}

bool Matrix3::operator==(const Matrix3& a) const {
    for (auto idx = 0; idx < 3; ++idx) {
        if (mat_[idx] != a[idx]) {
            return false;
        }
    }
    return true;
}

bool Matrix3::operator==(const std::initializer_list<double>& rhs) const {
    if (rhs.size() < 9) {
        return false;
    }
    auto it = rhs.begin();

    for (auto idx = 0; idx < 3; ++idx) {
        if (mat_[idx] != std::initializer_list<double>({*it++, *it++, *it++})) {
            return false;
        }
    }
    return true;
}

Matrix3 Matrix3::operator+(const Matrix3& a) const {
    Matrix3 result;
    for (auto idx = 0; idx < 3; ++idx) {
        result[idx] = mat_[idx] + a.mat_[idx];
    }
    return result;
}

Matrix3 Matrix3::operator-(const Matrix3& a) const {
    Matrix3 result;
    for (auto idx = 0; idx < 3; ++idx) {
        result[idx] = mat_[idx] - a.mat_[idx];
    }
    return result;
}

Matrix3 Matrix3::operator*(const Matrix3& a) const {
    Matrix3 result;
    for (auto idx = 0; idx < 3; ++idx) {
        result[idx] = mat_[idx] * a.mat_[idx];
    }
    return result;
}

Matrix3 Matrix3::operator*(const double& a) const {
    Matrix3 result;
    for (auto idx = 0; idx < 3; ++idx) {
        result[idx] = mat_[idx] * a;
    }
    return result;
}

Matrix3 Matrix3::operator/(const Matrix3& a) const {
    Matrix3 result;
    for (auto idx = 0; idx < 3; ++idx) {
        result[idx] = mat_[idx] / a.mat_[idx];
    }
    return result;
}

const Vector3& Matrix3::operator[](int val) const {
    if (val > 2) {
        return mat_[2];
    }
    return mat_[val];
}

Vector3& Matrix3::operator[](int val) {
    if (val > 2) {
        return mat_[2];
    }
    return mat_[val];
}

double Matrix3::det() const {
    return ((mat_[0][0] * mat_[1][1] * mat_[2][2]) + (mat_[0][1] * mat_[1][2] * mat_[2][0]) +
            (mat_[0][2] * mat_[1][0] * mat_[2][1]) - (mat_[0][2] * mat_[1][1] * mat_[2][0]) -
            (mat_[0][0] * mat_[1][2] * mat_[2][1]) - (mat_[0][1] * mat_[1][0] * mat_[2][2]));
}

Vector3 Matrix3::row(uint8_t row) const {
    if (row < 2) {
        return mat_[row];
    }
    return mat_[2];
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

Isometry::Isometry(const Vector3& vect) {
    mat_.emplace_back(vect);
    row_ = 1;
    column_ = 3;
}

Isometry::Isometry(const Matrix3& vect) {
    mat_.emplace_back(vect[0]);
    mat_.emplace_back(vect[1]);
    mat_.emplace_back(vect[2]);
    row_ = 3;
    column_ = 3;
}

Isometry::Isometry(const Vector3& vect, const Matrix3& mat) {
    Vector3 result;
    result[0] = mat[0][0] * vect[0] + mat[0][1] * vect[1] + mat[0][2] * vect[2];
    result[1] = mat[1][0] * vect[0] + mat[1][1] * vect[1] + mat[1][2] * vect[2];
    result[2] = mat[2][0] * vect[0] + mat[2][1] * vect[1] + mat[2][2] * vect[2];
    mat_.emplace_back(result);
    row_ = 1;
    column_ = 3;
}

Isometry::Isometry(std::vector<Vector3> mat) {
    for (auto vector : mat) {
        mat_.emplace_back(vector);
    }
    column_ = 3;
    row_ = mat.size();
}

Isometry Isometry::compose(const Isometry& isometry) const { return (*this * isometry); }

Isometry Isometry::inverse() const {
    std::vector<Vector3> vector;
    for (uint8_t count = 0; count < column_; ++count) {
        vector.push_back(Vector3(-mat_[count][0], -mat_[count][1], -mat_[count][2]));
    }
    return Isometry(vector);
}

Isometry Isometry::rotation() const { return mat_; }

Vector3 Isometry::transform(std::initializer_list<double> values) const {
    if (values.size() < 3) {
        return Vector3(0.0, 0.0, 0.0);
    }
    auto it = values.begin();
    Vector3 result;
    result[0] = mat_[0][0] + *it++;
    result[1] = mat_[0][1] + *it++;
    result[2] = mat_[0][2] + *it++;
    return result;
}

Vector3 Isometry::translation() const { return translation_; }

const Isometry Isometry::FromTranslation(const std::initializer_list<double>& values) {
    if (values.size() != 3) {
        return Isometry(Vector3::kZero, Matrix3::kZero);
    }
    auto it = values.begin();
    Vector3 vector;
    vector[0] = *it++;
    vector[1] = *it++;
    vector[2] = *it++;
    return Isometry(vector);
}

const Isometry Isometry::FromEulerAngles(double yaw, double pitch, double roll) {
    Isometry result = Isometry(RotateAround(Vector3::kUnitX, yaw)) * Isometry(RotateAround(Vector3::kUnitY, pitch)) *
                      Isometry(RotateAround(Vector3::kUnitZ, roll));
    return result;
}

const Isometry Isometry::RotateAround(const Vector3& axis, double angle) {
    if (axis == Vector3::kUnitX) {
        Matrix3 Rx(1.0, 0.0, 0.0, 0.0, cos(angle), -sin(angle), 0.0, sin(angle), cos(angle));
        return Rx;
    } else if (axis == Vector3::kUnitY) {
        Matrix3 Ry(cos(angle), 0.0, sin(angle), 0.0, 1.0, 0.0, -sin(angle), 0.0, cos(angle));
        return Ry;
    } else if (axis == Vector3::kUnitZ) {
        Matrix3 Rz(cos(angle), -sin(angle), 0.0, sin(angle), cos(angle), 0.0, 0.0, 0.0, 1.0);
        return Rz;
    }
    return Matrix3::kIdentity;
}

bool Isometry::operator==(const Isometry& rhs) const {
    if (mat_ == rhs.mat_) {
        return true;
    }
    return false;
}

bool Isometry::operator==(const Vector3& rhs) const {
    if (row_ != 1 && column_ != 3) return false;
    if (mat_[0] == rhs) {
        return true;
    }
    return false;
}

Vector3 Isometry::operator*(const Vector3& rhs) const {
    Vector3 result;
    result[0] = mat_[0][0] + rhs[0];
    result[1] = mat_[0][1] + rhs[1];
    result[2] = mat_[0][2] + rhs[2];
    return result;
}

Isometry Isometry::operator*(const Isometry& rhs) const {
    if ((row_ != rhs.row_) && (column_ != rhs.column_)) {
        return Vector3::kUnitX;
    }
    std::vector<Vector3> result;
    result.resize(row_);
    for (uint32_t row = 0; row < row_; ++row) {
        for (uint32_t column = 0; column < column_; ++column) {
            result[row][column] = rhs.mat_[row][column] + mat_[row][column];
        }
    }
    return Isometry(result);
}

}  // namespace math
}  // namespace ekumen
