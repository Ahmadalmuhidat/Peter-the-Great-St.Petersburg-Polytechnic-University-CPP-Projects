#ifndef TASK_4__HPP
#define TASK_4__HPP
#include <iostream>
#include <vector>
#include "tools.hpp"

namespace almuhidat
{
  double generate(double max, double min)
  {
    double rand = (double)std::rand() / RAND_MAX;
    return min + rand * (max - min);
  }

  void task_4(char *sort_method, char *size)
  {
    std::vector< int > array;

    for (int i = 0; i < atoi(size); i++)
    {
      array[i] = generate(1.0, -1.0);
    }

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
      std::invalid_argument("[-] Incorrect sort request. ");
    }

    almuhidat::Sort< almuhidat::bracket, std::vector< int > >(array, compare);
    almuhidat::Display< std::vector< int > >(array);
  }
}
#endif
