// Copyright 2025 UNN-CS Team
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <gtest/gtest.h>
#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

constexpr double kEpsilon = 1e-10;


TEST(CircleTest, ConstructorAndGettersWorkCorrect) {
  const double radius = 10.0;
  const Circle c(radius);

  EXPECT_DOUBLE_EQ(c.getRadius(), radius);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * radius * radius);
  EXPECT_DOUBLE_EQ(c.getCircumference(), 2.0 * M_PI * radius);
}

TEST(CircleTest, ConstructorNegativeRadiusThrowsException) {
  const double radius = -10.0;
  ASSERT_THROW(Circle c(radius), std::invalid_argument);
}

TEST(CircleTest, SetRadiusWorksCorrect) {
  double radius = 10.0;
  Circle c(radius);

  const double new_radius = 15.0;
  ASSERT_NO_THROW(c.setRadius(new_radius));

  EXPECT_DOUBLE_EQ(c.getRadius(), new_radius);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * new_radius * new_radius);
  EXPECT_DOUBLE_EQ(c.getCircumference(), 2.0 * M_PI * new_radius);
}

TEST(CircleTest, SetNegativeRadiusThrowsException) {
  const double radius = 10.0;
  Circle c(radius);

  const double new_radius = -15.0;
  ASSERT_THROW(c.setRadius(new_radius), std::invalid_argument);
}

TEST(CircleTest, SetAreaWorksCorrect) {
  const double radius = 5.0;
  Circle c(radius);

  const double new_area = 100.0;
  ASSERT_NO_THROW(c.setArea(new_area));
  const double new_radius = std::sqrt(new_area / M_PI);

  EXPECT_NEAR(c.getRadius(), new_radius, kEpsilon);
  EXPECT_NEAR(c.getArea(), M_PI * new_radius * new_radius, kEpsilon);
  EXPECT_NEAR(c.getCircumference(), 2.0 * M_PI * new_radius, kEpsilon);
}

TEST(CircleTest, SetNegativeAreaThrowsException) {
  const double radius = 5.0;
  Circle c(radius);

  const double new_area = -100.0;
  ASSERT_THROW(c.setArea(new_area), std::invalid_argument);
}

TEST(CircleTest, SetCircumferenceWorksCorrect) {
  const double radius = 5.0;
  Circle c(radius);

  const double new_circumference = 100.0;
  ASSERT_NO_THROW(c.setCircumference(new_circumference));
  const double new_radius = new_circumference / (2.0 * M_PI);

  EXPECT_NEAR(c.getRadius(), new_radius, kEpsilon);
  EXPECT_NEAR(c.getArea(), M_PI * new_radius * new_radius, kEpsilon);
  EXPECT_NEAR(c.getCircumference(), 2.0 * M_PI * new_radius, kEpsilon);
}

TEST(CircleTest, SetNegativeCircumferenceThrowsException) {
  const double radius = 5.0;
  Circle c(radius);

  const double new_circumference = -100.0;
  ASSERT_THROW(c.setCircumference(new_circumference), std::invalid_argument);
}

TEST(CircleTest, ZeroRadiusCircle) {
  const double radius = 0.0;
  Circle c(radius);

  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
  EXPECT_DOUBLE_EQ(c.getCircumference(), 0.0);
}

TEST(CircleTest, SetZeroRadiusWorksCorrect) {
  Circle c(10.0);
  c.setRadius(0.0);

  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
  EXPECT_DOUBLE_EQ(c.getCircumference(), 0.0);
}

TEST(CircleTest, SetZeroAreaWorksCorrect) {
  Circle c(10.0);
  c.setArea(0.0);

  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
  EXPECT_DOUBLE_EQ(c.getCircumference(), 0.0);
}

TEST(CircleTest, SetZeroCircumferenceWorksCorrect) {
  Circle c(10.0);
  c.setCircumference(0.0);

  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
  EXPECT_DOUBLE_EQ(c.getCircumference(), 0.0);
}

TEST(CircleTest, LargeRadiusCalculations) {
  const double radius = 1e6;
  Circle c(radius);

  EXPECT_DOUBLE_EQ(c.getRadius(), 1e6);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1e6 * 1e6);
  EXPECT_DOUBLE_EQ(c.getCircumference(), 2.0 * M_PI * 1e6);
}

TEST(CircleTest, SmallRadiusCalculations) {
  const double radius = 1e-6;
  Circle c(radius);

  EXPECT_DOUBLE_EQ(c.getRadius(), radius);
  EXPECT_NEAR(c.getArea(), M_PI * radius * radius, kEpsilon);
  EXPECT_DOUBLE_EQ(c.getCircumference(), 2.0 * M_PI * radius);
}

TEST(EarthGapTest, EarthGapOriginalData) {
  const double gap = calculateEarthGap(6378.1, 1.0);
  const double expected_gap = 1.0 / (2.0 * M_PI);
  EXPECT_NEAR(gap, expected_gap, kEpsilon);
}

TEST(EarthGapTest, EarthGapDifferentData) {
  const double gap = calculateEarthGap(10.0, 5.0);
  const double expected_gap = 5.0 / (2.0 * M_PI);
  EXPECT_NEAR(gap, expected_gap, kEpsilon);
}

TEST(EarthGapTest, EarthGapZeroRopeAdded) {
  const double gap = calculateEarthGap(6378.1, 0.0);
  EXPECT_NEAR(gap, 0.0, kEpsilon);
}

TEST(PoolCostTest, PoolCostOriginalData) {
  const double cost = calculatePoolCost(3.0, 1.0);
  const double expected_cost = 23000.0 * M_PI;
  EXPECT_NEAR(cost, expected_cost, kEpsilon);
}

TEST(PoolCostTest, PoolCostDifferentData) {
  const double cost = calculatePoolCost(5.0, 2.0);
  const double expected_cost = 52000.0 * M_PI;
  EXPECT_NEAR(cost, expected_cost, kEpsilon);
}

TEST(PoolCostTest, PoolCostNoPathWidth) {
  const double cost = calculatePoolCost(3.0, 0.0);
  const double expected_cost = 12000.0 * M_PI;
  EXPECT_NEAR(cost, expected_cost, kEpsilon);
}

TEST(PoolCostTest, PoolCostZeroRadiusPool) {
  const double cost = calculatePoolCost(0.0, 2.0);
  const double expected_cost = 12000.0 * M_PI;
  EXPECT_NEAR(cost, expected_cost, kEpsilon);
}
