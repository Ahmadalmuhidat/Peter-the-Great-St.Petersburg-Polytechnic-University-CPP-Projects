#include <iostream>
#include <stdio.h>
#include "HashingTable.cpp"

int main(void)
{
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a) / sizeof(a[0]);
  HashingTable<int> table(n);

  for (int i = 0; i < n; i++)
  {
    table.insert(a[i]);
  }
  table.search(15);
  table.display();
  table.remove(8);
  table.display();

  return 0;
}