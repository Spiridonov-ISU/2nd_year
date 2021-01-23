#pragma once
#include <iostream>

class Function
{
public:
	virtual double getMax(double x1,double x2) = 0;
    virtual double getMin(double x1,double x2) = 0;
    virtual double getValue(double x) = 0;
};