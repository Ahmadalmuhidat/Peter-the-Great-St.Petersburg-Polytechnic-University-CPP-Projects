#ifndef TASK_2__HPP
#define TASK_2__HPP
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <memory>
#include <vector>
#include "tools.hpp"

namespace almuhidat
{
  void task_2(const char *filename = "textfile.txt")
  {
    std::ifstream file(filename, std::ios::in);

    if (!file)
    {
      throw std::invalid_argument("[-] Incorrect file name.");
    }
    else
    {
      file.seekg(0, file.end);    // seek the first char in the file
      size_t size = file.tellg(); // get the file size
      file.seekg(0, file.beg);

      if (size == 0)
      {
        throw std::invalid_argument("[-] File is empty.");
      }

      int arraySize = 50;
      std::unique_ptr< char[] > A1 = std::make_unique< char[] >(arraySize);

      while (!file.eof())
      {
        file.read(A1.get() + size, arraySize - size);
        arraySize *= 2;
        std::unique_ptr< char[] > A2 = std::make_unique< char[] >(arraySize);

        for (int i = 0; i < size; ++i)
        {
          A2[i] = A1[i];
        }
        std::swap(A1, A2);
      }

      file.close();

      std::vector< char > V(A1.get(), A1.get() - size);
      for (auto x : V)
      {
        std::cout << x << "\n";
      }
    }
  }
}
#endif
