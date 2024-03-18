#include <iostream>
#include <fstream>
#include <vector>
#include "../header/Point.h"
#include "../header/Algorithm.h"

std::vector<Point> loadPoints (const std::string& filename) {
    std::fstream file(filename, std::ios::in);

    //Checking if the file opened correctly
    if (!file.is_open()) {
        std::cout << "\nAn error occurred while opening the file.\n";
        return {};
    }

    std::vector<Point> points;
    int numberOfPoints;
    double x, y;

    file >> numberOfPoints;
    if (numberOfPoints < 3) {
        std::cout << "Not enough points to create rim.";
        return {};
    }

    //Writing points to a vector
    for (int i=0; i<numberOfPoints; i++) {
        file >> x >> y;
        points.emplace_back(x, y);
    }

    file.close();
    return points;
}

int main() {
    std::string filename;
    std::cout << "Enter file name: ";
    std::cin >> filename;

    //Loading points into a file
    std::vector<Point> points = loadPoints(filename);

    //Finding the vertices of the envelope
    Algorithm algorithm(points);
    std::vector<Point> vertices = algorithm.findVertices();

    //Writing points to the terminal
    for (Point point : vertices)
        std::cout << point.to_string(1) << " ";

    return 0;
}
