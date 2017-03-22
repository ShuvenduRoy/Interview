#if 0
#include<iostream>
#include<limits.h>
#include <stdio.h>
#define ROW 4
using namespace std;


int Kadane(int* arr)
{
	int end = -1;
	int local_max = INT_MIN;
	int sum = 0;
	int local_start = 0;

	for (int i = 0; i < ROW; i++)
	{
		sum += arr[i];
		if (sum < 0)
		{
			sum = 0;
			local_start = i + 1;
		}
		else if (sum > local_max)
		{
			local_max = sum;
			end = i;
		}
	}

	if (end != -1)
		return local_max;

	local_max = arr[0];

	for (int i = 0; i < ROW; i++)
	{
		if (arr[i] > local_max)
		{
			local_max = arr[i];
		}
	}
	return local_max;
}

int main()
{
	int arr[4] = { -4,5,-2,5 };
	cout << Kadane(arr) << endl;
}

#endif