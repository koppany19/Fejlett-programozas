//
// Created by Koppany on 9/30/2024.
//

#ifndef POINT_H
#define POINT_H

#include <string>
#include <cmath>
#include <set>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0);
    int getX() const;
    int getY() const;
    void print(const string &prefix, const string &sufix) const;

};
double distance(const Point& a, const Point& b);

bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);

void testIsSquare(const char *filename);

Point* createArray(int numPoints);

void printArray(Point* points, int numPoints);

pair<Point, Point> closestPoints(Point* points, int numPoints);

pair<Point, Point> farthestPoints(Point* points, int numPoints);

void sortPoints(Point* points, int numPoints);

vector<Point> farthestPointsFromOrigin(Point* points, int numPoints);

void deletePoints(Point* points);



#endif //POINT_H
