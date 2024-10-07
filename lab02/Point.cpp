//
// Created by Koppany on 9/30/2024.
//

#include "Point.h"

#include <iostream>

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}

void Point::print(const string &prefix, const string &sufix) const {
    cout << prefix << "(" << x << " , " << y << ")" << sufix;
}

double distance(const Point &a, const Point &b) {
        return sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    set <double> set;
    set.insert(distance(a, b));
    set.insert(distance(a, c));
    set.insert(distance(a, d));
    set.insert(distance(b, c));
    set.insert(distance(b, d));
    set.insert(distance(c, d));

    if(set.size() != 2) {return false;}
    return true;

}

void testIsSquare(const char *filename) {
    ifstream infile(filename);
    if(!infile) {
        cout << "Error when opening the file!" << endl;
        return;
    }

    int x1, y1, x2, y2, x3, y3, x4, y4;

    while(infile >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        Point p1(x1, y2);
        Point p2(x2, y2);
        Point p3(x3, y3);
        Point p4(x4, y4);

        p1.print("A ", "\n");
        p2.print("B ", "\n");
        p3.print("C ", "\n");
        p4.print("D ", "\n");

        if(isSquare(p1, p2, p3, p4)) {
            cout << "YES\n" << endl;
        }else {
            cout << "NO\n" << endl;
        }
    }
}

Point * createArray(int numPoints) {
    if(numPoints <= 0){ return nullptr; }

    srand(time(0));

    Point *points = new Point [numPoints];
    for (int i = 0; i < numPoints; i++) {
        int x = rand() % 2001;
        int y = rand() % 2001;
        points[i] = Point(x, y);
    }
    return points;
}

void printArray(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; ++i) {
        cout << i + 1 << ". ";
        points[i].print("Pont ", "\n");
        cout << endl;
    }
}

pair<Point, Point> closestPoints(Point *points, int numPoints) {
    Point p1 = points[0];
    Point p2 = points[1];
    double minDistance = distance(points[0], points[1]);

    for (int i = 0; i < numPoints - 1; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            double curr = distance(points[i], points[j]);
            if(curr < minDistance) {
                minDistance = curr;
                p1 = points[i];
                p2 = points[j];
            }
        }
    }
    return {p1, p2};
}

pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    Point p1 = points[0];
    Point p2 = points[1];
    double maxDistance = distance(points[0], points[1]);

    for (int i = 0; i < numPoints - 1; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            double curr = distance(points[i], points[j]);
            if(curr > maxDistance) {
                curr = maxDistance;
                p1 = points[i];
                p2 = points[j];
            }
        }
    }
    return {p1, p2};
}

bool comp(const Point &a, const Point &b) {
    return a.getX() < b.getX();
}

void sortPoints(Point *points, int numPoints) {
    sort(points, points + numPoints, comp);
    printArray(points, numPoints);
}

double distanceFromOrigo(const Point &p) {
    return sqrt(pow(p.getX(), 2) + pow(p.getY(), 2));
}

vector<Point> farthestPointsFromOrigin(Point *points, int numPoints) {
    vector <Point> farthestPoint;

    for(int i = 0; i < 10 && i < numPoints; i++) {
        farthestPoint.push_back(i);
    }

    for(int i = 10; i < numPoints; i++) {
        int minInd = 0;
        double minDistance = distanceFromOrigo(farthestPoint[0]);
        for(int j = 1; j < 10; j++) {
            double current = distanceFromOrigo(farthestPoint[j]);
            if(current > minDistance) {
                current = minDistance;
                minInd = j;
            }
        }
        if(distanceFromOrigo(points[i]) > minDistance) {
            farthestPoint[minInd] = points[i];
        }
    }
    return farthestPoint;
}

void deletePoints(Point *points) {
    delete[] points;
}
