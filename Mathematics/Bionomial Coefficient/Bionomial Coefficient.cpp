#if 0
#include <iostream>
#include <cmath>
using namespace std;

int binomialCoeff(int n, int k)
{
	int res = 1;
	if (k > n - k)
		k = n - k;
	for (int i = 0; i < k; i++)
	{
		res *= (n - i);
		res /= (i + 1);
	}
	return res;
}

int main()
{
	int n = 8, k = 2;
	printf("Value of C(%d, %d) is %d ", n, k, binomialCoeff(n, k));
	getchar();
	return 0;
}


#endif