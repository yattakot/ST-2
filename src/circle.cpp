// Copyright 2022 UNN-CS
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "circle.h"
#include <cmath>
#include <stdexcept>

Circle::Circle(double radius) {
  setRadius(radius);
}

void Circle::setRadius(double radius) {
  if (radius < 0.0) {
    throw std::invalid_argument("Radius cannot be negative");
  }
  radius_ = radius;
  circumference_ = 2.0 * M_PI * radius_;
  area_ = M_PI * radius_ * radius_;
}

void Circle::setCircumference(double circumference) {
  if (circumference < 0.0) {
    throw std::invalid_argument("Circumference cannot be negative");
  }
  circumference_ = circumference;
  radius_ = circumference_ / (2.0 * M_PI);
  area_ = M_PI * radius_ * radius_;
}

void Circle::setArea(double area) {
  if (area < 0.0) {
    throw std::invalid_argument("Area cannot be negative");
  }
  area_ = area;
  radius_ = std::sqrt(area_ / M_PI);
  circumference_ = 2.0 * M_PI * radius_;
}

double Circle::getRadius() const { return radius_; }
double Circle::getCircumference() const { return circumference_; }
double Circle::getArea() const { return area_; }
