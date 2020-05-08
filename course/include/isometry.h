#pragma once
#include "Vector3.h"
#include "Matrix3.h"
#include <math.h>

namespace ekumen
{
class Isometry
{
public:
    Isometry();
    explicit Isometry(const Vector3 &v, const Matrix3 &m);
    explicit Isometry(const std::initializer_list<double> &list, Matrix3 &m);

    ~Isometry();
    static Isometry FromTranslation(const std::initializer_list<double> &list);
    static Isometry FromTranslation(const Vector3 &v);
    static Isometry RotateAround(const Vector3 &v, const double &a);
    static Isometry FromEulerAngles(const double &x, const double &y, const double &z);

    Vector3 transform(const Vector3 &v) const;
    Vector3 transform(const std::initializer_list<double> &list);
    Isometry inverse(void) const;
    Isometry compose(const Isometry &I1) const;
    Vector3 translation() const;
    Matrix3 rotation() const;

    friend bool operator==(const Isometry &p, const Isometry &q);
    friend std::ostream &operator<<(std::ostream &os, const Isometry &m);

    friend Vector3 operator*(const Isometry &i, const Vector3 &v);
    friend Isometry operator*(const Isometry &i, const Isometry &i2);

private:
    Vector3 vector3_isometry;
    Matrix3 matrix3_isometry;
    double v_row3_isometry[4];
};

} // namespace ekumen
