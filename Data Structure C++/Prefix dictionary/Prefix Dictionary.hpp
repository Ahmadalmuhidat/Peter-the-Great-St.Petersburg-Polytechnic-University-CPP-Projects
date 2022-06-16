#ifndef __Prefix_Dictionary
#define __Prefix_Dictionary
// Define the character size
#define CHAR_SIZE 128
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;

struct Node
{
	int prefix_count;
	bool isWord;
	Node *children[26];
};

class Dictionary
{
public:
	Node *head;

	Dictionary();

	void insert(string word);

	bool search(string word);

	int words_with_prefix(string prefix);
};

// Returns new trie node (initialized to NULLs)
Node *getNode();

bool isEmpty(Node *root);

Node *Remove(Node *root, string key, int depth = 0);

#endif