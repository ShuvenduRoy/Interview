#if 0
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

struct node
{
	int key;
	node* left;
	node* right;
	int height;
};

int height(node* root)
{
	if (root == NULL)
		return 0;
	return root->height;
}

node* newNode(int key)
{
	node* temp = new node();
	temp->key = key;
	temp->left = temp->right = NULL;
	temp->height = 1;
	return temp;
}

node* rightRotate(node* y)
{
	node* x = y->left;
	node* T2 = x->left;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

struct node *leftRotate(struct node *x)
{
	struct node *y = x->right;
	struct node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	//  Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// Return new root
	return y;
}

int getBalance(struct node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct node* insert(struct node* node, int key)
{
	/* 1.  Perform the normal BST rotation */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	/* 2. Update height of this ancestor node */
	node->height = max(height(node->left), height(node->right)) + 1;

	/* 3. Get the balance factor of this ancestor node to check whether
	this node became unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

void preOrder(struct node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
	struct node *root = NULL;

	/* Constructing tree given in the above figure */
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);

	/* The constructed AVL Tree would be
	30
	/  \
	20   40
	/  \     \
	10  25    50
	*/

	printf("Pre order traversal of the constructed AVL tree is \n");
	preOrder(root);

	return 0;
}

#endif