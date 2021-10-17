#include <iostream>
#include <stdexcept>
#include "task-1.hpp"
#include "task-2.hpp"
#include "task-3.hpp"
#include "task-4.hpp"
// using namespace almuhidat;

int main(int args, char **argv)
{
  if (args < 2)
  {
    throw std::invalid_argument("[-] Incorrect task number argument.");
  }
  switch (*argv[1])
  {
  case '1':
    if (args == 3)
    {
      almuhidat::task_1(argv[2]);
    }
    else
    {
      throw std::invalid_argument("[-] Incorrect number of input parameters.");
    }
    break;

  case '2':
    if (args == 3)
    {
      almuhidat::task_2(argv[2]);
    }
    else
    {
      throw std::invalid_argument("[-] Incorrect number of input parameters.");
    }
    break;

  case '3':
    if (args == 2)
    {
      almuhidat::task_3();
    }
    else
    {
      throw std::invalid_argument("[-] Incorrect number of input parameters.");
    }
    break;

  case '4':
    if (args == 4)
    {
      almuhidat::task_4(argv[2], argv[3]);
    }
    else
    {
      throw std::invalid_argument("[-] Incorrect number of input parameters.");
    }
    break;

  default:
    throw std::invalid_argument("[-] Invalid task number argument.");
    break;
  }
  return 0;
}
