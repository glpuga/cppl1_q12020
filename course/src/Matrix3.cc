#include "Matrix3.h"

namespace ekumen
{

Vector3::Vector3(const double x, const double y, const double z)
{
    values[0] = x;
    values[1] = y;
    values[2] = z;
}
Vector3::Vector3()
{
    values[0] = 0.;
    values[1] = 0.;
    values[2] = 0.;
}

double Vector3::norm() const
{
    return sqrt(dot(Vector3(x(), y(), z())));
}

double Vector3::dot(const Vector3 &q) const
{
    return ((values[0] * q.x()) + (values[1] * q.y()) + (values[2] * q.z()));
}

Vector3 Vector3::cross(const Vector3 &q) const
{
    Vector3 r;
    r.x() = values[1] * q.z() - values[2] * q.y();
    r.y() = values[2] * q.x() - values[0] * q.z();
    r.z() = values[0] * q.y() - values[1] * q.x();
    return (r);
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
    try
    {
        return values[index];
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error occurred: " << ex.what() << std::endl;
    }
}

double &Vector3::operator[](const int index)
{
    try
    {
        return values[index];
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error occurred: " << ex.what() << std::endl;
    }
}

const Vector3 Vector3::kUnitX = Vector3(1., 0., 0.);
const Vector3 Vector3::kUnitY = Vector3(0., 1., 0.);
const Vector3 Vector3::kUnitZ = Vector3(0., 0., 1.);
const Vector3 Vector3::kZero = Vector3(0., 0., 0.);

const Matrix3 Matrix3::kIdentity = Matrix3(Vector3::kUnitX,Vector3::kUnitY,Vector3::kUnitZ);
const Matrix3 Matrix3::kZero = Matrix3(Vector3::kZero,Vector3::kZero,Vector3::kZero);
//const Matrix3 Matrix3::kOnes  = Matrix3(Vector3::kOnes,Vector3::kOnes,Vector3::kOnes);


} // namespace ekumen
