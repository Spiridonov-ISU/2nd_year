#include "Figure.h"
#include "Triangle.h"
#include <math.h>

Triangle::Triangle(double a, double b, double c)
{
    this->A = a;
    this->B = b;
    this->C = c;
}

double Triangle::GetArea() {
    double p = this->GetPerimeter() / 2;
    return sqrt(p * (p - this->A) * (p - this->B) * (p - this->C));
}

double Triangle::GetPerimeter()
{
    return A + B + C;
}