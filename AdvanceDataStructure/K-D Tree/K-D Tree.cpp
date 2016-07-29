#if 0
#include<iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	int arr[2];
	node* left;
	node *right;
};

node* newNode(int* points)
{
	node* temp = new node();
	for (int i = 0; i < 2; i++)
		temp->arr[i] = points[i];

	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

bool arePointsSame(int point1[], int point2[])
{
	// Compare individual pointinate values
	for (int i = 0; i < 2; ++i)
		if (point1[i] != point2[i])
			return false;

	return true;
}


bool searchRec(node* root, int point[], unsigned depth)
{
	// Base cases
	if (root == NULL)
		return false;
	if (arePointsSame(root->arr, point))
		return true;

	// Current dimension is computed using current depth and total
	// dimensions (k)
	unsigned cd = depth % 2;

	// Compare point with root with respect to cd (Current dimension)
	if (point[cd] < root->arr[cd])
		return searchRec(root->left, point, depth + 1);

	return searchRec(root->right, point, depth + 1);
}

// Searches a Point in the K D tree. It mainly uses
// searchRec()
bool search(node* root, int point[])
{
	// Pass current depth as 0
	return searchRec(root, point, 0);
}

node* insertUtil(node* root, int * points, int d)
{
	if (root == NULL)
		return newNode(points);
	d = d % 2;

	if (points[d] < root->arr[d])
		root->left = insertUtil(root->left, points, d+1);
	else
		root->right = insertUtil(root->right, points, d+1);
	return root;
}


node* insert(node* root, int *points)
{
	return insertUtil(root, points, 0);
}

int main()
{
	struct node *root = NULL;
	int points[][2] = { { 3, 6 },{ 17, 15 },{ 13, 15 },{ 6, 12 },
	{ 9, 1 },{ 2, 7 },{ 10, 19 } };

	int n = sizeof(points) / sizeof(points[0]);

	for (int i = 0; i<n; i++)
		root = insert(root, points[i]);

	int point1[] = { 10, 19 };
	(search(root, point1)) ? cout << "Found\n" : cout << "Not Found\n";

	int point2[] = { 12, 19 };
	(search(root, point2)) ? cout << "Found\n" : cout << "Not Found\n";

	getchar();
	return 0;
}

#endif