// add1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>
#include "print.h"
using namespace std;

class AddValue
{
	int theValue;
public:
	AddValue(int value) :theValue(value) {

	}

	void operator() (int &elem) const {
		elem += theValue;
	}
};

int main()
{
	list<int> coll;

	for (int i = 1; i <= 9; i++)
	{
		coll.push_back(i);
	}

	PRINT_ELEMENT(coll, "Initialized: ");
	for_each(coll.begin(), coll.end(), AddValue(10));
	PRINT_ELEMENT(coll, "After: ");
	for_each(coll.begin(), coll.end(), AddValue(*coll.begin()));
	PRINT_ELEMENT(coll, "After that: ");

	getchar();
    return 0;
}

