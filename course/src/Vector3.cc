#include "Vector3.h"

namespace ekumen
{

double Vector3::norm() const
{
    return sqrt(dot(Vector3(x(),y(),z())));
    
}

double Vector3::dot(const Vector3 &q) const
{
    return ((x_ * q.x()) + (y_ * q.y()) + (z_ * q.z()));
}

Vector3 Vector3::cross(const Vector3 &q) const
{
    //Vector3 r;
    //r[0] = y_*q.z() - z_*q.y();
    //r[1] = z_*q.x() - x_*q.z();
    //r[2] = x_*q.y() - y_*q.x();
    //not implemented
    return (Vector3(y_ * q.z() - z_ * q.y(), z_ * q.x() - x_ * q.z(), x_ * q.y() - y_ * q.x())); //only for shutdown warning
}

Vector3 operator+(const Vector3 &p, const Vector3 &q)
{
    Vector3 res(p.x() + q.x(), p.y() + q.y(), p.z() + q.z());
    return res;
}

Vector3 operator-(const Vector3 &p, const Vector3 &q)
{
    Vector3 res(p.x() - q.x(), p.y() - q.y(), p.z() - q.z());
    return res;
}

Vector3 operator*(const double &cte, const Vector3 &p)
{
    Vector3 res(cte * p.x(), cte * p.y(), cte * p.z());
    return res;
}

Vector3 operator*(const Vector3 &p, const double &cte)
{
    Vector3 res(cte * p.x(), cte * p.y(), cte * p.z());
    return res;
}

Vector3 operator*(const Vector3 &p, const Vector3 &q)
{
    Vector3 res(p.x() * q.x(), p.y() * q.y(), p.z() * q.z());
    return res;
}

Vector3 operator/(const Vector3 &p, const Vector3 &q)
{
    Vector3 res(p.x() / q.x(), p.y() / q.y(), p.z() / q.z());
    return res;
}

bool operator==(const Vector3 &p, const Vector3 &q)
{
    bool res = (p.x() == q.x()) && (p.y() == q.y()) && (p.z() == q.z());
    return res;
}
bool operator!=(const Vector3 &p, const Vector3 &q)
{

    return (!(p == q));
}
std::ostream &operator<<(std::ostream &os, const Vector3 &p)
{
    os << "(x: " << p.x() << ", y: " << p.y() << ", z: " << p.z() << ")";
    return os;
}

const double &Vector3::operator[](const int index) const
{
    switch (index)
    {
    case 0:
        return x_;
    case 1:
        return y_;
    case 2:
        return z_;
    default:
        break;
    }

    return (&x_)[index];
}

double &Vector3::operator[](const int index)
{
    switch (index)
    {
    case 0:
        return x_;
    case 1:
        return y_;
    case 2:
        return z_;
    default:
        break;
    }

    return x_;
}

const Vector3 Vector3::kUnitX = Vector3(1., 0., 0.);
const Vector3 Vector3::kUnitY = Vector3(0., 1., 0.);
const Vector3 Vector3::kUnitZ = Vector3(0., 0., 1.);
const Vector3 Vector3::kZero = Vector3(0., 0., 0.);

} // namespace ekumen
