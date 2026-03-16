// Copyright 2022 UNN-CS
#include "tasks.h"

#include "circle.h"

double calculateEarthGap(double earth_radius_km, double rope_length_m) {
  double earth_radius_m = earth_radius_km * 1000;
  Circle earth(earth_radius_m);

  double old_earth_ference = earth.getFerence();
  double new_earth_ference = old_earth_ference + rope_length_m;

  earth.setFerence(new_earth_ference);
  return earth.getRadius() - earth_radius_m;
}

double calculatePoolCost(double pool_radius_m, double path_width_m) {
  Circle pool(pool_radius_m);
  Circle pool_with_path(pool_radius_m + path_width_m);

  double path_area = pool_with_path.getArea() - pool.getArea();
  double cost_of_path = path_area * 1000;

  double fence_lenght = pool_with_path.getFerence();
  double cost_of_fence = fence_lenght * 2000;

  return cost_of_path + cost_of_fence;
}
