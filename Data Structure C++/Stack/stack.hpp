#ifndef __STACK
#define __STACK

#include <iostream>

template <class T>
class Stack
{

public:
	size_t top; // top item
	T arr[5];		// stack list

	// "default" constructor - create an empty list
	Stack();

	// Check if the list is empty or not
	bool isEmpty();

	// Check if the list is full or not
	bool isFull();

	// Insert item in the list
	void Push(T val);

	// Delete last item in the list
	T Pop();

	// Display item in the given position
	T Peek(int pos);
	// Change item in the given position
	void Change(int pos, T val);

	// Display all the list
	void DisplayStack();

	// How many item we have in the list
	int Count();
};

// Check if the brackets are balanced in the string
bool areBracketsBalanced(const char *expr);

#endif