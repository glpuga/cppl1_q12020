#include "Vector3.h"

namespace ekumen
{

double Vector3::norm() const
{
    return sqrt((x_ * x_) + (y_ * y_) + (z_ * z_));
}

double Vector3::dot(const Vector3 &q) const
{
    return ((x_ * q.x()) + (y_ * q.y()) + (z_ * q.z()));
}

Vector3 Vector3::cross(Vector3 &q) const
{
    //not implemented
    return (Vector3::kZero); //only for shutdown warning
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

double Vector3::operator[](int index) const
{
    if (index < 3)
    {
        switch (index)
        {
        case 0:
            return (&x_)[index];
        case 1:
            return (&y_)[index];
        case 2:
            return (&z_)[index];
        default:
            break;
        }
    }
}

const Vector3 Vector3::kUnitX = Vector3(1., 0., 0.);
const Vector3 Vector3::kUnitY = Vector3(0., 1., 0.);
const Vector3 Vector3::kUnitZ = Vector3(0., 1., 0.);
const Vector3 Vector3::kZero = Vector3(0., 0., 0.);

} // namespace ekumen
