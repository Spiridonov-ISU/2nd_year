#include <iostream>
#include "Parabola.h"

using namespace std;

Parabola::Parabola(vector<int>& coeffic) {
	if (coeffic.size() != 3) {
		return;
	}
	this->coeffic = coeffic;
	this->size = coeffic.size();
}

double Parabola::getMax(double x1, double x2) {
	double max;

	if (this->coeffic[0] > 0) {
		return (this->getValue(x1) > this->getValue(x2)) ? this->getValue(x1) : this->getValue(x2);
	} else {
		double x = -this->coeffic[1] / (2 * this->coeffic[0]);
		if (x > x2 || x < x1) {
			max = DBL_MIN;
			double temp_max;

			for (double i = x1; i <= x2; i += 0.01) {
				temp_max = this->getValue(i);
				if (temp_max > max) max = temp_max;
			}

			return max;
		} else {
			return this->getValue(x);
		}
	}
}

double Parabola::getMin(double x1, double x2) {
	double min;

	if (this->coeffic[0] < 0) {
		return (this->getValue(x1) < this->getValue(x2)) ? this->getValue(x1) : this->getValue(x2);
	} else {
		double x = -this->coeffic[1] / (2 * this->coeffic[0]);
		if (x > x2 || x < x1) {
			min = DBL_MAX;
			double temp_min;

			for (double i = x1; i <= x2; i += 0.01) {
				temp_min = this->getValue(i);
				if (temp_min < min) min = temp_min;
			}

			return min;
		} else {
			return this->getValue(x);
		}
	}
}
double Parabola::getValue(double x) {
	return this->coeffic[0] * x * x + this->coeffic[1] * x + this->coeffic[2];
}