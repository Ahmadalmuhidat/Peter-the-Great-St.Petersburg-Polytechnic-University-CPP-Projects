#ifndef __BINARY_SEARCH_TREE
#define __BINARY_SEARCH_TREE
#include <vector>

template <typename T>
struct Node
{
	T data;
	Node<T> *left;
	Node<T> *right;
};

template <typename T>
class BST
{
private:
	Node<T> *rootptr;
	static int Count;

	void PrintInOrderPrivet(Node<T> *ptr);

	void AddNodePrivet(T val, Node<T> *ptr);

	Node<T> *searchPrivet(Node<T> *ptr, T data);

	int FindSmallestPrivet(Node<T> *ptr);

	void RemoveNodePrivet(T val, Node<T> *ptr);

	void printLevelOrder(struct Node<T> *root);

	void printGivenLevel(struct Node<T> *root, int level);

public:
	// main methods
	BST();

	bool isEmpty();

	Node<T> *CreateNode(T val);

	void AddNode(T val);

	void PrintInOrder();

	bool checkptr(Node<T> *ptr);

	void NodeInfo(T val);

	Node<T> *Search(T val);

	int count();

	//Remove methods
	void RemoveNode(T val);

	void RemoveMatch(Node<T> *parent, Node<T> *match, bool left);

	void RemoveRootMatch();

	// Printing methods
	int height(Node<T> *root);

	void reverseLevelOrder();

	void PrintAsTree();
};

#endif