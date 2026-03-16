// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

double calculateEarthGap(double earth_radius_km, double rope_length_m) {
  constexpr double kMetersPerKm = 1000.0;

  const double earth_radius_m = earth_radius_km * kMetersPerKm;
  Circle earth(earth_radius_m);

  const double original_circumference = earth.getCircumference();
  earth.setCircumference(original_circumference + rope_length_m);

  return earth.getRadius() - earth_radius_m;
}

double calculatePoolCost(double pool_radius_m, double path_width_m) {
  constexpr double kConcreteCostPerSqMeter = 1000.0;
  constexpr double kFenceCostPerMeter = 2000.0;

  Circle pool(pool_radius_m);
  Circle outer_boundary(pool_radius_m + path_width_m);

  const double path_area = outer_boundary.getArea() - pool.getArea();
  const double path_cost = path_area * kConcreteCostPerSqMeter;

  const double fence_length = outer_boundary.getCircumference();
  const double fence_cost = fence_length * kFenceCostPerMeter;

  return path_cost + fence_cost;
}
