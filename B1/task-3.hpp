#ifndef TASK_3__HPP
#define TASK_3__HPP
#include <iostream>
#include <vector>
#include <stdexcept>
#include "tools.hpp"

namespace almuhidat
{
  void task_3()
  {
    std::vector< int > V;
    int element = 1;

    while (std::cin >> element)
    {
      if (element == 0)
      {
        break;
      }
      else
      {
        V.push_back(element);
      }
    }

    if (!std::cin.eof() && std::cin.fail())
    {
      throw std::invalid_argument("[-] Incorrect input - only integers allowed.");
    }

    if (V.empty())
    {
      throw std::invalid_argument("[-] vector is empty");
    }

    if (V.back() != 0)
    {
      throw std::invalid_argument("[-] the last element must be 0.");
    }
    else
    {
      V.pop_back();
    }

    auto it = V.begin();
    if (V.back() == 1)
    {
      while (it != V.end())
      {
        if (*it % 2 == 0)
        {
          it = V.erase(it);
        }
        else
        {
          it++;
        }
      }
    }
    else if (it != V.end())
    {
      while (it != V.end())
      {
        if (*it % 3 == 0)
        {
          it = V.insert(++it, 3, 1);
          it += 2;
        }
        it++;
      }
    }
    almuhidat::Display(V);
  }
}
#endif
