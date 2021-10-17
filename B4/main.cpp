#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "dataStruct.hpp"

using DataStruct = almuhidat::DataStruct;

int main()
{
  std::istream_iterator<DataStruct> first(std::cin);
  std::istream_iterator<DataStruct> last;
  std::vector<DataStruct> dataVec(first, last);

  if (!std::cin.eof())
  {
    return 1;
  }

  std::sort(dataVec.begin(), dataVec.end());
  std::copy(dataVec.begin(), dataVec.end(), std::ostream_iterator<DataStruct>(std::cout, "\n"));
  return 0;
}