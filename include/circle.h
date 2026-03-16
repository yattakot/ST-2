// Copyright 2022 UNN-CS
#define INCLUDE_CIRCLE_H_
#include <cstdint>

class Circle {
  double radius;
  double ference;
  double area;

 public:
  explicit Circle(double _radius);

  void setRadius(double _radius);
  void setFerence(double _ference);
  void setArea(double _area);

  double getRadius();
  double getFerence();
  double getArea();
};

#endif  // INCLUDE_CIRCLE_H_
