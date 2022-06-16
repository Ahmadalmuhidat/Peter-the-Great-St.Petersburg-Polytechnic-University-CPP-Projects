#ifndef __Queue
#define __Queue

template <typename T>
class Queue
{

public:
	int front; // front item
	int tail;	 // last item
	T arr[5];

	// "default" constructor - create an empty list
	Queue();

	// Insert new item
	void Enqueue(T val);

	// Remove last item
	T Dequeue();

	// Check if the list is full or not
	bool isFull();

	// Check if the list is empty or not
	bool isEmpty();

	// Sort list in order
	void Sorting();

	// How many item we have
	int Count();

	// Dislay all the items
	void Display();
};

// Compare two lists
template <typename T>
bool CompareTwoLists(Queue<T> F, Queue<T> S);

#endif