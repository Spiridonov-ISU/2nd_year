#pragma once
#include "Function.h"
#include <vector>

using namespace std;

class Parabola : public Function {
private:
    vector<int> coeffic;
    int size;
public:
    Parabola(vector<int>& coeffs);
    double getMax(double x1, double x2);
    double getMin(double x1, double x2);
    double getValue(double x);
};