#include "Figure.h"
#include "Point.h"
#include "Poligon.h"
#include <math.h>
#include <vector>

Poligon::Poligon(vector<Point> p)
{
    this->points = p;
}

double Poligon::GetArea()
{
    double area = 0;
    int j = points.size() - 1;
    for (int i = 0; i < points.size(); i++) {
        area += (points[j].GetX() + points[i].GetX()) * (points[j].GetY() - points[i].GetY());
        j = i;
    }
    return abs(area / 2);
}

double Poligon::GetPerimeter()
{
    double perimeter = 0;
    int m, n;
    for (int i = 1; i < points.size() - 1; i++) {
        Point a = points[i];
        Point b = points[i + 1];
        m = a.GetX() - b.GetX();
        n = a.GetY() - b.GetY();
        perimeter += sqrt(abs(m * m - n * n));
    }
    return perimeter;
}