#if 0

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool prevPermutation(string &str)
{
	int n = str.length() - 1;

	//i is any large number sitting right to a small number(i-1) searching from right
	//This small number will be swaped
	// with the smallest number bigger than that
	int i = n;
	while (i > 0 && str[i - 1] >= str[i])
		i--;

	if (i <= 0)
		return false;


	//so, i-1 is one member of swap(_._) function
	//let's search other (j)
	//obviously i is the first candidate as it is greater than i-1. so we initialize j with i

	int j = i;
	for (int k = i+1; k <= n; k++)
	{
		if (str[k] > str[i - 1] && str[k]<str[j])
			j = k;
	}

	swap(str[j], str[i - 1]);
	reverse(str.begin() + i, str.end());

	return true;
}

// Driver code
int main()
{
	string str = "12233";

	
	while (1)
	{
		if (prevPermutation(str))
			cout << "Next permutation is " << str << endl;
		else
			break;
	}
	return 0;
}

#endif