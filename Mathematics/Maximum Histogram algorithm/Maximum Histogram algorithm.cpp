# if 0
#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

int histogram(int *input, int n)
{
	int maxArea = INT_MIN;
	stack<int> s;
	int area;
	int top;
	int x;
	int i;
	for (i = 0; i < n; )
	{
		if (!s.empty())
			x = s.top();

		if (s.empty() || input[i] >= input[x])
		{
			s.push(i++);
		}
		else
		{
			top = s.top();
			s.pop();

			if (s.empty())
			{
				area = input[top] * i;
			}
			else
			{
				area = input[top] * (i - s.top() - 1);
			}
			if (area > maxArea)
				maxArea = area;
		}
	}
	while (!s.empty())
	{
		int area;
		int top = s.top();
		s.pop();

		if (s.empty())
		{
			area = input[top] * i;
		}
		else
		{
			area = input[top] * (i - s.top() - 1);
		}
		if (area > maxArea)
			maxArea = area;
	}

	return maxArea;
}

int main()
{
	int input[] = { 2,2,2,6,1,5,4,2,2,2,2 };
	cout << histogram(input, 11);
}

#endif
