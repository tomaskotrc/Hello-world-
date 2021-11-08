#ifndef SHAPE_H
#define SHAPE_H

// Jednoducha trida pro popis bodu
// struct je jako class, jen je standardne vse viditelne jako public
struct Point {
    Point(double _x, double _y);
    double x;
    double y;
};

double dist(Point a, Point b);

// Trida Shape je abstraktni, metoda is_inside() zde neni implementovana
// Tuto metodu musi implementovat odvozene tridy
// Abstraktni trida je jakysi predpis podle ktereho muzeme vytvaret
// odvozene tridy
class Shape {
    public:
    virtual bool is_inside(Point p) const = 0; // Predpis pro metodu is_inside
                                               // Vraci true, pokud lezi bod uvnitr tvaru
};

// Tridy pro popis jednotlivych tvaru, ktere budeme integrovat
class Circle : public Shape {
public:
    Circle(Point _c, double _r);
    virtual bool is_inside(Point p) const;
private:
    Point c;
    double r;
};

class Flower : public Shape {
public:
    Flower(Point _c, double _r, double _freq);
    virtual bool is_inside(Point p) const;
private:
    Point c;
    double r;
    double freq;
};

#endif // SHAPE_H
