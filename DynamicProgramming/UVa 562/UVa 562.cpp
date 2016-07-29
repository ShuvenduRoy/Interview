#if 0
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
	int Nm, x, i;
	cin >> Nm;
	for (x = 0; x < Nm; x++)
	{
		int n;
		cin >> n;
		int *arr = new int[n];
		int sum = 0;
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}
		int s = sum / 2;
		bool *v = new bool[s + 1];
		for (int i = 0; i <= s; i++)
			v[i] = false;
		v[0] = true;

		for (i = 0; i < n; i++)
		{
			for (int j = s; j > 0; j--)
			{
				if (!v[j])
				{
					v[j] = (arr[i] <= j) ? v[j - arr[i]] : false;
				}
			}
		}

		for (i = s; i > 0; i--)
		{
			if (v[i]) break;
		}

		cout << abs(sum - 2 * i )<< endl;
	}
}


#endif
