#include "Shape.h"
#include <cmath>

Point::Point(double _x, double _y) { x = _x; y = _y; }

double dist(Point a, Point b) {
    double rx = a.x - b.x;
    double ry = a.y - b.y;
    return std::sqrt(rx*rx + ry*ry);
}

Circle::Circle(Point _c, double _r) : c(_c), r(_r) {}

bool Circle::is_inside(Point p) const {
    return dist(p,c) < r;
}

Flower::Flower(Point _c, double _r, double _freq) : c(_c), r(_r), freq(_freq) {}

bool Flower::is_inside(Point p) const {

    return dist(p,c) < std::abs(std::sin(freq*std::atan2(p.y - c.y,p.x - c.x)));
}
