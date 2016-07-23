# if 0
#include <iostream>
using namespace std;


int main()
{
	int input[][4] = { { 2,0,-3,4 },{ 6, 3, 2, -1 },{ 5, 4, 7, 3 },{ 2, -6, 8, 1 } };
	int T[5][5] = { 0 };
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			T[i][j] = T[i - 1][j] + T[i][j - 1] - T[i - 1][j - 1] + input[i - 1][j - 1];
		}
	}

	int r1 = 1, c1 = 1, r2 = 2, c2 = 2;
	r1++;
	r2++;
	c1++;
	c2++;

	cout << T[r2][c2] - T[r1-1][c2] - T[r2][c1 - 1] + T[r1 - 1][c1 - 1] << endl;

}

#endif