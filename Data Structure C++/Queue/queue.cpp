#include <iostream>
#include <algorithm>
#include "queue.h"

template <typename T>
Queue<T>::Queue()
{
	front = -1;
	tail = -1;
	// for (int i = 0; i < 5; i++)
	// {
	// 	arr[i] = 0;
	// }
}

template <typename T>
void Queue<T>::Enqueue(T val)
{
	if (isFull())
	{
		std::cout << "is full" << std::endl;
	}
	else if (isEmpty())
	{
		tail = 0;
		front = 0;
		arr[tail] = val;
	}
	else
	{
		tail++;
		arr[tail] = val;
	}
}

template <typename T>
T Queue<T>::Dequeue()
{
	T x;
	if (isEmpty())
	{
		return 0;
	}
	else if (front == tail)
	{
		x = arr[tail];
		arr[front] = 0;
		tail = -1;
		front = -1;
		return x;
	}
	else
	{
		x = arr[tail];
		arr[front] = 0;
		front++;
		return x;
	}
	return x;
}

template <typename T>
bool Queue<T>::isFull()
{
	if (tail == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
bool Queue<T>::isEmpty()
{
	if (front == -1 && tail == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
void Queue<T>::Sorting()
{
	if (isEmpty())
	{
		return;
	}
	else
	{
		std::sort(std::begin(arr), std::end(arr));
	}
}

template <typename T>
int Queue<T>::Count()
{
	return (tail - front + 1);
}

template <typename T>
void Queue<T>::Display()
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

template <typename T>
bool CompareTwoLists(Queue<T> F, Queue<T> S)
{
	if (F.Count() == S.Count())
	{
		int points = 0;
		for (int i = 0; i < F.Count(); i++)
		{
			for (int num : S.arr)
			{
				if (F.arr[i] == num)
				{
					points += 1;
				}
				else
				{
					continue;
				}
			}
		}
		if (points == F.Count())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}