#pragma once
#include "Function.h"
#include <vector>

using namespace std;

class Exponenta : public Function {
private:
    double k;
    double c;
public:
    Exponenta(double k);
    Exponenta(double k, double c);
    double getMax(double x1, double x2);
    double getMin(double x1, double x2);
    double getValue(double x);
};