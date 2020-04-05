#include <isometry/isometry.hpp>

namespace ekumen {
  namespace math {

  //Vector3

  const Vector3 Vector3::kUnitX(1., 0., 0.);
  const Vector3 Vector3::kUnitY(0., 1., 0.);
  const Vector3 Vector3::kUnitZ(0., 0., 1.);
  const Vector3 Vector3::kZero(0., 0., 0.);

  Vector3 & Vector3::operator *= (const double & obj)
  {
    x_ *= obj;
    y_ *= obj;
    z_ *=  obj;
    return *this;
  }

  Vector3 & Vector3::operator /= (const double & obj)
  {
    x_ /= obj;
    y_ /= obj;
    z_ /=  obj;
    return *this;
  }

  Vector3 & Vector3::operator += (const Vector3 & obj)
  {
    x_ += obj.x();
    y_ += obj.y();
    z_ +=  obj.z();
    return *this;
  }

  Vector3 & Vector3::operator -= (const Vector3 & obj)
  {
    x_ -= obj.x();
    y_ -= obj.y();
    z_ -=  obj.z();
    return *this;
  }

  bool Vector3::operator == (const std::initializer_list<double> & obj) const
  {
    if (obj.size() != 3)
    {
      throw std::runtime_error("Size of list not valid");
    }
    auto it = obj.begin();
    double x_list, y_list, z_list;
    x_list = *it++;
    y_list = *it++;
    z_list = *it;
    if ( (x_list != x_) || (y_list != y_) || (z_list != z_) )
    {
      return false;
    }
    return true;
  }

  bool Vector3::operator == (const Vector3 & obj) const
  {
    if ( (obj[0] != x_) || (obj[1] != y_) || (obj[2] != z_) )
    {
      return false;
    }
    return true;
  }

  Vector3 & Vector3::operator *= (const Vector3 & obj)
  {
    x_ *= obj.x();
    y_ *= obj.y();
    z_ *=  obj.z();
    return *this;
  }

  Vector3 & Vector3::operator /= (const Vector3 & obj)
  {
    x_ /= obj.x();
    y_ /= obj.y();
    z_ /=  obj.z();
    return *this;
  }

  double Vector3::norm() const
  {
    return sqrt( std::pow(x_, 2.0) + std::pow(y_, 2.0) + std::pow(z_, 2.0) );
  }

  Vector3 operator * (const double & obj1, const Vector3 & obj2)
  {
    return Vector3(obj2.x() * obj1, obj2.y() * obj1, obj2.z() * obj1);
  }

  const double & Vector3::operator [] (const int index) const
  {
    if (index > 2 || index < 0)
    {
      throw std::runtime_error("Index not valid");
    }
    else if (index == 0)
    {
      return x_;
    }
    else if (index == 1)
    {
      return y_;
    }
    else
    {
      return z_;
    }
  }

  double & Vector3::operator [] (const int index)
  {
    if (index > 2 || index < 0)
    {
      throw std::runtime_error("Index not valid");
    }
    else if (index == 0)
    {
      return x_;
    }
    else if (index == 1)
    {
      return y_;
    }
    else
    {
      return z_;
    }
  }

  Vector3 Vector3::cross(const Vector3 & obj) const
  {
    return Vector3(
                y_ * obj.z_ - z_ * obj.y_,
                z_ * obj.x_ - x_ * obj.z_,
                x_ * obj.y_ - y_ * obj.x_);
  }

  double Vector3::dot(const Vector3 & obj) const
  {
    return (x_ * obj.x_) + (y_ * obj.y_) + (z_ * obj.z_);
  }

  //Matrix3

  const Matrix3 Matrix3::kIdentity({1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.});
  const Matrix3 Matrix3::kZero({0., 0., 0.}, {0., 0., 0.}, {0., 0., 0.});
  const Matrix3 Matrix3::kOnes({1., 1., 1.}, {1., 1., 1.}, {1., 1., 1.});

  bool Matrix3::operator == (const Matrix3 & obj) const
  {
    if (obj[0] != row1_ || obj[1] != row2_ || obj[2] != row3_)
    {
      return false;
    }
    return true;
  }

  bool Matrix3::operator == (const std::initializer_list<double> & obj) const
  {
    if (obj.size() != 9)
    {
      throw std::runtime_error("Size of list not valid");
    }
    if (obj.begin()[0] != row1_[0] || obj.begin()[1] != row1_[1] || obj.begin()[2] != row1_[2])
    {
      return false;
    }
    else if (obj.begin()[3] != row2_[0] || obj.begin()[4] != row2_[1] || obj.begin()[5] != row2_[2])
    {
      return false;
    }
    else if (obj.begin()[6] != row3_[0] || obj.begin()[7] != row3_[1] || obj.begin()[8] != row3_[2])
    {
      return false;
    }
    return true;
  }

  Vector3 Matrix3::operator [] (const int index) const
  {
    if (index > 2 || index < 0)
    {
      throw std::runtime_error("Index not valid");
    }
    else if (index == 0)
    {
      return row1_;
    }
    else if (index == 1)
    {
      return row2_;
    }
    return row3_;
  }

  Vector3 & Matrix3::operator [] (const int index)
  {
    if (index > 2 || index < 0)
    {
      throw std::runtime_error("Index not valid");
    }
    else if (index == 0)
    {
      return row1_;
    }
    else if (index == 1)
    {
      return row2_;
    }
    return row3_;
  }

  Matrix3 & Matrix3::operator += (const Matrix3 & obj)
  {
    row1_ += obj[0];
    row2_ += obj[1];
    row3_ += obj[2];
    return *this;
  }

  Matrix3 & Matrix3::operator -= (const Matrix3 & obj)
  {
    row1_ -= obj[0];
    row2_ -= obj[1];
    row3_ -= obj[2];
    return *this;
  }

  Matrix3 & Matrix3::operator *= (const Matrix3 & obj)
  {
    row1_ *= obj[0];
    row2_ *= obj[1];
    row3_ *= obj[2];
    return *this;
  }

  Matrix3 & Matrix3::operator /= (const Matrix3 & obj)
  {
    row1_ /= obj[0];
    row2_ /= obj[1];
    row3_ /= obj[2];
    return *this;
  }

  Matrix3 & Matrix3::operator *= (const double & obj)
  {
    row1_ *= obj;
    row2_ *= obj;
    row3_ *= obj;
    return *this;
  }

  Matrix3 & Matrix3::operator /= (const double & obj)
  {
    row1_ /= obj;
    row2_ /= obj;
    row3_ /= obj;
    return *this;
  }

  Vector3 Matrix3::operator * (const Vector3 & obj)
  {
    double new_x = (row1_[0] * obj[0]) + (row1_[1] * obj[1]) + (row1_[2] * obj[2]);
    double new_y = (row2_[0] * obj[0]) + (row2_[1] * obj[1]) + (row2_[2] * obj[2]);
    double new_z = (row3_[0] * obj[0]) + (row3_[1] * obj[1]) + (row3_[2] * obj[2]);
    return Vector3(new_x, new_y, new_z);
  }

  Matrix3 operator * (const double & obj1, const Matrix3 & obj2)
  {
    return Matrix3(obj2[0] * obj1, obj2[1] * obj1, obj2[2] * obj1);
  }

  double Matrix3::det() const
  {
    return ((row1_[0] * row2_[1] * row3_[2]) + (row1_[1] * row2_[2] * row3_[0]) +
            (row1_[2] * row2_[0] * row3_[1]) - (row1_[2] * row2_[1] * row3_[0]) -
            (row1_[0] * row2_[2] * row3_[1]) - (row1_[1] * row2_[0] * row3_[2]));
  }

  Vector3 Matrix3::row(const int index) const
  {
    if (index > 2 || index < 0)
    {
      throw std::runtime_error("Index not valid");
    }
    else if (index == 0)
    {
      return row1_;
    }
    else if (index == 1)
    {
      return row2_;
    }
    return row3_;
  }

  Vector3 Matrix3::col(const int index) const
  {
    if (index > 2 || index < 0)
    {
      throw std::runtime_error("Index not valid");
    }
    return Vector3(row1_[index], row2_[index], row3_[index]);
  }

}
}
