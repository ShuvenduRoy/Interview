#if 0
#include<iostream>
#include <cstdlib>
#include<cstring>
using namespace std;

#define ARRAY_SIZE(a)  sizeof(a)/sizeof(a[0])
#define ALPHABATE_SIZE (26)
#define CHAR_TO_INDEX(c)	((int)c-(int)'a')

struct TrieNode
{
	TrieNode* children[ALPHABATE_SIZE];
	bool isLeaf;
};

TrieNode *getNode()
{
	TrieNode *pNode = new TrieNode();
	for (int i = 0; i < ALPHABATE_SIZE; i++)
		pNode->children[i] = NULL;
	pNode->isLeaf = false;

	return pNode;
}

void insert(TrieNode* root, char* key)
{
	int length = strlen(key);
	TrieNode* p = root;

	for (int level = 0; level < length; level++)
	{
		int index = CHAR_TO_INDEX(key[level]);
		if (!p->children[index])
			p->children[index] = getNode();
		p = p->children[index];
	}
	p->isLeaf = true;
}

bool search(TrieNode* root, char* key)
{
	int length = strlen(key);
	TrieNode* p = root;

	for (int level = 0; level < length; level++)
	{
		int index = CHAR_TO_INDEX(key[level]);
		if (!p->children[index])
			return false;
		p = p->children[index];
	}
	return (p != NULL && p->isLeaf);
}

int main()
{
	char keys[][8] = { "the","a","there","answer","any","by","bye","their" };
	char output[][32] = { "Not present in trie","Present in trie" };

	struct TrieNode* root = getNode();
	for (int i = 0; i < ARRAY_SIZE(keys); i++)
		insert(root, keys[i]);

	cout << output[search(root, "the")] << endl;
	cout << output[search(root, "these")] << endl;
	cout << output[search(root, "their")] << endl;
	cout << output[search(root, "thaw")] << endl;
	
	getchar();
	return 0;
}

#endif