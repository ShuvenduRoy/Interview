#if 0
#include <iostream>
using namespace std;

int AreAll9s(int* num, int n)
{
	int i;
	for (i = 0; i < n; ++i)
		if (num[i] != 9)
			return 0;
	return 1;
}

/* Utility that prints out an array on a line */
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void generateNextPalindromeUtil(int num[], int n)
{
	int mid = n / 2;
	bool leftsml = false;
	int i = mid - 1;
	int j = (n % 2) ? mid + 1 : mid;

	while (i>=0 && num[i]==num[j])
	{
		i--; j++;
	}
	if (i < 0 || num[i] < num[j])
		leftsml = true;

	while (i >= 0)
	{
		num[j] = num[i];
		j++;
		i--;
	}

	// Handle the case where middle digit(s) must be incremented. 
	// This part of code is for CASE 1 and CASE 2.2
	if (leftsml == true)
	{
		int carry = 1;
		i = mid - 1;

		// If there are odd digits, then increment
		// the middle digit and store the carry
		if (n % 2 == 1)
		{
			num[mid] += carry;
			carry = num[mid] / 10;
			num[mid] %= 10;
			j = mid + 1;
		}
		else
			j = mid;

		// Add 1 to the rightmost digit of the left side, propagate the carry 
		// towards MSB digit and simultaneously copying mirror of the left side 
		// to the right side.
		while (i >= 0)
		{
			num[i] += carry;
			carry = num[i] / 10;
			num[i] %= 10;
			num[j++] = num[i--]; // copy mirror to right
		}
	}
}

void generateNextPalindrome(int num[], int n)
{
	int i;

	printf("\nNext palindrome is:\n");

	// Input type 1: All the digits are 9, simply o/p 1
	// followed by n-1 0's followed by 1.
	if (AreAll9s(num, n))
	{
		printf("1 ");
		for (i = 1; i < n; i++)
			printf("0 ");
		printf("1");
	}

	// Input type 2 and 3
	else
	{
		generateNextPalindromeUtil(num, n);

		// print the result
		printArray(num, n);
	}
}

// Driver Program to test above function
int main()
{
	int num[] = { 9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2 };

	int n = sizeof(num) / sizeof(num[0]);

	generateNextPalindrome(num, n);
	getchar();
	return 0;
}

#endif