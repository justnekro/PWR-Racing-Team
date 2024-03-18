#include <utility>
#include <cmath>

#include "../header/Algorithm.h"

Algorithm::Algorithm(std::vector<Point> points) {
    this -> points = std::move(points);
}

int Algorithm::findFirstPoint() {
    int index = 0;
    for (int i=0; i<points.size(); i++) {
        if (points[i].getY() < points[index].getY()) {
            index = i;
        } else if (points[i].getY() == points[index].getY() && points[i].getX() < points[index].getX()) {
            index = i;
        }
    }
    return index;
}

double Algorithm::vectorLength(const Point p1, const Point p2) {
    return sqrt(((p2.getX() - p1.getX()) * (p2.getX() - p1.getX())) + ((p2.getY() - p1.getY()) * (p2.getY() - p1.getY())));
}

double Algorithm::dotProduct(const Point p1, const Point p2, const Point p3) {
    return ((p2.getX() - p1.getX()) * (p3.getX() - p2.getX())) + ((p2.getY() - p1.getY()) * (p3.getY() - p2.getY()));
}

double Algorithm::calculateAngle(const Point p1, const Point p2, const Point p3) {
    return acos(dotProduct(p1, p2, p3) / (vectorLength(p1, p2) * vectorLength(p2, p3)));
}

std::vector<Point> Algorithm::findVertices() {
    int index = findFirstPoint();
    std::vector<Point> vertices = {points[findFirstPoint()]};

    //Finding the second vertex
    double minAngle = 3.15;
    int minIndex;
    for (int i=0; i<points.size(); i++) {
        double angle = calculateAngle(Point(points[index].getX() - 1, points[index].getY()), points[index], points[i]);
        if (angle < minAngle) {
            minAngle = angle;
            minIndex = i;
        }
    }

    //Finding the remaining vertices
    while(minIndex != index) {
        vertices.push_back(points[minIndex]);
        minAngle = 3.15;
        for (int i=0; i<points.size(); i++) {
            double angle = calculateAngle(vertices[vertices.size()-2], vertices[vertices.size()-1], points[i]);
            if (angle < minAngle) {
                minAngle = angle;
                minIndex = i;
            }
        }
    }

    return vertices;
}