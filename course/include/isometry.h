/**
 * @file Vector.h
 * @author Gonzalo Cervetti (g.cervetti@creativa77.com)
 * @brief This Class provides implementation for vector operation.
 * @version 0.1
 * @date 2020-02-03
 *
 * @copyright Copyright (c) 2020
 *
 */

#pragma once

// Standard libraries
#include <math.h>
#include <initializer_list>
#include <iostream>
#include <sstream>
#include <string>

namespace ekumen {
namespace math {

class Vector3 {
   public:
    Vector3(const double& x, const double& y, const double& z);
    Vector3();
    /**
     * @brief Normalizes a function./
     *
     * @return double normalized value of the vector.
     */
    inline double norm() const { return sqrt(pow(x_, 2.0) + pow(y_, 2.0) + pow(z_, 2.0)); };
    inline double dot(Vector3 v) const { return ((x_ * v.x_) + (y_ * v.y_) + (z_ * v.z_)); };
    Vector3 cross(Vector3 v) const;

    // Getter for elements of the vector.
    const double& x() const { return x_; };
    const double& y() const { return y_; };
    const double& z() const { return z_; };

    double& x() { return x_; };
    double& y() { return y_; };
    double& z() { return z_; };

    // Operators overloading.
    inline Vector3 operator+(const Vector3& a) const { return Vector3(x_ + a.x_, y_ + a.y_, z_ + a.z_); };
    inline Vector3 operator-(const Vector3& a) const { return Vector3(x_ - a.x_, y_ - a.y_, z_ - a.z_); };
    inline Vector3 operator*(const double& a) const { return Vector3(x_ * a, y_ * a, z_ * a); };
    inline Vector3 operator/(const Vector3& a) const { return Vector3(x_ / a.x_, y_ / a.y_, z_ / a.z_); };
    const double& operator[](int val) const;
    double& operator[](int val);
    inline bool operator==(const Vector3& a);
    inline bool operator!=(const Vector3& a);

    // Static members
    static const Vector3 kUnitX;
    static const Vector3 kUnitY;
    static const Vector3 kUnitZ;
    static const Vector3 kZero;

   private:
    double x_, y_, z_;
};

// non-member binary operators

inline bool operator==(const Vector3& lhs, const std::initializer_list<double>& rhs) {
    int count = 0;
    for (auto it = rhs.begin(); it != rhs.end(); ++it, ++count) {
        if (lhs[count] != *it) return false;
    }
    return true;
}

inline bool operator==(const Vector3& lhs, const Vector3& rhs) {
    if ((lhs.x() == rhs.x()) && (lhs.y() == rhs.y()) && (lhs.z() == rhs.z())) return true;
    return false;
}

inline bool operator!=(const Vector3& lhs, const Vector3& rhs) {
    if ((lhs.x() == rhs.x()) && (lhs.y() == rhs.y()) && (lhs.z() == rhs.z())) return false;
    return true;
}

inline bool operator!=(const Vector3& lhs, const std::initializer_list<double>& rhs) {
    int count = 0;
    for (auto it = rhs.begin(); it != rhs.end(); ++it, ++count) {
        if (lhs[count] != *it) return true;
    }
    return false;
}

inline Vector3 operator*(const double scalar, const Vector3& vect) {
    Vector3 result(vect.x() * scalar, vect.y() * scalar, (vect.z() * scalar));
    return result;
}

inline Vector3 operator*(const Vector3& vect1, const Vector3& vect2) {
    return Vector3(vect1.x() * vect2.x(), vect1.y() * vect2.y(), vect1.z() * vect2.z());
}

inline std::ostream& operator<<(std::ostream& os, const Vector3& vect) {
    return os << "(x: " << std::to_string(static_cast<int>(vect.x()))
              << ", y: " << std::to_string(static_cast<int>(vect.y()))
              << ", z: " << std::to_string(static_cast<int>(vect.z())) << ")";
}

}  // namespace math
}  // namespace ekumen