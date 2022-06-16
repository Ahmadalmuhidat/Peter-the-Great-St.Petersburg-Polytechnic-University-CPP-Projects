#include <iostream>
#include <list>
#include <algorithm>
#include "HashingTable.hpp"

template <typename T>
HashingTable<T>::HashingTable(int size)
{
  this->size = size;
  this->table = new std::list<T>[size];
}

template <typename T>
int HashingTable<T>::hashFunction(T val)
{
  return (val % this->size);
}

template <typename T>
void HashingTable<T>::insert(T val)
{
  int index = hashFunction(val);
  this->table[index].push_back(val);
}

template <typename T>
void HashingTable<T>::remove(T val)
{
  int index = hashFunction(val);
  auto it = std::find(this->table[index].begin(), this->table[index].end(), val);

  if (it != this->table[index].end())
  {
    this->table[index].erase(it);
  }
}

template <typename T>
void HashingTable<T>::search(T val)
{
  int index = hashFunction(val);
  auto it = std::find(this->table[index].begin(), this->table[index].end(), val);

  if (it != this->table[index].end())
  {
    std::cout << "Found " << val << "at index " << index << std::endl;
  }
  else
  {
    std::cout << val << " not found" << std::endl;
  }
}

template <typename T>
void HashingTable<T>::display()
{
  for (int i = 0; i < this->size; ++i)
  {
    std::cout << i;
    for (auto it : this->table[i])
    {
      std::cout << " --> " << it;
    }
    std::cout << "\n";
  }
}