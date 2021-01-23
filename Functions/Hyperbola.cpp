#include <iostream>
#include "Hyperbola.h"


Hyperbola::Hyperbola(double k) {
	this->k = k;
	this->c = 0.0;
}

Hyperbola::Hyperbola(double k, double c) {
	this->k = k;
	this->c = c;
}

double Hyperbola::getMax(double x1, double x2) {
	if (this->k > 0) {
		if (x1 == 0) return INFINITY;
		return (x1 > 0) ? this->getValue(x1) : (x2 > 0) ? this->getValue(x2) : this->getValue(x1);
	} else {
		if (x2 == 0) return INFINITY;
		return (x1 > 0) ? this->getValue(x2) : (x2 > 0) ? this->getValue(x1) : this->getValue(x2);
	}
}

double Hyperbola::getMin(double x1, double x2) {
	if (this->k > 0) {
		return (x1 >= 0) ? this->getValue(x2) : (x2 > 0) ? this->getValue(x1) : this->getValue(x2);
	} else {
		if (x1 == 0) return -INFINITY;

		if (x1 > 0) {
			return this->getValue(x1);
		} else {
			if (x2 > 0) {
				return this->getValue(x2);
			} else {
				if (x1 == 0) return INFINITY;

				return this->getValue(x1);
			}
		}
	}
}

double Hyperbola::getValue(double x) {
	return this->k / x + this->c;
}