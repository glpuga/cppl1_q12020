#include "vector3.h"
#include <cmath>
#include <initializer_list>
#include <iostream>
#include <stdexcept>

namespace ekumen {
namespace math {
namespace {
constexpr double square(double x) { return x * x; }
constexpr int kXIndex = 0;
constexpr int kYIndex = 1;
constexpr int kZIndex = 2;
}  // namespace

const Vector3 Vector3::kUnitX = Vector3(1, 0, 0);
const Vector3 Vector3::kUnitY = Vector3(0, 1, 0);
const Vector3 Vector3::kUnitZ = Vector3(0, 0, 1);
const Vector3 Vector3::kZero = Vector3(0, 0, 0);

Vector3::Vector3(double x, double y, double z) : x_(x), y_(y), z_(z) {}

Vector3::Vector3(const Vector3& obj) : Vector3(obj.x(), obj.y(), obj.z()) {}

Vector3::Vector3(std::initializer_list<double> vector) {
  if (vector.size() != 3) {
    throw std::invalid_argument("Initializer list must be of size 3.");
  }
  const double* p = vector.begin();
  x_ = *p;
  y_ = *(p + 1);
  z_ = *(p + 2);
}

Vector3& Vector3::operator=(const Vector3& obj) {
  x_ = obj.x();
  y_ = obj.y();
  z_ = obj.z();
}

Vector3 Vector3::operator+(const Vector3& obj) const {
  Vector3 res(x_ + obj.x(), y_ + obj.y(), z_ + obj.z());
  return res;
}

Vector3 Vector3::operator-(const Vector3& obj) const {
  Vector3 res(x_ - obj.x(), y_ - obj.y(), z_ - obj.z());
  return res;
}

Vector3 Vector3::operator*(const Vector3& obj) const {
  Vector3 res(x_ * obj.x(), y_ * obj.y(), z_ * obj.z());
  return res;
}

Vector3 Vector3::operator*(const double& factor) const {
  Vector3 res(x_ * factor, y_ * factor, z_ * factor);
  return res;
}

Vector3 operator*(const double& factor, const Vector3& obj) {
  Vector3 res(factor * obj.x(), factor * obj.y(), factor * obj.z());
  return res;
}

Vector3 Vector3::operator/(const Vector3& obj) const {
  Vector3 res(x_ / obj.x(), y_ / obj.y(), z_ / obj.z());
  return res;
}

Vector3 Vector3::operator/(const double& factor) const {
  Vector3 res(x_ / factor, y_ / factor, z_ / factor);
  return res;
}

bool Vector3::operator==(const Vector3& rhs) const {
  return (x_ == rhs.x() && y_ == rhs.y() && z_ == rhs.z());
}

bool Vector3::operator!=(const Vector3& rhs) const { return !(*this == rhs); }

const double& Vector3::operator[](int index) const { return (*this)[index]; }

double& Vector3::operator[](int index) {
  switch (index) {
    case kXIndex:
      return x_;
    case kYIndex:
      return y_;
    case kZIndex:
      return z_;
    default:
      throw std::invalid_argument("Allowed indexes are: 0, 1, 2.");
  }
}

std::ostream& operator<<(std::ostream& os, const Vector3& obj) {
  os << "(x: " << obj.x() << ", y: " << obj.y() << ", z: " << obj.z() << ")";
  return os;
}

double Vector3::norm() const {
  return std::sqrt(square(x_) + square(y_) + square(z_));
}

double Vector3::dot(const Vector3& obj) const {
  return (this->x_ * obj.x() + this->y_ * obj.y() + this->z_ * obj.z());
}

Vector3 Vector3::cross(const Vector3& obj) const {
  double res_x = this->y_ * obj.z() - this->z_ * obj.y();
  double res_y = this->z_ * obj.x() - this->x_ * obj.z();
  double res_z = this->x_ * obj.y() - this->y_ * obj.x();
  return Vector3(res_x, res_y, res_z);
}

const double& Vector3::x() const { return x_; }

// Try avoiding using this. This is error-prone as it can have two
// responsibilities as getter or setter.
double& Vector3::x() { return x_; }

const double& Vector3::y() const { return y_; }

// Try avoiding using this. This is error-prone as it can have two
// responsibilities as getter or setter.
double& Vector3::y() { return y_; }

const double& Vector3::z() const { return z_; }

// Try avoiding using this. This is error-prone as it can have two
// responsibilities as getter or setter.
double& Vector3::z() { return z_; }

}  // namespace math
}  // namespace ekumen