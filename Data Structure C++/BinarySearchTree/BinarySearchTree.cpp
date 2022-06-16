#include <iostream>
#include <vector>
#include "BinarySearchTree.h"

// Privet
template <typename T>
void BST<T>::PrintInOrderPrivet(Node<T> *ptr)
{
	if (isEmpty())
	{
		std::cout << "nothing to print" << std::endl;
	}
	if (ptr->left != nullptr)
	{
		PrintInOrderPrivet(ptr->left);
	}
	std::cout << ptr->data << " ";
	if (ptr->right != nullptr)
	{
		PrintInOrderPrivet(ptr->right);
	}
}

template <typename T>
void BST<T>::AddNodePrivet(T val, Node<T> *ptr)
{
	if (isEmpty())
	{
		rootptr = CreateNode(val);
		Count++;
		//std::cout << val << " top" << std::endl;
	}
	else if (val < ptr->data) // left insert
	{
		if (ptr->left == nullptr)
		{
			ptr->left = CreateNode(val);
			Count++;
			// << val << " left" << std::endl;
		}
		else
		{
			AddNodePrivet(val, ptr->left);
		}
	}
	else if (val > ptr->data) // right insert
	{
		if (ptr->right == nullptr)
		{
			ptr->right = CreateNode(val);
			Count++;
			//std::cout << val << " right" << std::endl;
		}
		else
		{
			AddNodePrivet(val, ptr->right);
		}
	}
	else
	{
		std::cout << val << " has been already inserted to the tree" << std::endl;
	}
}

template <typename T>
Node<T> *BST<T>::searchPrivet(Node<T> *ptr, T key)
{
	if (ptr != NULL)
	{
		// Base Cases: root is null or key is present at root
		if (ptr->data == key)
		{
			std::cout << key << " found" << std::endl;
			return ptr;
		}
		// Key is greater than root's key
		if (ptr->data < key)
		{
			return searchPrivet(ptr->right, key);
		}
		// Key is smaller than root's key
		return searchPrivet(ptr->left, key);
	}
	else
	{
		return NULL;
	}
}

template <typename T>
int BST<T>::FindSmallestPrivet(Node<T> *ptr)
{
	if (isEmpty())
	{
		return -1000;
	}
	else
	{
		if (ptr->left != nullptr)
		{
			return FindSmallestPrivet(rootptr->left);
		}
		else
		{
			return ptr->data;
		}
	}
}

template <typename T>
void BST<T>::RemoveNodePrivet(T val, Node<T> *ptr)
{
	if (!isEmpty())
	{
		if (ptr->data == rootptr->data)
		{
			if (rootptr->data == val)
			{
				RemoveRootMatch();
			}
			else
			{
				if (ptr->data > val && ptr->left != nullptr)
				{
					/*ptr->left->data == val ?*/
					RemoveMatch(ptr, ptr->left, true);
					RemoveNodePrivet(val, ptr->left);
				}
				else if (ptr->data > val && ptr->right != nullptr)
				{
					/*ptr->left->data == val ?*/
					RemoveMatch(ptr, ptr->right, false);
					RemoveNodePrivet(val, ptr->right);
				}
				else
				{
					std::cout << "The val" << val << " were not found" << std::endl;
				}
			}
		}
	}
	else
	{
		std::cout << "tree is empty" << std::endl;
	}
}

// Public

// main methods
template <typename T>
BST<T>::BST()
{
	rootptr = nullptr;
}

template <typename T>
bool BST<T>::isEmpty()
{
	if (rootptr == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
Node<T> *BST<T>::CreateNode(T val)
{
	Node<T> *NewNode = new Node<T>;
	NewNode->data = val;
	NewNode->left = nullptr;
	NewNode->right = nullptr;
	return NewNode;
}

template <typename T>
void BST<T>::AddNode(T val)
{
	AddNodePrivet(val, rootptr);
}

template <typename T>
void BST<T>::PrintInOrder()
{
	PrintInOrderPrivet(rootptr);
}

template <typename T>
bool BST<T>::checkptr(Node<T> *ptr)
{
	if (ptr != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
void BST<T>::NodeInfo(T val)
{
	Node<T> *ptr = Search(val);
	if (ptr == NULL)
	{
		std::cout << " not in tree" << std::endl;
	}
	else
	{
		std::cout << "    " << ptr->data << std::endl;

		std::cout << (checkptr(ptr->left) ? ptr->left->data : 0) << "      " << (checkptr(ptr->right) ? ptr->right->data : 0) << std::endl;
	}
}

template <typename T>
Node<T> *BST<T>::Search(T val)
{
	return searchPrivet(rootptr, val);
}

template <typename T>
int BST<T>::count()
{
	return Count;
}

// Remove method
template <typename T>
void BST<T>::RemoveNode(T val)
{
	RemoveNodePrivet(val, rootptr);
}

template <typename T>
void BST<T>::RemoveMatch(Node<T> *parent, Node<T> *match, bool left)
{
	if (!isEmpty())
	{
		Node<T> *delptr;
		int MatchKey = match->data;
		int SmallestIntRightSubTree;

		if (match->left == nullptr && match->right == nullptr)
		{
			delptr = match;
			left == true ? parent->left = nullptr : parent->right = nullptr;
			delete delptr;
			Count--;
			std::cout << MatchKey << " removed" << std::endl;
		}
		else if (match->left == nullptr && match->right != nullptr)
		{
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = nullptr;
			delptr = match;
			delete delptr;
			Count--;
			std::cout << MatchKey << " removed" << std::endl;
		}
		else if (match->left != nullptr && match->right == nullptr)
		{
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = nullptr;
			delptr = match;
			delete delptr;
			Count--;
			std::cout << MatchKey << " removed" << std::endl;
		}
		else
		{
			SmallestIntRightSubTree = FindSmallestPrivet(match->right);
			RemoveNodePrivet(SmallestIntRightSubTree, match);
			match->data = SmallestIntRightSubTree;
		}
	}
	else
	{
		std::cout << "tree empty" << std::endl;
	}
}

template <typename T>
void BST<T>::RemoveRootMatch()
{
	if (rootptr != nullptr)
	{
		Node<T> *delptr = rootptr;
		T RootKey = rootptr->data;
		int SmallestIntRightSubTree;

		if (rootptr->left == nullptr && rootptr->right == nullptr)
		{
			rootptr = nullptr;
			delete delptr;
			Count--;
			std::cout << RootKey << " removed" << std::endl;
		}
		else if (rootptr->left == nullptr && rootptr->right != nullptr)
		{
			rootptr = rootptr->right;
			delptr->right = nullptr;
			delete delptr;
			Count--;
			std::cout << RootKey << " deleted" << std::endl;
		}
		else if (rootptr->left != nullptr && rootptr->right == nullptr)
		{
			rootptr = rootptr->left;
			delptr->left = nullptr;
			delete delptr;
			Count--;
			std::cout << RootKey << " deleted" << std::endl;
		}
		else
		{
			SmallestIntRightSubTree = FindSmallestPrivet(rootptr->right);
			RemoveNodePrivet(SmallestIntRightSubTree, rootptr);
			rootptr->data = SmallestIntRightSubTree;
		}
	}
	else
	{
		std::cout << "tree is empty" << std::endl;
	}
}

// Printing methods
template <typename T>
int BST<T>::height(Node<T> *root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int left_height = height(root->left);
		int right_height = height(root->right);

		// Find max(subtree_heightH) + 1 to get the height of the tree
		return std::max(left_height, right_height) + 1;
	}
}

template <typename T>
void BST<T>::printLevelOrder(struct Node<T> *root)
{
	/* Function to line by line print level order traversal a tree*/
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
	{
		printGivenLevel(root, i);
		std::cout << " ";
	}
}

template <typename T>
void BST<T>::reverseLevelOrder()
{
	/*Function to print REVERSE level order traversal a tree*/

	int h = height(rootptr);
	int i;

	for (i = h; i >= 1; i--) //THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER
	{
		printGivenLevel(rootptr, i);
	}
}

template <typename T>
void BST<T>::printGivenLevel(struct Node<T> *root, int level)
{
	/*Print nodes at a given level*/

	if (root == NULL)
	{
		return;
	}

	if (level == 1)
	{
		std::cout << root->data << " ";
	}

	else if (level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

template <typename T>
void BST<T>::PrintAsTree()
{
	printLevelOrder(rootptr);
}

// statics
template <typename T>
int BST<T>::Count = 0;