#include <iostream>
#include "Point.h"

using namespace std;

int main(int argc, char** argv) {
    Point p1(1,1);
    /*cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;*/
    p1.print("p1", "\n");
    Point p2(2, 1);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    cout << distance(p1, p2) << endl;
    Point p3(2, 2);
    Point p4(1, 2);
    testIsSquare("points.txt");
    int N;
    cout << "Add meg a pontok szamat: ";
    cin >> N;
    printArray(createArray(N), N);

    Point *point = createArray(N);
    pair<Point, Point> closestPoint = closestPoints(point, N);
    cout << "Closest point: \n";
    closestPoint.first.print("P1", "\n");
    closestPoint.second.print("P2", "\n");
    cout << endl;

    cout << "\nFarthest points: ";
    pair<Point, Point> farthestPoint = farthestPoints(point, N);
    farthestPoint.first.print("P1", "\n");
    farthestPoint.second.print("P2", "\n");
    cout << endl;

    cout << "Sorted: \n";
    sortPoints(point, N);

    delete point;

    int numPoints = 100;
    Point *points = createArray(numPoints);
    vector<Point> farthestPoints = farthestPointsFromOrigin(points, numPoints);
    for (auto p : farthestPoints) {
        p.print("", "\n");
    }
    cout << endl;

    deletePoints(points);

    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);


    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
    delete pp1;
    delete pp2;
    return 0;
}