#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};


Node* Insert(Node* root,int data)
{
    Node *temp= new Node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;

   if(root==NULL)
        root=temp;

    else if(data<=root->data)
    {
        root->left=Insert(root->left,data);
    }
    else
    {
        root->right=Insert(root->right,data);
    }
    return root;
}

void Inorder(Node* temp)
{
    if(temp==NULL) return;
    Inorder(temp->left);
    cout<<temp->data<<" ";
    Inorder(temp->right);
}

int main()
{
    Node* head=NULL;

    head=Insert(head,15);
    head=Insert(head,5);
    head=Insert(head,10);
    head=Insert(head,25);
    head=Insert(head,1);

    Inorder(head);
}
