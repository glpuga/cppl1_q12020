#include "Matrix3.h"

namespace ekumen
{

    Matrix3::Matrix3()
    {
        row(0) = Vector3::kZero;
        row(1) = Vector3::kZero;
        row(2) = Vector3::kZero;
    }

    Matrix3::Matrix3(const Vector3 &f1, const Vector3 &f2, const Vector3 &f3)
    {
        row(0) = f1;
        row(1) = f2;
        row(2) = f3;
    }

    Matrix3::Matrix3(const std::initializer_list<double> &list)
    {
        int i = 0, j = 0;
        if (list.size() == 9)
        {
            for (const auto &v : list)
                {
                    row_values[i][j] = v;
                    if (j++ == 2)
                    {
                        ++i;
                        j = 0;
                    }
                }
        }
    }

    Matrix3::Matrix3(const std::initializer_list<double> &r0, const std::initializer_list<double> &r1, const std::initializer_list<double> &r2)
    {
        row(0) = Vector3(r0);
        row(1) = Vector3(r1);
        row(2) = Vector3(r2);
        
    }

    Matrix3::Matrix3(const Matrix3 &m)
    {
        row(0) = m.row(0);
        row(1) = m.row(1);
        row(2) = m.row(2);
    }

    double Matrix3::det() const
    {
        const Vector3 &i = row(0);
        Vector3 j = row(1).cross(row(2));
        return (i.x() * j.x() + i.y() * j.y() + i.z() * j.z());
    }

    const Vector3 Matrix3::row(int index) const
    {
        if ((index >= 0)&&(index < 3))
            return row_values[index];
        else
            return Vector3();
    }

    Vector3 &Matrix3::row(int index)
    {
        if ((index >= 0)&&(index < 3))
            return row_values[index];
        else
            return row_values[0];
        
    }

    const Vector3 Matrix3::col(const int index) const
    {

            if ((index >= 0)&&(index < 3))
            {
                Vector3 p(row_values[0][index], row_values[1][index], row_values[2][index]);
                return p;
            }


        return Vector3();
    }

    Vector3 Matrix3::col(const int index)
    {
            if ((index >= 0)&&(index < 3))
            {
                Vector3 p(row_values[0][index], row_values[1][index], row_values[2][index]);
                return p;
            }
        return Vector3();
    }

    const Vector3 &Matrix3::operator[](const int &index) const
    {
        try
        {
            if ((index >= 0)&&(index < 3))
            {
                return row_values[index];
            }
        }
        catch (const std::exception &ex)
        {
            std::cerr << "Error occurred: " << ex.what() << std::endl;
        }
        return row_values[0];
    }

    Vector3 &Matrix3::operator[](const int &index)
    {
        try
        {
            if ((index >= 0)&&(index < 3))
            {
                return row(index);
            }
        }
        catch (const std::exception &ex)
        {
            std::cerr << "Error occurred: " << ex.what() << std::endl;
        }
        return row(0);
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
        Matrix3 r(p);
        r += q;
        return r;
    }

    Matrix3 operator-(const Matrix3 &p, const Matrix3 &q)
    {
        Matrix3 r(p);
        r -= q;
        return r;
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

    bool operator==(const std::initializer_list<double> &list, const Matrix3 &p)
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
        for (size_t i = 0; i < 3; ++i)
        {
            res.row(i) = p.row(i) / q.row(i);
        }
        return res;
    }

    bool operator!=(const Matrix3 &p, const Matrix3 &q)
    {
        return !(p == q);
    }

    bool operator!=(const Matrix3 &p, const std::initializer_list<double> &list)
    {
        Matrix3 q(list);
        return !(p == q);
    }

    bool operator!=(const std::initializer_list<double> &list, const Matrix3 &p)
    {
        Matrix3 q(list);
        return !(p == q);
    }

    std::ostream &operator<<(std::ostream &os, const Matrix3 &p)
    {
        os << "[";
        for (size_t i = 0; i < 2; ++i)
        {
            os << "[" << p[i][0] << ", " << p[i][1] << ", " << p[i][2] << "], ";
        }
        os << "[" << p[2][0] << ", " << p[2][1] << ", " << p[2][2] << "]]";

        return os;
    }

    const Matrix3 Matrix3::kIdentity = Matrix3(Vector3::kUnitX, Vector3::kUnitY, Vector3::kUnitZ);
    const Matrix3 Matrix3::kZero = Matrix3(Vector3::kZero, Vector3::kZero, Vector3::kZero);
    const Matrix3 Matrix3::kOnes = Matrix3(Vector3::kOnes, Vector3::kOnes, Vector3::kOnes);
} // namespace ekumen
