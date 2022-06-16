#include "stack.h"

template <class T>
Stack<T>::Stack()
{
	top = -1;
}

template <class T>
bool Stack<T>::isEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool Stack<T>::isFull()
{
	if (top == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void Stack<T>::Push(T val)
{
	if (isFull())
	{
		std::cout << "The stack is already full" << std::endl;
	}
	else
	{
		top++;
		arr[top] = val;
	}
}

template <class T>
T Stack<T>::Pop()
{
	if (isEmpty())
	{
		std::cout << "Stack underflow" << std::endl;
		return 0;
	}
	else
	{
		int PopVal = arr[top];
		arr[top] = 0;
		top--;
		return PopVal;
	}
}

template <class T>
int Stack<T>::Count()
{
	return top + 1;
}

template <class T>
T Stack<T>::Peek(int pos)
{
	if (isEmpty())
	{
		std::cout << "Stack underflow" << std::endl;
		return 0;
	}
	else
	{
		return arr[pos];
	}
}

template <class T>
void Stack<T>::Change(int pos, T val)
{
	if (isEmpty())
	{
		std::cout << "Stack underflow" << std::endl;
	}
	else
	{
		arr[pos] = val;
		std::cout << val << " changed to location " << pos << std::endl;
	}
}

template <class T>
void Stack<T>::DisplayStack()
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

bool areBracketsBalanced(const char *expr) // const char*
{
	Stack<char> s;
	char x;

	for (int i = 0; expr[i] != '\0'; i++)
	{
		if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
		{
			s.Push(expr[i]);
		}

		if (s.isEmpty())
		{
			return false;
		}

		switch (expr[i])
		{
		case ')':
			x = s.top;
			s.Pop();
			if (x == '{' || x == '[')
				return false;
			break;
		case '}':
			x = s.top;
			s.Pop();
			if (x == '(' || x == '[')
				return false;
			break;
		case ']':
			x = s.top;
			s.Pop();
			if (x == '(' || x == '{')
				return false;
			break;

		default:
			break;
		}
	}
	return (s.isEmpty());
}