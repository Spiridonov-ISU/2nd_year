#pragma once
#include "Figure.h"
#include "Point.h"
#include <vector>

using namespace std;

class Poligon : public Figure
{
private:
    vector<Point> points;
public:
    Poligon(vector<Point> p);
    double GetArea();
    double GetPerimeter();
};