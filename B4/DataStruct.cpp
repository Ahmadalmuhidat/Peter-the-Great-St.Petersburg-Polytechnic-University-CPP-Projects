#include "DataStruct.hpp"
#include <string>
#include <sstream>

std::istream &almuhidat::operator>>(std::istream &in, DataStruct &data)
{
  std::string str;
  getline(in, str);
  std::stringstream temp(str);
  int key = 0;
  temp >> key;

  if ((key > 5) || (key < -5) || (!temp))
  {
    in.setstate(std::istream::failbit);
    return in;
  }

  data.key1 = key;
  char ch = 0;
  temp >> ch;

  if ((ch != ',') || (!temp))
  {
    in.setstate(std::istream::failbit);
    return in;
  }

  temp >> key;
  if ((key > 5) || (key < -5) || (!temp))
  {
    in.setstate(std::istream::failbit);
    return in;
  }
  data.key2 = key;
  temp >> ch;

  if ((ch != ',') || (!temp))
  {
    in.setstate(std::istream::failbit);
    return in;
  }

  temp >> std::ws;
  std::getline(temp, str);

  if (!temp)
  {
    in.setstate(std::istream::failbit);
    return in;
  }
  data.str = str;
  return in;
}
std::ostream &almuhidat::operator<<(std::ostream &out, DataStruct &data)
{
  out << data.key1 << " " << data.key2 << " " << data.str;
  return out;
}

bool almuhidat::operator<(const DataStruct &L, const DataStruct &R)
{
  if (L.key1 == R.key1)
  {
    if (L.key2 == R.key2)
    {
      return (L.str.size() < R.str.size());
    }
    return (L.key2 < R.key2);
  }
  return (L.key1 < R.key1);
}