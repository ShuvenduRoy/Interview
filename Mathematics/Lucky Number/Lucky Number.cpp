#if 0
#include <iostream>
#include <cmath>
using namespace std;

bool isLucky(int  n)
{
	int counter = 2;
	while (1)
	{
		if (counter > n) return true;
		if (n%counter == 0) return false;
		n -= n / 2;
		counter++;
	}
}

int main()
{
	int x = 19;
	if (isLucky(x))
		printf("%d is a lucky no.", x);
	else
		printf("%d is not a lucky no.", x);
	getchar();
}

#endif