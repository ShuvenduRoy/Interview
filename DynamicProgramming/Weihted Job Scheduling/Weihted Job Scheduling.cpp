#if 0
#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

struct Job
{
	int start, finish, profit;
};

int lastNonConflict(Job arr[], int i)
{
	for (int j = i - 1; j >= 0; j--)
	{
		if (arr[j].finish <= arr[i].start)
			return j;
	}
	return -1;
}

bool jobComparataor(Job s1, Job s2)
{
	return (s1.finish < s2.finish);
}

int findMaxProfit(Job arr[], int n)
{
	sort(arr, arr + n, jobComparataor);

	int *table = new int[n];
	for (int i = 0; i < n; i++)
		table[i] = arr[i].profit;

	for (int i = 1; i < n; i++)
	{
		
			int l = lastNonConflict(arr, i);
			if (l != -1)
				table[i] += table[l];
			table[i] = max(table[i - 1], table[i]);
		
	}
	return table[n - 1];
}

int main()
{
	Job arr[] = { { 3, 10, 20 },{ 1, 2, 50 },{ 6, 19, 100 },{ 2, 100, 200 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The optimal profit is " << findMaxProfit(arr, n) << endl;
	return 0;
}

#endif