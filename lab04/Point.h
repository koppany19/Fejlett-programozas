//
// Created by Koppany on 10/16/2024.
//

#ifndef POINT_H
#define POINT_H

#define M 2000

#include <iostream>
#include <cmath>

using namespace std;

class Point{
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    double distanceTo(const Point& point)const ;
};

#endif //POINT_H
