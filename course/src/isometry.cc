#include "isometry.h"

namespace ekumen
{
Isometry::Isometry()
{
    vector3_isometry = Vector3::kZero;
    matrix3_isometry = Matrix3::kIdentity;
    //TODO Mejorar
    v_row3_isometry[0] = 0;
    v_row3_isometry[1] = 0;
    v_row3_isometry[2] = 0;
    v_row3_isometry[3] = 1;
}
Isometry::Isometry(const Vector3 &v, const Matrix3 &m)
{
    vector3_isometry = v;
    matrix3_isometry = m;
    v_row3_isometry[0] = 0;
    v_row3_isometry[1] = 0;
    v_row3_isometry[2] = 0;
    v_row3_isometry[3] = 1;
}

Isometry::Isometry(const std::initializer_list<double> &list, Matrix3 &m)
{
    vector3_isometry = Vector3(list);
    matrix3_isometry = m;
    v_row3_isometry[0] = 0;
    v_row3_isometry[1] = 0;
    v_row3_isometry[2] = 0;
    v_row3_isometry[3] = 1;
}

Isometry::~Isometry()
{
}

Isometry Isometry::FromTranslation(const std::initializer_list<double> &list)
{
    Isometry I(Vector3(list), Matrix3::kIdentity);
    return (I);
}

Isometry Isometry::FromTranslation(const Vector3 &v)
{
    Isometry I(v, Matrix3::kIdentity);
    return (I);
}

Isometry Isometry::RotateAround(const Vector3 &v, const double &a)
{
    Isometry I1;
    if (v == Vector3::kUnitX)
    {
        I1.matrix3_isometry = {{1., 0., 0.}, {0., cos(a), -sin(a)}, {0, sin(a), cos(a)}};
    }
    else if (v == Vector3::kUnitY)
    {
        I1.matrix3_isometry = {{cos(a), 0., sin(a)}, {0., 1., 0.}, {-sin(a), 0, cos(a)}};
    }
    else if (v == Vector3::kUnitZ)
    {
        I1.matrix3_isometry = {{cos(a), -sin(a), 0}, {sin(a), cos(a), 0}, {0., 0., 1.}};
    }

    return I1;
}

Vector3 Isometry::translation() const
{
    return (vector3_isometry);
}

Matrix3 Isometry::rotation() const
{
    return (matrix3_isometry);
}

Isometry Isometry::FromEulerAngles(const double &x, const double &y, const double &z)
{
    double cx = cos(x);
    double sx = sin(x);
    double cy = cos(y);
    double sy = sin(y);
    double cz = cos(z);
    double sz = sin(z);

    double m00 = cy * cz;
    double m01 = -cy * sz;
    double m02 = sy;
    double m10 = sx * sy * cz + cz * cx;
    double m11 = -sx * sy * sz + cx * cz;
    double m12 = -sx * sy;
    double m20 = -cx * sy * cz + sx * sz;
    double m21 = cx * sy * sz + sx * cz;
    double m22 = cx * cy;

    Vector3 vv1 = Vector3(m00, m01, m02);
    Vector3 vv2 = Vector3(m10, m11, m12);
    Vector3 vv3 = Vector3(m20, m21, m22);

    return (Isometry(Vector3::kZero, Matrix3(vv1, vv2, vv3)));
}

Vector3 Isometry::transform(const Vector3 &v) const
{
    return ((*this) * v);
}

Vector3 Isometry::transform(const std::initializer_list<double> &list)
{
    return ((*this) * Vector3(list));
}

Isometry Isometry::inverse(void) const
{
    Isometry I(vector3_isometry * (-1), matrix3_isometry);
    return (I);
}

Isometry Isometry::compose(const Isometry &I1) const
{
    Isometry I = Isometry((*this) * I1);
    return (I);
}

bool operator==(const Isometry &p, const Isometry &q)
{
    for (size_t i = 0; i < 2; i++)
    {
        if (p.vector3_isometry[i] != p.vector3_isometry[i])
            return false;
        if (p.matrix3_isometry[i] != p.matrix3_isometry[i])
            return false;
    }
    return true;
}

Vector3 operator*(const Isometry &i, const Vector3 &v)
{

    Vector3 r;
    r.x() = i.matrix3_isometry.row(0).dot(v) + i.vector3_isometry.x();
    r.y() = i.matrix3_isometry.row(1).dot(v) + i.vector3_isometry.y();
    r.z() = i.matrix3_isometry.row(2).dot(v) + i.vector3_isometry.z();
    return (r);
}

Isometry operator*(const Isometry &i, const Isometry &i2)
{
    Isometry m;
    Matrix3 p = i.matrix3_isometry;
    Matrix3 q = i2.matrix3_isometry;

    Vector3 a, b;
    for (size_t i = 0; i < 3; i++)
    {
        a = p.row(i);
        for (size_t j = 0; j < 3; j++)
        {
            b = q.col(j);
            m.matrix3_isometry[i][j] = a.dot(b);
        }
    }
    m.vector3_isometry = i.vector3_isometry + i2.vector3_isometry;
    return (m);
}

std::ostream &operator<<(std::ostream &os, const Isometry &p)
{
    os.precision(9);
    os << "[T: " << p.vector3_isometry << ", ";
    os << "R:" << p.matrix3_isometry << "]";
    return os;
}

} // namespace ekumen
