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
    explicit Matrix3(const Vector3 f1, const Vector3 f2, const Vector3 f3);
    Matrix3(const std::initializer_list<double> &list);
    Matrix3(const std::initializer_list<double> &r1, const std::initializer_list<double> &r2, const std::initializer_list<double> &r3);
    Matrix3(const Matrix3 &m);
    ~Matrix3();

    double det() const;
    Vector3 &row(const int index) const;
    Vector3 &row(const int index);
    Vector3 col(const int index) const;
    Vector3 col(const int index);

    Matrix3 &operator+=(const Matrix3 &q);
    Matrix3 &operator-=(const Matrix3 &q);

    //operator overload
    const Vector3 &operator[](const int index) const;
    Vector3 &operator[](const int index);

    friend bool operator==(const Matrix3 &p, const Matrix3 &q);
    friend bool operator==(const Matrix3 &p, const std::initializer_list<double> &list);

    friend Matrix3 operator*(const double &cte, const Matrix3 &p);
    friend Matrix3 operator*(const Matrix3 &p, const double &cte);
    friend Matrix3 operator*(const Matrix3 &p, const Matrix3 &q);
    friend Matrix3 operator/(const Matrix3 &p, const Matrix3 &q);

    friend bool operator!=(const Matrix3 &p, const Matrix3 &q);
    friend bool operator!=(const Matrix3 &p, const std::initializer_list<double> &list);

    friend std::ostream &operator<<(std::ostream &os, const Matrix3 &p);
    static const Matrix3 kIdentity;
    static const Matrix3 kZero;
    static const Matrix3 kOnes;

private:
    Vector3 *row_values = new Vector3[3];
};

Matrix3 operator+(const Matrix3 &p, const Matrix3 &q);
Matrix3 operator-(const Matrix3 &p, const Matrix3 &q);

} // namespace ekumen
