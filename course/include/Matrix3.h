#pragma once
#include <iostream>
#include "math.h"
#include "Vector3.h"

namespace ekumen
{

class Matrix3
{
public:
    explicit Matrix3();
    explicit Matrix3(const Vector3 f1, const Vector3 y, const Vector3 z);


    double det() const;
    
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
   
    friend std::ostream &operator<<(std::ostream &os, const Matrix3 &p);
         

    static const Matrix3 kIdentity;
    static const Matrix3 kZero;
    static const Matrix3 kOnes;
   

private:

    Vector3 *values = new Vector3[3];

};

} // namespace ekumen
