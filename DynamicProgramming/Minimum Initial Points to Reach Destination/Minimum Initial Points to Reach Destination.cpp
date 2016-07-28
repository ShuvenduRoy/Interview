#if 0
#include<iostream>
#include <limits>
#include <algorithm>
#include <math.h>
using namespace std;
#define R 3
#define C 3

int minInitialPoints(int points[][C])
{
	int **table = new int*[R];
	for (int i = 0; i < R; i++)
		table[i] = new int[C];

	table[R - 1][C - 1] = points[R - 1][C - 1] > 0 ? 1 : abs(points[R - 1][C - 1]) + 1;
	for (int i = R - 2; i >= 0; i--)
		table[i][C - 1] =max( table[i + 1][C - 1] - points[i][C - 1],1);
	for (int j = C - 2; j >= 0; j--)
		table[R - 1][j] = max(table[R - 1][j + 1] - points[R - 1][j], 1);

	for (int i = R - 2; i >= 0; i--)
	{
		for (int j = C - 2; j >= 0; j--)
		{
			int min_points_on_exit = min(table[i + 1][j], table[i][j + 1]);
			table[i][j] = max(min_points_on_exit - points[i][j], 1);
		}
	}

	return table[0][0];

}

int main()
{

	int points[R][C] = { { -2,-3,3 },
	{ -5,-10,1 },
	{ 10,30,-5 }
	};
	cout << "Minimum Initial Points Required: "
		<< minInitialPoints(points) << endl;
	return 0;
}

#endif