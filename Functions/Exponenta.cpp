#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include "Exponenta.h"


using namespace std;

Exponenta::Exponenta(double k) {
	this->k = k;
	this->c = 0.0;
}

Exponenta::Exponenta(double k, double c) {
	this->k = k;
	this->c = c;
}

double Exponenta::getMax(double x1, double x2) {
	return (k > 0) ? this->getValue(x2) : this->getValue(x1);
}

double Exponenta::getMin(double x1, double x2) {
	return (k > 0) ? this->getValue(x1) : this->getValue(x2);
}

double Exponenta::getValue(double x) {
	return pow(M_E, x) * k + c;
}