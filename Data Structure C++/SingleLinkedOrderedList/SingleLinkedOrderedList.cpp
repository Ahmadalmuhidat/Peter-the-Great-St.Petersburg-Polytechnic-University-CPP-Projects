#include <iostream>
#include "SingleLinkedOrderedList.h"

template <typename T>
SingleLinkedList<T>::SingleLinkedList(Node<T> *n)
{
	head = n;
};

template <typename T>
Node<T> *SingleLinkedList<T>::FindeItem(T d)
{
	Node<T> *temp = NULL;
	Node<T> *ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == d)
		{
			temp = ptr;
			break;
		}
		ptr = ptr->next;
	}
	return temp;
};

template <typename T>
void SingleLinkedList<T>::sortList()
{
	Node<T> *current = head, *index = NULL;
	T temp;

	if (head == NULL)
	{
		return;
	}
	else
	{
		while (current != NULL)
		{
			//Node index will point to node next to current
			index = current->next;

			while (index != NULL)
			{
				//If current node's data is greater than index's node data, swap the data between them
				if (current->data > index->data)
				{
					temp = current->data;
					current->data = index->data;
					index->data = temp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}

template <typename T>
void SingleLinkedList<T>::InsertItem(T n)
{
	if (FindeItem(n) != NULL)
	{
		std::cout << "Item already exists with the key value " << n << std::endl;
	}
	else
	{
		Node<T> *new_node = new Node<T>(n);

		if (head == NULL)
		{
			head = new_node;
		}
		else
		{
			Node<T> *ptr = head;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = new_node;
		}
		sortList();
	}
};

template <typename T>
void SingleLinkedList<T>::DeleteItem(T n)
{
	if (head == NULL)
	{
		std::cout << "The list is already empty. cant delete !" << std::endl;
	}
	else if (head != NULL)
	{
		if (head->data == n)
		{
			head = head->next;
		}
		else
		{
			Node<T> *temp = NULL;
			Node<T> *CurrentNode = head->next;
			Node<T> *PrevNode = head;
			while (CurrentNode != NULL)
			{
				if (CurrentNode->data == n)
				{
					temp = CurrentNode;
					CurrentNode = NULL;
					break;
				}
				else
				{
					PrevNode = PrevNode->next;
					CurrentNode = CurrentNode->next;
				}
			}
			if (temp != NULL)
			{
				PrevNode->next = temp->next;
			}
			else
			{
				std::cout << "Node doesnt exist with key value " << n << std::endl;
			}
		}
	}
}

template <typename T>
void SingleLinkedList<T>::UpdateNode(T oldVal, T newVal)
{
	Node<T> *ptr = FindeItem(oldVal);
	if (ptr != NULL)
	{
		T before = ptr->data;
		ptr->data = newVal;
		sortList();
	}
	else
	{
		std::cout << "Node is not exists with key value" << std::endl;
	}
}

template <typename T>
void SingleLinkedList<T>::ShowList()
{
	Node<T> *ptr = head;
	while (ptr != NULL)
	{
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
	Node<T> *next_ = head;
	Node<T> *current_ = nullptr;
	while (next_ != nullptr)
	{
		current_ = next_;
		next_ = next_->next;
		delete current_;
	}
}

template <typename T>
void MoveItem(T n, SingleLinkedList<T> from, SingleLinkedList<T> to)
{
	if (from.FindeItem(n))
	{
		from.DeleteItem(n);
		from.ShowList();
		to.InsertItem(n);
		to.ShowList();
	}
	else
	{
		std::cout << "the item is not exist" << std::endl;
	}
}

template <typename T>
void DeleteCommon(SingleLinkedList<T> &first, SingleLinkedList<T> &second)
{
	Node<T> *current = first.head;

	while (current != nullptr)
	{
		if (second.FindeItem(current->data))
		{
			second.DeleteItem(current->data);
		}
		current = current->next;
	}
}

template <typename T>
SingleLinkedList<T> CommonItems(SingleLinkedList<T> *first, SingleLinkedList<T> *second)
{
	SingleLinkedList<T> merged_list;
	Node<T> *current = second->head;

	while (current != nullptr)
	{
		if (first->FindeItem(current->data))
		{
			merged_list.InsertItem(current->data);
		}
		current = current->next;
	}
	return merged_list;
}

template <typename T>
SingleLinkedList<T> MergeLists(SingleLinkedList<T> *first, SingleLinkedList<T> *second)
{
	Node<T> *current = second->head;
	SingleLinkedList<T> merged;
	while (current != nullptr)
	{
		merged.InsertItem(current->data);
		current = current->next;
	}

	Node<T> *current2 = first->head;
	while (current != nullptr)
	{
		merged.InsertItem(current2->data);
		current2 = current2->next;
	}
	return merged;
}
