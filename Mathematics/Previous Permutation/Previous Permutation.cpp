/ C++ program to print all permutations with
// duplicates allowed using prev_permutation()
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// Function to compute the previous permutation
bool prevPermutation(string &str)
{
	// Find index of the last element of the string
	int n = str.length() - 1;

	int i = n;
	while (i > 0 && str[i - 1] <= str[i])
		i--;

	if (i <= 0)
		return false;

	int j = i - 1;
	while (j + 1 <= n && str[j + 1] <= str[i - 1])
		j++;

	swap(str[j], str[i - 1]);
	reverse(str.begin()+i, str.end());

	return true;
}

// Driver code
int main()
{
	string str = "4321";
	while(1)
	{
		if (prevPermutation(str))
			cout << "Previous permutation is " << str << endl;
		else
			break;
	}
	return 0;
}
