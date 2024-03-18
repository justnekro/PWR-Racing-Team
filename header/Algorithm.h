//
// Created by jakus on 17.03.2024.
//

#ifndef PWR_RT_ALGORITHM_H
#define PWR_RT_ALGORITHM_H

#include <iostream>
#include <vector>
#include "Point.h"

class Algorithm {
    private:
    std::vector<Point> points;

    public:
    explicit Algorithm(std::vector<Point> points);
    int findFirstPoint();
    double calculateAngle(Point p1, Point p2, Point point3);
    double vectorLength(Point p1, Point p2);
    double dotProduct(Point p1, Point p2, Point p3);
    std::vector<Point> findVertices();
};

#endif //PWR_RT_ALGORITHM_H
