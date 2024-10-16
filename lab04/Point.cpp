//
// Created by Koppany on 10/16/2024.
//

#include "Point.h"


Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}

double Point::distanceTo(const Point &point) const {
    int dx = x - point.getX();
    int dy = y - point.getY();
    return sqrt(dx * dx + dy * dy);
}
