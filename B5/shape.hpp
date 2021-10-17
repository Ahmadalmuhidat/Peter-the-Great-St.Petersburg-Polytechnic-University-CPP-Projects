#ifndef SHAPE_
#define SHAPE_
#include <iosfwd>
#include <vector>

namespace almuhidat
{
  struct Point
  {
    int x, y;
  };

  using Shape = std::vector<Point>;

  std::istream &operator>>(std::istream &in, Point &point);
  std::ostream &operator<<(std::ostream &out, Point &point);
  std::ostream &operator<<(std::ostream &out, Shape &shape);
  std::istream &operator>>(std::istream &in, Shape &shape);
  bool operator<(const Shape &L, const Shape &R);
}

#endif