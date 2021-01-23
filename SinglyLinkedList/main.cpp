#include <iostream>
#include "List.h"

using namespace std;

int main() {
	List<int> lst;
	lst.pushBack(5);
	lst.pushBack(7);
	lst.pushBack(32);
	lst.pushFront(101);
	for (int i = 0; i < lst.getSize(); i++) {
		cout << lst[i] << " ";
	}

	cout << "\n\n" << "popBack " << endl;
	lst.popBack();
	for (int i = 0; i < lst.getSize(); i++) {
		cout << lst[i] << " ";
	}

	cout << "\n\n" << "removeAt 1" << endl;
	lst.removeAt(1);
	for (int i = 0; i < lst.getSize(); i++) {
		cout << lst[i] << " ";
	}

	cout << "\n\n" << "removeAt 1" << endl;
	lst.insert(3425, 1);
	for (int i = 0; i < lst.getSize(); i++) {
		cout << lst[i] << " ";
	}
	return 0;
}