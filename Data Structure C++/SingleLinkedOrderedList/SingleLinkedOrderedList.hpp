#ifndef Single_Linked_List
#define Single_Linked_List

//  SingleLinkedList.h - Single Linked List of integers
//
template <typename T>
struct Node
{
	T data;
	Node *next; // Next node in the list

	// Constructor for creating a new list item.
	Node(T d = 0, Node *next = nullptr)
	{
		this->data = d;		 // value of the list item
		this->next = next; // pointer to the next item in the list
	}
};

template <typename T>
class SingleLinkedList
{
public:
	Node<T> *head; // first element of the list

	// "default" constructor - create an empty list
	SingleLinkedList(Node<T> *n = nullptr);

	// Find item in the list
	Node<T> *FindeItem(T d);

	// Sort list in order
	void sortList();

	// Add item to the list
	void InsertItem(T n);

	// Delete item from the list
	void DeleteItem(T n);

	// Update item in the list
	void UpdateNode(T k, T d);

	// Display all items in the list
	void ShowList();

	// List destructor
	~SingleLinkedList();
};

template <typename T>
// Move item from list to list
void MoveItem(T n, SingleLinkedList<T> from, SingleLinkedList<T> to);

template <typename T>
// Delete common items in the list
void DeleteCommon(SingleLinkedList<T> &first, SingleLinkedList<T> &second);

template <typename T>
// Display the common items in two lists
SingleLinkedList<T> CommonItems(SingleLinkedList<T> *first, SingleLinkedList<T> *second);

template <typename T>
// Merge two lists
SingleLinkedList<T> MergeLists(SingleLinkedList<T> *first, SingleLinkedList<T> *second);

#endif