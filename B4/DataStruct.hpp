#ifndef DATA_STRUCT_
#define DATA_STRUCT_
#include <string>
#include <iosfwd>

namespace almuhidat
{
  struct DataStruct
  {
    int key1, key2;
    std::string str;
  };

  std::ostream &operator<<(std::ostream &out, DataStruct &data);
  std::istream &operator>>(std::istream &in, DataStruct &data);
  bool operator<(const DataStruct &L, const DataStruct &R);
}

#endif