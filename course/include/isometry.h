#ifndef ISOMETRY_H
#define	ISOMETRY_H

namespace ekumen {

class Vector3 {
 public:
  explicit Vector3(int value) : value_(value) {}
  int value() const { return value_; }

 private:
  const int value_{};
};

}  // cppcourse

#endif
