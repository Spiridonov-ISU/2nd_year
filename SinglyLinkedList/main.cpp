#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List<int> lst;
	lst.pushFront(5);
	lst.pushFront(7);
	lst.pushFront(101);

	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "popBack " << endl << endl;

	lst.popBack();

	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << endl;
	}

	return 0;
}