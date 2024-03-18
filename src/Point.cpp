#include "../header/Point.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Point::Point(double x, double y) {
    this -> x = x;
    this -> y = y;
}

std::string Point::to_string(int precision) const {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << "(" << x << ", " << y << ")";
    return stream.str();
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setX(double newX) {
    x = newX;
}

void Point::setY(double newY) {
    y = newY;
}

bool Point::operator==(const Point &rhs) const {
    return x == rhs.x && y == rhs.y;
}
