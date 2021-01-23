#pragma once
#include "Function.h"

using namespace std;

class Hyperbola : public Function {
private:
    double k;
    double c;
public:
    Hyperbola(double k);
    Hyperbola(double k, double c);
    double getMax(double x1, double x2);
    double getMin(double x1, double x2);
    double getValue(double x);
};