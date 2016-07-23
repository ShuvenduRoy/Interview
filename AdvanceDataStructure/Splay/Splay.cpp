#if 0
#include <iostream>
#include <stdlib.h>
struct node
{
	int key;
	node *left;
	node *right;
};

node *newNode(int key)
{
	node * temp = new node();
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

node *rightRotate(node *x)
{
	node *y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}

node *leftRotate(node *x)
{
	node *y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

node *splay(node* root, int key)
{
	if (root == NULL || root->key == key)
		return root;
	if (key < root->key)
	{
		if (root->left == NULL) return root;

		if (key < root->left->key)
		{
			//left left
			root->left->left = splay(root->left->left, key);
			root = rightRotate(root);
		}
		else if (key > root->left->key)
		{
			//left right 
			root->left->right = splay(root->left->right, key);
			if (root->left->right != NULL)
				root->left = leftRotate(root->left);
		}

		return (root->left == NULL) ? root : rightRotate(root);
	}
	else // Key lies in right subtree
	{
		// Key is not in tree, we are done
		if (root->right == NULL) return root;

		// Zag-Zig (Right Left)
		if (root->right->key > key)
		{
			// Bring the key as root of right-left
			root->right->left = splay(root->right->left, key);

			// Do first rotation for root->right
			if (root->right->left != NULL)
				root->right = rightRotate(root->right);
		}
		else if (root->right->key < key)// Zag-Zag (Right Right)
		{
			// Bring the key as root of right-right and do first rotation
			root->right->right = splay(root->right->right, key);
			root = leftRotate(root);
		}

		// Do second rotation for root
		return (root->right == NULL) ? root : leftRotate(root);
	}
}

struct node *search(struct node *root, int key)
{
	return splay(root, key);
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

/* Drier program to test above function*/
int main()
{
	struct node *root = newNode(100);
	root->left = newNode(50);
	root->right = newNode(200);
	root->left->left = newNode(40);
	root->left->left->left = newNode(30);
	root->left->left->left->left = newNode(20);

	root = search(root, 20);
	printf("Preorder traversal of the modified Splay tree is \n");
	preOrder(root);
	return 0;
}

#endif