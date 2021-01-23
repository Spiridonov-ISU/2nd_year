#include <iostream>
#include <vector>
#include "Function.h"
#include "Polynom.h"
#include "Hyperbola.h"
#include "Parabola.h"
#include "Exponenta.h"

using namespace std;

int main() {
	vector<int> plcoeff = { 2, 2, 4, 9 };
	Polynom pl(plcoeff);
	cout << "polynom" << endl;
	cout << "ValF\t" << pl.getValue(2) << endl;
	cout << "Max \t" << pl.getMax(-4, 4) << endl;
	cout << "Min \t" <<pl.getMin(-4, 4) << "\n\n";

	Hyperbola h(6, 3);
	cout << "hyperbola" << endl;
	cout << "ValF\t" << h.getValue(2) << endl;
	cout << "Max \t" << h.getMax(-4, 4) << endl;
	cout << "Min \t" << h.getMin(-4, 4) << "\n\n";

	vector<int> prcoeff = { -1, 2, 1 };
	Parabola pr (prcoeff);
	cout << "parabola" << endl;
	cout << "ValF\t" << pr.getValue(2) << endl;
	cout << "Max \t" << pr.getMax(0, 4) << endl;
	cout << "Min \t" << pr.getMin(0, 4) << "\n\n";
	
	Exponenta e = (2, 5);
	cout << "exponenta" << endl;
	cout << "ValF\t" << e.getValue(2) << endl;
	cout << "Max \t" << e.getMax(0, 4) << endl;
	cout << "Min \t" << e.getMin(0, 4) << "\n\n";

	return 0;
}