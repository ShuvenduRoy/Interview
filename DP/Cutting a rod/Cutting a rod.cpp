//  http://www.radford.edu/~nokie/classes/360/dp-rod-cutting.html

#if 0
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

/*int cutRod(int arr[], int n)
{
	if (n <= 0) return 0;
	int max_val = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		max_val = max(max_val, arr[i]+cutRod(arr, n - i - 1));
	}
	return max_val;
}*/

int cutRod(int arr[], int n)
{
	int *val = new int[n + 1];
	val[0] = 0;

	for (int i = 1; i < n + 1; i++)
	{
		int maxi = INT_MIN;
		for (int j = 0; j < i; j++)
		{
			maxi = max(maxi, arr[j] + val[i - j - 1]);
		}
		val[i] = maxi;
	}

	return val[n];
}

int main()
{
	int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
	getchar();
	return 0;
}


#endif