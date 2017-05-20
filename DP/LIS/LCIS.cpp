#if 0
#include <iostream>
#include <limits>
using namespace std;


int LCIS(int *arr1, int n, int *arr2, int m)
{
	int *table = new int[m];
	for (int i = 0; i < m; i++)
		table[i] = 0;

	for (int i = 0; i < n; i++)
	{
		int current = 0;
		for (int j = 0; j < m; j++)
		{
			if (arr1[i] == arr2[j] && current + 1 > table[j])
				table[j] = current + 1;
			
			if (arr1[i] > arr2[j] && table[j] > current)
				current = table[j];
		}
	}

	int max = INT_MIN;
	for (int i = 0; i < m; i++)
	{
		if (table[i] > max)
			max = table[i];
	}
	return max;
}

int main()
{
	int arr1[] = { 3, 4, 9, 1 ,10};
	int arr2[] = { 5, 3, 8, 9, 10, 2, 1 };

	int n = sizeof(arr1) / sizeof(arr1[0]);
	int m = sizeof(arr2) / sizeof(arr2[0]);

	cout << "Length of LCIS is "
		<< LCIS(arr1, n, arr2, m) << endl;
	return (0);
}

#endif