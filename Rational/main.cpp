#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
    Rational a(4, 1), b(1, 6);

    cout << "a = " << a << endl;
    cout << "b = " << b << "\n\n";

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << "\n\n";
 
    cout << "a == b = " << (a == b) << endl;
    cout << "a != b = " << (a != b) << endl;
    cout << "a > b = " << (a > b) << endl;
    cout << "a < b = " << (a < b) << endl;
    cout << "a >= b = " << (a >= b) << endl;
    cout << "a <= b = " << (a <= b) << "\n\n";

    b = ++b;
    cout << "++b = " << b << endl;
    b = --b;
    cout << "--b = " << b << "\n\n";

    cout << "a.Rational_sqrt() = " << a.Rational_sqrt() << endl;
}