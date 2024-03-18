#ifndef PWR_RT_POINT_H
#define PWR_RT_POINT_H

#include <iostream>

class Point {
    private:
    double x;
    double y;

    public:
    Point(double x, double y);

    std::string to_string(int precision) const;

    double getX() const;
    double getY() const;

    bool operator==(const Point &rhs) const;
};


#endif //PWR_RT_POINT_H
