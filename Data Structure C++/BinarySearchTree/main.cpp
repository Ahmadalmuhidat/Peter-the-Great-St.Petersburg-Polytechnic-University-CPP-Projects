#include <iostream>
#include "BinarySearchTree.cpp"
using namespace std;

int main()
{
	BST<int> t;

	t.AddNode(50);
	t.AddNode(40);
	t.AddNode(60);
	t.AddNode(36);
	t.AddNode(73);
	t.AddNode(11);
	t.AddNode(23);
	t.AddNode(34);
	t.AddNode(32);
	t.AddNode(64);

	t.NodeInfo(36);

	t.PrintInOrder();
	cout << endl;

	t.Search(40);
	t.RemoveNode(36);

	t.PrintInOrder();
	cout << endl;

	cout << "Number of nodes: " << t.count() << endl;

	cout << endl;
	t.PrintAsTree();

	cout << "\n";
	t.reverseLevelOrder();

	BST<std::string> str;

	str.AddNode("test");
	str.AddNode("code");
	str.PrintInOrder();

	return 0;
}