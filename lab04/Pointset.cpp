#include "Pointset.h"
#include <algorithm>
#include <random>

bool used[M + 1][M + 1]{false};

random_device rd; // Seed the random number generator
mt19937 mt(rd());
uniform_int_distribution<int> dist(0, M); // Generate numbers in the range [0, M]

int genRandom(int x) {
    return dist(mt);
}

void PointSet::computeDistances() {
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

PointSet::PointSet(int n) {
    this->n = n;
    this->points.reserve(n);
    while (points.size() < n) {
        int x = genRandom(M);
        int y = genRandom(M);
        if (!used[x][y]) {
            points.emplace_back(Point(x, y));
            used[x][y] = true;
        }
    }
    computeDistances();
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for (const auto& point : points) {
        cout << "(" << point.getX() << ", " << point.getY() << ") ";
    }
    cout << endl;
}

void PointSet::printDistances() const {
    for (double distance : distances) {
        cout << distance << " ";
    }
    cout << endl;
}

bool compare(const Point& a, const Point& b) {
    return a.getX() < b.getX();
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), compare);
}

bool compare2(const Point& a, const Point& b) {
    return a.getY() < b.getY();
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), compare2);
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    unique(distances.begin(), distances.end());
    auto last = unique(distances.begin(), distances.end());
    return distance(distances.begin(), last);
}
