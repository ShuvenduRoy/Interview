#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	ifstream inf("output.txt");
	if (!inf)
	{
		cout << "Error";
		exit(1);
	}

	while (inf)
	{
		string s;
		getline(inf, s);
		cout << s << endl;
	}

	getchar();
}
