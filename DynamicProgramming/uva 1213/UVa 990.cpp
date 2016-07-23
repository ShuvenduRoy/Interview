#if 0
#include <iostream>
#include <cstdio>
using namespace std;
int  W;

void Path(int** dp, int **temp,int *w,int *v,  int n, int k, int d)
{
	if (n == 0) cout << d << endl;
	else if(temp[n][k]==1)
	{
		Path(dp, temp,w,v, n - 1, k - w[n], d+1);
		cout << ((w[n] / 3) / W) << " " << v[n] << endl;
	}
	else Path(dp, temp, w, v, n - 1, k , d);
}

int main()
{
	int t;int n;
	int test;
	while (scanf("%d %d", &t, &W) == 2)
	{
		
		cin >> n;
		int *v = new int[n+1];
		int *w = new int[n+1];
		for (int i = 1; i <= n; i++)
		{
			cin >> w[i] >> v[i];
			w[i] =w[i]* 3*W;
		}

		int **dp = new int*[n + 1];
		for (int i = 0; i <= n; i++)
			dp[i] = new int[t + 1];

		int **temp = new int*[n + 1];
		for (int i = 0; i <= n; i++)
			temp[i] = new int[t + 1];

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= t; j++)
				dp[i][j] = 0;

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= t; j++)
				temp[i][j] = 0;


		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= t; j++)
			{
				dp[i][j] = dp[i - 1][j];
				if (j >= w[i] && dp[i][j] < v[i] + dp[i - 1][j - w[i]])
				{
					dp[i][j] = v[i] + dp[i - 1][j - w[i]];
					temp[i][j] = 1;
				}
			}
		}

		if (test++)
			puts(" ");
		cout << dp[n][t] << endl;
		Path(dp, temp,w,v, n, t, 0);
	}
}

#endif