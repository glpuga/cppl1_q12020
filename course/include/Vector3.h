#ifndef VECTOR3_H
#define	VECTOR3_H
#include "math.h"

namespace ekumen {

class Vector3 {
 public:
    explicit Vector3(double x, double y, double z) : x_(x),y_(y),z_(z) {}
    
    double x() const {return x_;}
    double y() const {return y_;}
    double z() const {return z_;}
    double norm() const {return sqrt((x_*x_)+(y_*y_)+(z_*z_));}

    double operator[](int index) const;
 private:    
    const double x_;
    const double y_;
    const double z_;
};


Vector3 operator +(const Vector3 &p,const Vector3 &q)
{
    Vector3 res( p.x() + q.x(), p.y() + q.y(), p.z() + q.z() );
    return res;
}

Vector3 operator -(const Vector3 &p,const Vector3 &q)
{
    Vector3 res( p.x() - q.x(), p.y() - q.y(), p.z() - q.z() );
    return res;
}

Vector3 operator *(const double &cte,const Vector3 &p)
{
    Vector3 res( cte*p.x(),cte*p.y(), cte*p.z());
    return res;
}

Vector3 operator *(const Vector3 &p,const double &cte)
{
    Vector3 res( cte*p.x(),cte*p.y(), cte*p.z());
    return res;
}

Vector3 operator *(const Vector3 &p,const Vector3 &q)
{
    Vector3 res( p.x()*q.x(), p.y()*q.y(), p.z()*q.z() );
    return res;
}

Vector3 operator /(const Vector3 &p,const Vector3 &q)
{
    Vector3 res( p.x()/q.x(), p.y()/q.y(), p.z()/q.z() );
    return res;
}

bool operator ==(const Vector3 &p, const Vector3 &q)
{
   bool res = (p.x()==q.x())&&(p.y()==q.y())&&(p.z()==q.z());
   return res;
}

double Vector3::operator[](int index) const{
         
   switch(index){
      case 0:
         return(&x_)[index];
      case 1:
         return(&x_)[index];
      case 2:
         return(&x_)[index];
      default:
         break;
   }
}

}  // cppcourse

#endif