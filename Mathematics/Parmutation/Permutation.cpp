#if 0
#include <iostream>
#include <cmath>
using namespace std;

void swap(char *a, char *b)
{
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void permute(char *s, int l, int r)
{
	if (l == r)
		cout << s << endl;
	for (int i = l; i <= r; i++)
	{
		swap((s + l), (s + i));
		permute(s, l + 1, r);
		swap((s + l), (s + i));
	}
}

int main()
{
	char str[] = "ABC";
	int n = strlen(str);
	permute(str, 0, n - 1);
	getchar();
	return 0;
}
#endif