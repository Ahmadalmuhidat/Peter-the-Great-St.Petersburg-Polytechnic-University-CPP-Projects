#include <iostream>
#include "queue.cpp"

int main()
{
	Queue<int> q1;
	q1.Enqueue(3);
	q1.Enqueue(1);
	q1.Enqueue(13);
	q1.Enqueue(56);
	q1.Enqueue(20);
	std::cout << (q1.isFull() ? "Queue Overflow" : "Queue Underflow") << std::endl;
	std::cout << q1.Count() << " elements in the queue" << std::endl;
	std::cout << "q1: ";
	q1.Display();
	q1.Dequeue();
	std::cout << "q1: ";
	q1.Display();
	std::cout << q1.Count() << " elements in the queue" << std::endl;

	std::cout << "----------------------" << std::endl;

	Queue<int> q2;
	q2.Enqueue(20);
	q2.Enqueue(56);
	q2.Enqueue(1);
	q2.Enqueue(13);
	q2.Enqueue(3);
	std::cout << "q2: ";
	q2.Display();

	Queue<int> q3;
	q3.Enqueue(9);
	q3.Enqueue(4);
	q3.Enqueue(15);
	q3.Enqueue(28);
	q3.Enqueue(7);
	std::cout << "q3: ";
	q3.Display();
	std::cout << (CompareTwoLists(q2, q3) ? "q2 & q3 same" : "q2 & q3 not same") << std::endl;

	Queue<int> q4;
	q4.Enqueue(9);
	q4.Enqueue(4);
	q4.Enqueue(15);
	q4.Enqueue(28);
	q4.Enqueue(7);
	std::cout << (CompareTwoLists(q4, q3) ? "q4 & q3 same" : "q4 & q3 not same") << std::endl;

	std::cout << "\nsorting: \n";
	q4.Sorting();
	q4.Display();

	Queue<std::string> q5;
	q5.Enqueue("test");
	q5.Enqueue("queue");
	q5.Display();

	return 0;
}
