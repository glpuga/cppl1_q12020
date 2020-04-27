#include "Matrix3.h"

namespace ekumen
{

Matrix3::Matrix3()
{
    row_values[0] = Vector3::kZero;
    row_values[1] = Vector3::kZero;
    row_values[2] = Vector3::kZero;
}
Matrix3::Matrix3(const Vector3 f1, const Vector3 f2, const Vector3 f3)
{
    row_values[0] = f1;
    row_values[1] = f2;
    row_values[2] = f3;
}
Matrix3::Matrix3(const std::initializer_list<double> &list)
{
    size_t c = 0;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            row_values[i][j] = *(list.begin() + c);
            c++;
        }
    }
}
Matrix3::Matrix3(const std::initializer_list<double> &r0, const std::initializer_list<double> &r1, const std::initializer_list<double> &r2)
{
    //modificar
    row_values[0] = Vector3(*(r0.begin() + 0), *(r0.begin() + 1), *(r0.begin() + 2));
    row_values[1] = Vector3(*(r1.begin() + 0), *(r1.begin() + 1), *(r1.begin() + 2));
    row_values[2] = Vector3(*(r2.begin() + 0), *(r2.begin() + 1), *(r2.begin() + 2));
}

Matrix3::Matrix3(const Matrix3 &m)
{
    row(0) = m.row(0);
    row(1) = m.row(1);
    row(2) = m.row(2);
}

Matrix3::~Matrix3() {}

double Matrix3::det() const
{

    Vector3 i = row(0);
    Vector3 j = row(1).cross(row(2));
    return (i.x() * j.x() + i.y() * j.y() + i.z() * j.z());
}

Vector3 &Matrix3::row(const int index) const
{
    return (row_values[index]);
}
Vector3 &Matrix3::row(const int index)
{
    return (row_values[index]);
}

Vector3 Matrix3::col(const int index) const
{

    try
    {
        Vector3 p;
        p.x() = row_values[0][index];
        p.y() = row_values[1][index];
        p.z() = row_values[2][index];
        return p;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error occurred: " << ex.what() << std::endl;
    }
    return(Vector3::kZero);
}

Vector3 Matrix3::col(const int index)
{
    try
    {
        Vector3 p;
        p.x() = row_values[0][index];
        p.y() = row_values[1][index];
        p.z() = row_values[2][index];
        return p;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error occurred: " << ex.what() << std::endl;
    }
    return(Vector3::kZero);
}

const Vector3 &Matrix3::operator[](const int index) const
{
    try
    {
        //return (row(index));
        return (row_values[index]);
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error occurred: " << ex.what() << std::endl;
    }
}

Vector3 &Matrix3::operator[](const int index)
{
    try
    {
        return (row(index));
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error occurred: " << ex.what() << std::endl;
    }
}

Matrix3 &Matrix3::operator+=(const Matrix3 &q)
{
    row(0) += q.row(0);
    row(1) += q.row(1);
    row(2) += q.row(2);
    return *this;
}
Matrix3 &Matrix3::operator-=(const Matrix3 &q)
{
    row(0) -= q.row(0);
    row(1) -= q.row(1);
    row(2) -= q.row(2);
    return *this;
}

Matrix3 operator+(const Matrix3 &p, const Matrix3 &q)
{
    Matrix3 r;
    r.row(0) = p.row(0) + q.row(0);
    r.row(1) = p.row(1) + q.row(1);
    r.row(2) = p.row(2) + q.row(2);
    return (r);
}

Matrix3 operator-(const Matrix3 &p, const Matrix3 &q)
{
    Matrix3 r;
    r.row(0) = p.row(0) - q.row(0);
    r.row(1) = p.row(1) - q.row(1);
    r.row(2) = p.row(2) - q.row(2);
    return (r);
}

bool operator==(const Matrix3 &p, const Matrix3 &q)
{
    bool row0 = (p.row(0) == q.row(0));
    bool row1 = (p.row(1) == q.row(1));
    bool row2 = (p.row(2) == q.row(2));
    return (row0 && row1 && row2);
}

bool operator==(const Matrix3 &p, const std::initializer_list<double> &list)
{

    Matrix3 q(list);
    return (p == q);
}

Matrix3 operator*(const double &cte, const Matrix3 &p)
{
    Matrix3 res(cte * p.row(0), cte * p.row(1), cte * p.row(2));
    return res;
}
Matrix3 operator*(const Matrix3 &p, const double &cte)
{
    Matrix3 res(cte * p.row(0), cte * p.row(1), cte * p.row(2));
    return res;
}

Matrix3 operator*(const Matrix3 &p, const Matrix3 &q)
{

    Matrix3 res(p.row(0) * q.row(0), p.row(1) * q.row(1), p.row(2) * q.row(2));
    return res;
}

Matrix3 operator/(const Matrix3 &p, const Matrix3 &q)
{
    Matrix3 res;
    for (size_t i = 0; i < 3; i++)
        res.row(i) = p.row(i) / q.row(i);
    return (res);
}

bool operator!=(const Matrix3 &p, const Matrix3 &q)
{
    return (!(p == q));
}

bool operator!=(const Matrix3 &p, const std::initializer_list<double> &list)
{
    Matrix3 q(list);
    return (!(p == q));
}

std::ostream &operator<<(std::ostream &os, const Matrix3 &p)
{
    os << "[";
    for (size_t i = 0; i < 2; i++)
    {
        os << "[" << p[i][0] << ", " << p[i][1] << ", " << p[i][2] << "], ";
    }
    os << "[" << p[2][0] << ", " << p[2][1] << ", " << p[2][2] << "]]";

    return os;
}

const Matrix3 Matrix3::kIdentity = Matrix3(Vector3::kUnitX, Vector3::kUnitY, Vector3::kUnitZ);
const Matrix3 Matrix3::kZero = Matrix3(Vector3::kZero, Vector3::kZero, Vector3::kZero);
const Matrix3 Matrix3::kOnes = Matrix3(Vector3(1., 1., 1), Vector3(1., 1., 1), Vector3(1., 1., 1));

} // namespace ekumen
