#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;
typedef unsigned long long mytype;
mytype base = 1e12;

void setdata(mytype nSize, mytype* arr, int a) {
	memset(arr, 0, nSize*sizeof(mytype));
	arr[0] = a;
}

bool isZero(mytype nSize, mytype* arr) {
	for (int i = 0; i < nSize; i++) {
		if (arr[i] != 0)
			return false;
	}
	return true;
}

void Div(mytype nSize, mytype* arr, mytype d) {
	mytype carry = 0, xi, q;
	for (mytype i = 0; i < nSize; i++) {
		xi = arr[i] + carry * base;
		q = xi / d;
		carry = xi - q * d;
		arr[i] = q;
	}
}

void Add(mytype nSize, mytype* arr1, mytype* arr2) {
	mytype carry = 0;
	for (int i = nSize - 1; i >= 0; i--) {
		arr1[i] += arr2[i] + carry;
		if (arr1[i] >= base) {
			arr1[i] -= base;
			carry = 1;
		}
		else carry = 0;
	}
}

void print_e(mytype* arr, mytype nSize) {
	ofstream file("exponent.txt");
	if (!file) {
		cout << "Failed to create file!";
		exit(1);
	}
	file << arr[0] << '.';
	for (mytype i = 1; i < nSize; i++)
		file << setfill('0') << setw(12) << arr[i];
}


int main() {
    /*n - это количество символов*/
	mytype n = 1000000, nSize, k = 1;
	nSize = n / log10(base);
	mytype* e = new mytype[nSize];
	mytype* uk = new mytype[nSize];


	setdata(nSize, e, 1);
	setdata(nSize, uk, 1);
	while (!isZero(nSize, uk)) {
		Div(nSize, uk, k);
		Add(nSize, e, uk);
		k++;
	}
	print_e(e, nSize);

	return 0;
}
