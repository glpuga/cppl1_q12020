#include "Vector3.h"

namespace ekumen
{

double Vector3::norm() const
{
    return sqrt((x_ * x_) + (y_ * y_) + (z_ * z_));
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

std::ostream &operator<<(std::ostream &os, const Vector3 &p)
{
    os << "(x: " << p.x() << ", y: " << p.y() << ", z: " << p.z() << ")";
    return os;
}

double Vector3::operator[](int index) const
{

    switch (index)
    {
    case 0:
        return (&x_)[index];
    case 1:
        return (&x_)[index];
    case 2:
        return (&x_)[index];
    default:
        break;
    }
}

    void Vector3::kUnitX(){

    }
    void Vector3::kUnitY(){

    }
    void Vector3::kUnitZ(){
        
    }

} // namespace ekumen
