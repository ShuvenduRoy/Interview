#if 0
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<string>
using namespace std;

int cmp(const void* a, const void *b)
{
	return (*(char*)a > *(char*)b);
}

void swp(char* a, char* b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

int ceilIdx(char *str, char start, int l, int r)
{
	int ceilIndex = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (str[i] > start && str[i] < str[ceilIndex])
			ceilIndex = i;
	}
	return ceilIndex;
}

void sortedPermutations(char* str)
{
	int n = strlen(str);
	bool isFinished = false;
	qsort(str, n, sizeof(str[0]), cmp);

	while (!isFinished)
	{
		int i;
		cout << str << endl;
		for (i = n - 2; i >= 0; i--)
		{
			if (str[i] < str[i + 1])
				break;
		}

		if (i == -1)
			isFinished = true;

		else
		{
			int j = ceilIdx(str, str[i], i + 1, n - 1);
			swp(&str[i], &str[j]);
			qsort(str + i + 1, n - i - 1, sizeof(str[0]), cmp);
		}

	}
}

int main()
{
	char str[] = "ABCD";
	sortedPermutations(str);
	getchar();
	return 0;
}


#endif