#pragma once

#include "Function.h"
#include <vector>

using namespace std;

class Polynom : public Function {
private:
    vector<int> coeffic;
    int size;
public:
    Polynom(vector<int>& coeffic);
    double getMax(double x1, double x2);
    double getMin(double x1, double x2);
    double getValue(double x);
};
