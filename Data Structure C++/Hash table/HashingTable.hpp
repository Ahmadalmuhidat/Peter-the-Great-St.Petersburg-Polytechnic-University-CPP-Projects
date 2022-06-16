#ifndef HASH_TABLE_
#define HASH_TABLE_
#include <list>

template <typename T>
class HashingTable
{
public:
  HashingTable(int size);
  void insert(T val);
  void remove(T val);
  void search(T val);
  void display();
  int hashFunction(T val);

private:
  int size;
  std::list<T> *table;
};

#endif