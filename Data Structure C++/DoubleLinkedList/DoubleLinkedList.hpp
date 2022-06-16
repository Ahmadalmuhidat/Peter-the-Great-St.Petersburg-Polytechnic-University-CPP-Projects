#ifndef __DOUBLE_LINKED_LIST
#define __DOUBLE_LINKED_LIST
#include <iostream>

//  DoubleLinkedList.h - Double linked list of integers
//
template <typename T>
struct Node // can only be used in DoubleLinkedList class
{
  T item_;        // value of the list item
  Node<T> *next_; // pointer to the next item in the list
  Node<T> *prev_; // pointer to the previous element of the list

  // Constructor for creating a new list item.
  Node(T item, Node<T> *next = nullptr, Node<T> *prev = nullptr) : item_(item), next_(next), prev_(prev) {}
};

template <typename T>
class DoubleLinkedList
{
private:
  // The Node type is used to describe the list item associated with
  // next with the next_ field and preceding with the prev_ field

  int count_;     // counter of the number of elements
  Node<T> *head_; // first element of the list
  Node<T> *tail_; // last element of the list

  // Access to the head node of the list
  Node<T> *head() const { return head_; }

  // Access to the tail node of the list
  Node<T> *tail() const { return tail_; }

  // Insert the generated node into the tail of the list
  void insertTail(Node<T> *x);

  // Insert the generated node at the beginning of the list
  void insertHead(Node<T> *x); // (int item);

  // Delete the given node
  void deleteNode(Node<T> *x);

  // Search for a node (address) with a given value
  Node<T> *searchNode(T item);

  // Replace node information with a new one
  Node<T> *replaceNode(Node<T> *x, T item);

public:
  DoubleLinkedList() : count_(0), head_(nullptr), tail_(nullptr) {}

  // Constructor "copy" - create a copy of the existing list
  DoubleLinkedList(const DoubleLinkedList &src);

  // Move constructor
  DoubleLinkedList(DoubleLinkedList<T> &&src) noexcept;

  //
  DoubleLinkedList &operator=(DoubleLinkedList &&x) noexcept;

  // number of list items
  int count() const;

  // Access information of the head node of the list
  T headItem() const;
  T &headItem();

  // Access information of the tail node of the list
  T tailItem() const;
  T &tailItem();

  // Insert an item into the head of the list
  void insertHead(T item);

  // Insert an item into the tail of the list
  void insertTail(T item);

  // Remove an item from the head of the list
  bool deleteHead();

  // Remove item from the tail of the list
  bool deleteTail();

  // Deleting a node with a given value
  bool deleteItem(const int item);

  // Search for a record with a given value
  bool searchItem(T item);

  // Replace node information with a new one
  bool replaceItem(T itemOld, T itemNew);

  // Output the list items as text to standard output
  void outAll();

  // copy assignment operator
  DoubleLinkedList &operator=(const DoubleLinkedList &src);

  //swap
  void swap(DoubleLinkedList &src) noexcept;

  // overloaded output operator
  friend std::ostream &operator<<(std::ostream &out, const DoubleLinkedList<T> &src)
  {
    src.outAll();
    return out;
  }

  // Overloaded comparison operator
  bool operator==(const DoubleLinkedList &scr);

  // Method for adding the list-parameter to the end of the initial list
  void addList(DoubleLinkedList &src);

  // List destructor
  virtual ~DoubleLinkedList();
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const DoubleLinkedList<T> &src);

#endif
