#include "shape.hpp"
#include <iterator>
#include <string>
#include <iostream>

using Point = almuhidat::Point;
using Shape = almuhidat::Shape;

std::istream &operator>>(std::istream &in, Point &point)
{
  in >> std::ws;
  if ((in.peek() == '\n') || (in.peek() != '('))
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  int x = 0;
  in >> x;
  in >> std::ws;
  if ((in.get() != ';') || (in.peek() == '\n'))
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  int y = 0;
  in >> y;
  in >> std::ws;
  if (in.get() != ')')
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  point.x = x;
  point.y = y;
  return in;
}

std::ostream &operator<<(std::ostream &out, Point &point)
{
  out << '(' << point.x << ', ' << point.y << ')';
  return out;
}

std::ostream &operator<<(std::ostream &out, Shape &shape)
{
  out << shape.size() << " ";
  std::copy(shape.begin(), shape.end(), std::ostream_iterator<Point>(out, " "));
  return out;
}

std::istream &operator>>(std::istream &in, Shape &shape)
{
  int vert;
  std::string vert_str;
  in >> vert_str;
  if ((!in) || (in.eof()) || (in.get() != ' '))
  {
    in.setstate(std::ios::failbit);
    return in;
  }
  Shape temp;
  std::copy_n(std::istream_iterator<Point>(in), vert, std::back_inserter(temp));
  std::swap(temp, shape);
  return in;
}

bool operator<(const Shape &L, const Shape &R)
{
}