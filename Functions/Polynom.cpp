#include <iostream>
#include <math.h>
#include "Polynom.h"


Polynom::Polynom(vector<int>& coeffic) {
    this->coeffic = coeffic;
    this->size = coeffic.size();
}

double Polynom::getMax(double x1, double x2) {
    double max = DBL_MIN;
    double temp_max;

    for (double i = x1; i <= x2; i += 0.01) {
        temp_max = this->getValue(i);
        if (temp_max > max) max = temp_max;
    }
    return max;
}

double Polynom::getMin(double x1, double x2) {
    double min = DBL_MAX;
    double temp_min;

    for (double i = x1; i <= x2; i += 0.01) {
        temp_min = this->getValue(i);
        if (temp_min < min) min = temp_min;
    }
    return min;
}

double Polynom::getValue(double x) {
    double result = 0;
    for (int i = 0; i < this->size; i++) {
        result += pow(x, this->size - i - 1) * this->coeffic[i];
    }
    return result;
}