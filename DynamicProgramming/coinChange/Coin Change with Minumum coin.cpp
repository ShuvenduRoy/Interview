#if 0
#include<iostream>
#include<limits.h>
using namespace std;

void Print(int *arr, int *R, int n, int total)
{
	if (R[total - 1] == -1)
		cout << "There is no solution" << endl;

	int start = total;
	while (start != 0)
	{
		int j = R[start];
		cout << arr[j] << " ";
		start -= arr[j];
	}
}

int CoinChange(int *arr, int n, int total)
{
	int *temp = new int[total + 1];
	int *R = new int[total + 1];
	for (int i = 0; i <= total; i++)
	{
		temp[i] = INT_MAX-100;
		R[i] = -1;
	}
	temp[0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= total; j++)
		{
			if (j >= arr[i])
			{
				if ( temp[j - arr[i]] + 1<temp[j])
				{
						temp[j] = temp[j - arr[i]] + 1;
						R[j] = i;
				}
			}
		}
	}
	Print(arr, R,n,total);
	return temp[total];
}

int main()
{
	int total = 13;
	int coins[] = { 7, 3, 2, 6 };

	cout<<endl<<"Total number of coin "<<CoinChange(coins, 4, total) << endl;
	getchar();
}


#endif