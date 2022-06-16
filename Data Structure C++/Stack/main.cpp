#include <iostream>
#include "stack.h"

int main()
{
	std::cout << "Test Stack class \n";
	std::cout << "\n";

	Stack<int> s; // create the stack

	if (s.isEmpty())
	{
		std::cout << "The stack s is empty" << std::endl;
	}

	s.Push(7); // add new element
	s.Push(3);
	s.Push(5);
	s.Push(1);
	s.Push(1);
	s.Push(12);

	if (s.isFull())
	{
		std::cout << "The stack is full" << std::endl;
	}

	s.DisplayStack(); // display all elemnts in the stack

	s.Pop(); // remove the last element
	s.DisplayStack();

	std::cout << s.Count() << " values in the stack" << std::endl;

	s.Peek(5); // return the position of the element

	s.Change(2, 3); // chnage the position of the element in the stack
	s.DisplayStack();

	std::cout << "========================" << std::endl;
	std::cout << "Task solution: ";
	Stack<char> t;
	const char *str = "{[()]})";

	areBracketsBalanced(str);
	std::cout << (areBracketsBalanced(str) ? "blanced\n" : "not balanced\n");

	return 0;
}
