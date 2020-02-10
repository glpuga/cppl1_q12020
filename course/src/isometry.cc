/**
 * @file Vector.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2020-02-03
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <isometry.h>

namespace ekumen {
namespace math {
Vector3::Vector3(const double &x, const double &y, const double &z) : x_(x), y_(y), z_(z) {}

Vector3::Vector3() {
    x_ = kZero.x_;
    y_ = kZero.y_;
    z_ = kZero.z_;
}

Vector3 Vector3::cross(Vector3 v) const {
    auto i = (y_ * v.z_) - (v.y_ * z_);
    auto j = (x_ * v.z_) - (v.x_ * z_);
    auto k = (x_ * v.y_) - (v.x_ * y_);

    return Vector3(i, j, k);
}

const double &Vector3::operator[](int val) const {
    switch (val) {
        case 0:
            return x_;
            break;
        case 1:
            return y_;
            break;
        case 2:
            return z_;
            break;
        default:
            return NULL;
            break;
    }
}

double &Vector3::operator[](int val) {
    switch (val) {
        case 0:
            return x_;
            break;
        case 1:
            return y_;
            break;
        case 2:
            return z_;
            break;
    }
}

inline bool Vector3::operator==(const Vector3 &a) {
    if ((a.x_ == x_) && (a.y_ == y_) && (a.z_ == z_)) {
        return true;
    }
    return false;
}

inline bool Vector3::operator!=(const Vector3 &a) {
    if ((a.x_ == x_) && (a.y_ == y_) && (a.z_ == z_)) {
        return false;
    }
    return true;
}

const Vector3 Vector3::kUnitX(1.0, 0.0, 0.0);
const Vector3 Vector3::kUnitY(0.0, 1.0, 0.0);
const Vector3 Vector3::kUnitZ(0.0, 0.0, 1.0);
const Vector3 Vector3::kZero(0.0, 0.0, 0.0);

}  // namespace math
}  // namespace ekumen
