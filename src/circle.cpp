// Copyright 2022 UNN-

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "circle.h"

#include <cmath>
#include <cstdint>

Circle::Circle(double _radius) { setRadius(_radius); }

void Circle::setRadius(double _radius) {
  if (_radius < 0) {
    throw -1;
  }
  radius = _radius;
  ference = 2 * M_PI * _radius;
  area = M_PI * _radius * _radius;
}
void Circle::setFerence(double _ference) {
  if (_ference < 0) {
    throw -1;
  }
  radius = _ference / (2 * M_PI);
  ference = _ference;
  area = M_PI * radius * radius;
}
void Circle::setArea(double _area) {
  if (_area < 0) {
    throw -1;
  }
  radius = std::sqrt(_area / M_PI);
  area = _area;
  ference = 2 * M_PI * radius;
}

double Circle::getRadius() { return radius; }
double Circle::getFerence() { return ference; }
double Circle::getArea() { return area; }
