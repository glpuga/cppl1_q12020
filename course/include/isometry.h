#pragma once

#include <string>
#include <iostream>
#include <cmath>

namespace cppcourse
{

class Vector3
{
public:
  Vector3(const std::initializer_list<double> &rhs);
  Vector3(const double &x = 0., const double &y = 0., const double &z = 0.) : x_(x),
                                                                              y_(y),
                                                                              z_(z){};
  int value() const { return value_; }
  Vector3 operator+(const Vector3 &other) const;
  Vector3 operator-(const Vector3 &other) const;
  Vector3 operator/(const Vector3 &other) const;
  Vector3 operator*(const double &other) const;
  Vector3 operator*(const Vector3 &other) const;
  double dot(const Vector3 &other) const;

  bool operator==(const double other[3]) const;
  bool operator!=(const Vector3 &other) const { return (not(*this == other)); }
  bool operator==(const Vector3 &other) const;
  bool operator==(const std::initializer_list<double> &rhs) const;
  double norm() const;
  double& x() { return x_; }
  const double& x() const { return x_; }
  double& y() { return y_; }
  const double& y() const { return y_; }
  double& z() { return z_; }
  const double& z() const { return z_; }
  Vector3 cross(const Vector3& other) const;
  double& operator[](const int index);
  const double& operator[](const int index) const;
  static const Vector3 kUnitX;
  static const Vector3 kUnitY;
  static const Vector3 kUnitZ;
  static const Vector3 kZero;
private:
  const int value_{};
  double x_, y_, z_;
};

inline Vector3 operator*(const double& i, const Vector3 &vec)
{
  return (vec * i);
}
inline std::ostream &operator<<(std::ostream &ss, const cppcourse::Vector3 &vec) { return ss << "(x: " << vec.x()
                                                                                             << ", y: "<< vec.y()
                                                                                             << ", z: "<< vec.z()
                                                                                             << ")"; }
                                                                                             

} // namespace cppcourse
