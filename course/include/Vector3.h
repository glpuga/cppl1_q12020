#ifndef VECTOR3_H
#define VECTOR3_H
#include <iostream>
#include "math.h"

namespace ekumen
{



class Vector3
{
public:
    explicit Vector3(double x, double y, double z) : x_(x), y_(y), z_(z) {}

    double x() const { return x_; }
    double y() const { return y_; }
    double z() const { return z_; }

    double norm() const;


    //operator overload
    double operator[](int index) const;
    friend Vector3 operator+(const Vector3 &p, const Vector3 &q);
    friend Vector3 operator-(const Vector3 &p, const Vector3 &q);
    friend Vector3 operator*(const double &cte, const Vector3 &p);
    friend Vector3 operator*(const Vector3 &p, const double &cte);
    friend Vector3 operator*(const Vector3 &p, const Vector3 &q);
    friend Vector3 operator/(const Vector3 &p, const Vector3 &q);
    friend bool operator==(const Vector3 &p, const Vector3 &q);
    friend std::ostream &operator<<(std::ostream &os, const Vector3 &p);

    constexpr k = Vector3(1., 1., 0);
    

private:
    const double x_;
    const double y_;
    const double z_;
};

} // namespace ekumen

#endif