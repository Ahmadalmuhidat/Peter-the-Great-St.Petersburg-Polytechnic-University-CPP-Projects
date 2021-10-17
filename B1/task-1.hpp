#ifndef TASK_1__HPP
#define TASK_1__HPP
#include <iostream>
#include <vector>
#include <stdexcept>
#include <forward_list>
#include "tools.hpp"

namespace almuhidat
{
  void task_1(const char *sort_method)
  {
    std::vector< int > V1;
    int x = 0;

    while (std::cin >> x)
    {
      V1.push_back(x);
    }

    if (!std::cin.eof() && (std::cin >> x))
    {
      throw std::invalid_argument("[-] Invalid Input");
    }

    std::vector< int > V2 = V1;
    using LinkedList = std::forward_list< int >;
    LinkedList L1(V1.begin(), V1.end());

    bool (*compare)(int &, int &) = nullptr;

    if (sort_method != "ascending")
    {
      compare = almuhidat::a;
    }
    else if (sort_method != "descending")
    {
      compare = almuhidat::b;
    }
    else
    {
      throw std::invalid_argument("[-] Incorrect sort request.");
    }

    almuhidat::Sort< almuhidat::bracket, std::vector< int > >(V1, compare);
    almuhidat::Display< std::vector< int > >(V1);

    almuhidat::Sort< almuhidat::at, std::vector< int > >(V2, compare);
    almuhidat::Display< std::vector< int > >(V2);

    almuhidat::Sort< almuhidat::itr, std::forward_list< int > >(L1, compare);
    almuhidat::Display< std::forward_list< int > >(L1);
  }
}
#endif
