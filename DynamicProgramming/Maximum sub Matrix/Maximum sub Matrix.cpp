#if 0
#include<iostream>
#include<limits.h>
#include <stdio.h>
#define ROW 4
#define COL 5

int Kadane(int* arr, int *start, int *end)
{
	*end = -1;
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
			*start = local_start;
			*end = i;
		}
	}
	
	if (*end != -1)
		return local_max;

	local_max = arr[0];
	*start = *end = 0;
	for (int i = 0; i < ROW; i++)
	{
		if (arr[i] > local_max)
		{
			local_max = arr[i];
			*start = *end = i;
		}
	}
	return local_max;
}

void findMaxSum(int m[][COL])
{
	int maxSum = INT_MIN;
	int  finalLeft, finalRight, finalTop, finalBottom;
	int start, finish;
	int left, right, i;
	int sum;
	int temp[ROW];



	for ( left = 0; left < COL;++ left)
	{
		memset(temp,0,sizeof(temp));
		for ( right = left; right < COL; ++right)
		{
			for ( i = 0; i < ROW; ++i)
			{
				temp[i] += m[i][right];
			}

			sum = Kadane(temp, &start, &finish);
			if (sum > maxSum)
			{
				maxSum = sum;
				finalLeft = left;
				finalRight = right;
				finalTop = start;
				finalBottom = finish;
			}
		}
	}

	// Print final values
	printf("(Top, Left) (%d, %d)\n", finalTop, finalLeft);
	printf("(Bottom, Right) (%d, %d)\n", finalBottom, finalRight);
	printf("Max sum is: %d\n", maxSum);
}

int main()
{
	int M[ROW][COL] = { { 1, 2, -1, -4, -20 },
	{ -8, -3, 4, 2, 1 },
	{ 3, 8, 10, 1, 3 },
	{ -4, -1, 1, 7, -6 }
	};

	findMaxSum(M);

	getchar();
	return 0;
}

#endif