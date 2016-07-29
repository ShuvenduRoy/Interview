#if 0

#include <iostream>
#include <limits>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int minPalPartion(char * str)
{
	int n = strlen(str);
	int *c = new int[n];
	bool **p = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = new bool[n];
	}

	for (int i = 0; i < n; i++)
	{
		c[i] = 0;
		p[i][i] = true;
	}

	for (int l = 2; l <= n; l++)
	{
		for (int i = 0; i < n - l + 1; i++)
		{
			int j = i + l - 1;

			if (l == 2)
				p[i][j] = (str[i] == str[j]);

			else
				p[i][j] = ( (str[i] == str[j]) && p[i + 1][j - 1]);
				
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (p[0][i]==true)
			c[i] = 0;
		else
		{
			c[i] = INT_MAX;
			for (int j = 0; j < i; j++)
			{
				if (p[j+1][i] == true && 1 + c[j] < c[i])
					c[i]=1 + c[j];
			}
		}
	}
	return c[n - 1];

}

int main()
{
	char str[] = "ababbbabbababa";
	printf("Min cuts needed for Palindrome Partitioning is %d",
		minPalPartion(str));
	getchar();
	return 0;
}

#endif