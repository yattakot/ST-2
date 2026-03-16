// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>

#include <cmath>

#include "circle.h"
#include "tasks.h"

const double epsilon = 1e-10;

TEST(CircleTest, ConstructorAndGettersWorksCorrect) {
  double radius = 10.0;
  Circle c(radius);

  EXPECT_DOUBLE_EQ(c.getRadius(), radius);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * radius * radius);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * radius);
}

TEST(CircleTest, ConstructorNegativeRadiusThrowsException) {
  double radius = -10.0;
  ASSERT_ANY_THROW(Circle c(radius));
}

TEST(CircleTest, SetRadiusWorksCorrect) {
  double radius = 10.0;
  Circle c(radius);

  double new_radius = 15.0;
  ASSERT_NO_THROW(c.setRadius(new_radius));

  EXPECT_DOUBLE_EQ(c.getRadius(), new_radius);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * new_radius * new_radius);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * new_radius);
}

TEST(CircleTest, SetNegativeRadiusThrowException) {
  double radius = 10.0;
  Circle c(radius);

  double new_radius = -15.0;
  ASSERT_ANY_THROW(c.setRadius(new_radius));
}

TEST(CircleTest, SetAreaWorksCorrect) {
  double radius = 5.0;
  Circle c(radius);

  double new_area = 100.0;
  ASSERT_NO_THROW(c.setArea(new_area));
  double new_radius = std::sqrt(new_area / M_PI);

  EXPECT_NEAR(c.getRadius(), new_radius, epsilon);
  EXPECT_NEAR(c.getArea(), M_PI * new_radius * new_radius, epsilon);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * new_radius, epsilon);
}

TEST(CircleTest, SetNegativeAreaThrowsException) {
  double radius = 5.0;
  Circle c(radius);

  double new_area = -100.0;
  ASSERT_ANY_THROW(c.setArea(new_area));
}

TEST(CircleTest, SetFerenceWorksCorrect) {
  double radius = 5.0;
  Circle c(radius);

  double new_ference = 100.0;
  ASSERT_NO_THROW(c.setFerence(new_ference));
  double new_radius = new_ference / (2 * M_PI);

  EXPECT_NEAR(c.getRadius(), new_radius, epsilon);
  EXPECT_NEAR(c.getArea(), M_PI * new_radius * new_radius, epsilon);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * new_radius, epsilon);
}

TEST(CircleTest, SetNegativeFerenceThrowsException) {
  double radius = 5.0;
  Circle c(radius);

  double new_ference = -100.0;
  ASSERT_ANY_THROW(c.setFerence(new_ference));
}

TEST(CircleTest, ZeroRadiusCircle) {
  double radius = 0.0;
  Circle c(radius);

  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleTest, SetZeroRadiusWorksCorrect) {
  double radius = 10.0;
  Circle c(radius);

  c.setRadius(0.0);

  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleTest, SetZeroAreaWorksCorrect) {
  double radius = 10.0;
  Circle c(radius);

  c.setArea(0.0);

  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleTest, SetZeroFerenceWorksCorrect) {
  double radius = 10.0;
  Circle c(radius);

  c.setFerence(0.0);

  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleTest, LargeRadiusCalculations) {
  double radius = 1e6;
  Circle c(radius);
  EXPECT_DOUBLE_EQ(c.getRadius(), 1e6);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1e6 * 1e6);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 1e6);
}

TEST(CircleTest, SmallRadiusCalculations) {
  double radius = 1e-6;
  Circle c(radius);
  EXPECT_DOUBLE_EQ(c.getRadius(), radius);
  EXPECT_NEAR(c.getArea(), M_PI * radius * radius, epsilon);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * radius);
}

TEST(EarthGapTest, EarthGapOriginalData) {
  double gap = calculateEarthGap(6378.1, 1.0);
  double expected_gap = 1.0 / (2 * M_PI);
  EXPECT_NEAR(gap, expected_gap, epsilon);
}

TEST(EarthGapTest, EarthGapDifferentData) {
  double gap = calculateEarthGap(10.0, 5.0);
  double expected_gap = 5.0 / (2 * M_PI);
  EXPECT_NEAR(gap, expected_gap, epsilon);
}

TEST(EarthGapTest, EarthGapZeroRopeAdded) {
  double gap = calculateEarthGap(6378.1, 0.0);
  EXPECT_NEAR(gap, 0.0, epsilon);
}

TEST(PoolCostTest, PoolCostOriginalData) {
  double cost = calculatePoolCost(3.0, 1.0);
  double expected_cost = 23000.0 * M_PI;
  EXPECT_NEAR(cost, expected_cost, epsilon);
}

TEST(PoolCostTest, PoolCostDifferentData) {
  double cost = calculatePoolCost(5.0, 2.0);
  double expected_cost = 52000.0 * M_PI;
  EXPECT_NEAR(cost, expected_cost, epsilon);
}

TEST(PoolCostTest, PoolCostNoPathWidth) {
  double cost = calculatePoolCost(3.0, 0.0);
  double expected_cost = 12000.0 * M_PI;
  EXPECT_NEAR(cost, expected_cost, epsilon);
}

TEST(PoolCostTest, PoolCostZeroRadiusPool) {
  double cost = calculatePoolCost(0.0, 2.0);
  double expected_cost = 12000.0 * M_PI;
  EXPECT_NEAR(cost, expected_cost, epsilon);
}
