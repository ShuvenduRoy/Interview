#if 0
#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int n;
	int degree;
	node *parent;
	node * child;
	node *sibling;
};

class BinomialHeap
{
private:
	node *H;
	node *Hr;
	int count;
public:
	node* Initializeheap();
	void Binomial_link(node *, node *);
	node *Create_node(int);
	node* Union(node*, node*);
	node* Insert(node*, node*);
	node* Merge(node*, node*);
	node* Extract_Min(node*);
	int Revert_list(node*);
	int Display(node*);
	node* Search(node*, int);
	int Decrease_key(node*, int, int);
	int Delete(node*, int);
	BinomialHeap()
	{
		H = Initializeheap();
		Hr = Initializeheap();
		int count = 1;
	}
};


// Initialize an empty heap
node* BinomialHeap::Initializeheap()
{
	node* np = NULL;
	return np;
}

void BinomialHeap::Binomial_link(node *y, node *z)
{
	y->parent = z;
	y->sibling = z->child;
	z->child = y;
	z->degree = z->degree + 1;
}

// create a new node and assign the value
node * BinomialHeap::Create_node(int k)
{
	node* p = new node;
	p->n = k;
	return p;
}


node* BinomialHeap::Union(node* H1, node* H2)
{
	node *H = Initializeheap();
	H = Merge(H1, H2);
	if(H==NULL)
		return H;

	node *prev_x;
	node *next_x;
	node *x;
	prev_x = NULL;
	x = H;
	next_x = x->sibling;

	while (next_x != NULL)
	{
		if ((x->degree != next_x->degree) || ((next_x->sibling != NULL) && (next_x->sibling)->degree == x->degree))
		{
			prev_x = x;
			x = next_x;
			
		}
		else
		{
			if (x->n <= next_x->n)
			{
				x->sibling = next_x->sibling;
				Binomial_link(next_x, x);
			}
			else
			{
				if (prev_x == NULL)
					H = next_x;
				else
					prev_x->sibling = next_x;
				Binomial_link(x, next_x);
				x = next_x;
			}
		}
		next_x = x->sibling;
	}
	return H;
}

node* BinomialHeap::Insert(node* H, node* x)
{
	node *H1 = Initializeheap();
	x->parent = NULL;
	x->child = NULL;
	x->sibling = NULL;
	x->degree = 0;
	H1 = x;
	H = Union(H, H1);
	return H;
}

node* BinomialHeap::Merge(node* h1, node* h2)
{
	node*h = Initializeheap();
	node *y;
	node *z;
	node *a;
	node *b;
	y = h1;
	z = h2;

	if (y != NULL)
	{
		if (z != NULL)
		{
			if (y->degree <= z->degree)
				h = y;
			else if (y->degree > z->degree)
				h = z;
		}
		else h = y;
	}
	else h = z;

	while (y != NULL && z != NULL)
	{
		if (y->degree < z->degree)
		{
			y = y->sibling;
		}
		else if (y->degree == z->degree)
		{
			a = y->sibling;
			y->sibling = z;
			y = a;
		}
		else
		{
			b = z->sibling;
			z->sibling = y;
			z = b;
		}
	}
	return h;
}
//node* Extract_Min(node*);
//int Revert_list(node*);

int BinomialHeap::Display(node* H)
{
	if (H == NULL)
	{
		cout << "The Heap is empty" << endl;
		return 0;
	}
	cout << "The root nodes are: " << endl;
	node* p;
	p = H;
	while (p != NULL)
	{
		cout << p->n;
		if (p->sibling != NULL)
			cout << "-->";
		p = p->sibling;
	}
	cout << endl;
}

//node* Search(node*, int);
//int Decrease_key(node*, int, int);
//int Delete(node*, int);

int main()
{
	int n, m, l, i;
	BinomialHeap bh;
	node* p;
	node *H;
	H = bh.Initializeheap();
	char ch;
	while (1)
	{
		cout << "----------------------------" << endl;
		cout << "Operations on Binomial heap" << endl;
		cout << "----------------------------" << endl;
		cout << "1)Insert Element in the heap" << endl;
		cout << "2)Extract Minimum key node" << endl;
		cout << "3)Decrease key of a node" << endl;
		cout << "4)Delete a node" << endl;
		cout << "5)Display Heap" << endl;
		cout << "6)Exit" << endl;
		cout << "Enter Your Choice: ";
		cin >> l;
		switch (l)
		{
		case 1:
			cout << "Enter the element to be inserted: ";
			cin >> m;
			p = bh.Create_node(m);
			H = bh.Insert(H, p);
			break;
		/*case 2:
			p = bh.Extract_Min(H);
			if (p != NULL)
				cout << "The node with minimum key: " << p->n << endl;
			else
				cout << "Heap is empty" << endl;
			break;*/
		case 3:
			cout << "Enter the key to be decreased: ";
			cin >> m;
			cout << "Enter new key value: ";
			cin >> l;
			//bh.Decrease_key(H, m, l);
			break;
		case 4:
			cout << "Enter the key to be deleted: ";
			cin >> m;
			//bh.Delete(H, m);
			break;
		case 5:
			cout << "The Heap is: " << endl;
			bh.Display(H);
			break;
		case 6:
			exit(1);
		default:
			cout << "Wrong Choice";
		}
	}
	return 0;
}

#endif