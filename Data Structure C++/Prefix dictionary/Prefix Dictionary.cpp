#define CHAR_SIZE 128
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "Prefix Dictionary.h"

using namespace std;

Dictionary::Dictionary()
{
	head = new Node();
	head->isWord = false;
	head->prefix_count = 0;
}

void Dictionary::insert(string word)
{
	Node *current = head;
	current->prefix_count++;

	for (int i = 0; i < word.length(); ++i)
	{
		//extract first character of word
		int letter = word[i] - 'a';

		if (current->children[letter] == NULL)
		{
			current->children[letter] = new Node();
		}

		current->children[letter]->prefix_count++;
		current = current->children[letter];
	}
	current->isWord = true;
}

bool Dictionary::search(string word)
{
	Node *current = head;
	for (int i = 0; i < word.length(); ++i)
	{
		int letter = (int)word[i] - (int)'a';
		if (current->children[letter] == NULL)
		{
			//retrun false not found
			return false; 
		}

		current = current->children[letter];
	}
	return current->isWord;
}

int Dictionary::words_with_prefix(string prefix)
{
	Node *current = head;
	for (int i = 0; i < prefix.length(); ++i)
	{
		int letter = (int)prefix[i] - (int)'a';
		if (current->children[letter] == NULL)
		{
			return 0;
		}
		else
		{
			current = current->children[letter];
		}
	}
	return current->prefix_count;
}

// Returns true if root has no children, else false
bool isEmpty(Node *root)
{
	for (int i = 0; i < CHAR_SIZE; i++)
		if (root->children[i])
		{
			return false;
		}

	return true;
}

Node *getNode()
{
	Node *pNode = new Node;

	pNode->isWord = false;

	for (int i = 0; i < CHAR_SIZE; i++)
	{
		pNode->children[i] = NULL;
	}
	return pNode;
}

Node *Remove(Node *root, string key, int depth)
{

	if (root == NULL)
	{
		return NULL;
	}

	if (depth == key.size())
	{
		if (root->isWord)
		{
			root->isWord = false;
		}

		if (isEmpty(root))
		{
			delete (root);
			root = NULL;
		}

		return root;
	}

	// If not last character, recur for the child
	// obtained using ASCII value
	int index = key[depth] - 'a';
	root->children[index] = Remove(root->children[index], key, depth + 1);

	// If root does not have any child (its only child got
	// deleted), and it is not end of another word.
	if (isEmpty(root) && root->isWord == false)
	{
		delete (root);
		root = NULL;
	}

	return root;
}
