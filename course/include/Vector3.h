#pragma once
#include <iostream>
#include "math.h"

namespace ekumen
{

class Vector3
{
public:
    explicit Vector3(double x, double y, double z) : x_(x), y_(y), z_(z) {}
    explicit Vector3() : x_(0.0), y_(0.0), z_(0.0) {}
    double x() const { return x_; }
    double y() const { return y_; }
    double z() const { return z_; }
        
    double norm() const;
    double dot(const Vector3 &q) const;
    Vector3 cross(const Vector3 &q) const;
    //operator overload
    const double& operator[](const int index) const;
    double& operator[](const int index);    
    

    friend Vector3 operator+(const Vector3 &p, const Vector3 &q);
    friend Vector3 operator-(const Vector3 &p, const Vector3 &q);
    friend Vector3 operator*(const double &cte, const Vector3 &p);
    friend Vector3 operator*(const Vector3 &p, const double &cte);
    friend Vector3 operator*(const Vector3 &p, const Vector3 &q);
    friend Vector3 operator/(const Vector3 &p, const Vector3 &q);
    friend bool operator==(const Vector3 &p, const Vector3 &q);
    friend bool operator!=(const Vector3 &p, const Vector3 &q);
    //friend bool operator!=(const Vector3 &p, const Vector3 &q);
    friend std::ostream &operator<<(std::ostream &os, const Vector3 &p);     

    static const Vector3 kUnitX;
    static const Vector3 kUnitY;
    static const Vector3 kUnitZ;
    static const Vector3 kZero;
private:
    double x_;
    double y_;
    double z_;
};

} // namespace ekumen