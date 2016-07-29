#if 0
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void Wildcard(char *text, char* patern)
{
	int n = strlen(text) + 1;
	int m = strlen(patern) + 1;

	bool **T = new bool*[n];
	for (int i = 0; i < n; i++)
		T[i] = new bool[m];

	T[0][0] = true;

	if (patern[0] == '*') {
		T[0][1] = true;
	}


	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (text[i - 1] == patern[j - 1] || patern[j - 1] == '?')
				T[i][j] = T[i - 1][j - 1];
			else if (patern[j - 1] == '*')
			{

					T[i][j] = T[i][j-1] || T[i - 1][j];
			}
			else T[i][j] = false;
		}
	}
	cout << T[n - 1][m - 1];
}

int main()
{
	Wildcard("xbylmz", "x?y*z");
	getchar();
}


#endif