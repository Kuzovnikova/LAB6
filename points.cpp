#include "Points.h"
#include <iostream>
#include <cmath>

Point2D::Point2D(double _x, double _y) : x(_x), y(_y) {}
void Point2D::Print() const { std::cout << "(" << x << ", " << y << ")"; }
Point2D::~Point2D() {}

Point3D::Point3D(double _x, double _y, double _z) : Point2D(_x, _y), z(_z) {}

double Point3D::DistanceTo(const Point3D& other) const {
    return std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2) + std::pow(other.z - z, 2));
}

void Point3D::Print() const { std::cout << "(" << x << ", " << y << ", " << z << ")"; }
