#ifndef OPERATIONS_
#define OPERATIONS_
#include "shape.hpp"

namespace almuhidat
{
  using Shape = almuhidat::Shape;
  using Point = almuhidat::Point;

  int vertCount(int sum, const Shape shape);
  bool isTriangle(const Shape &shape);
  bool isRectangle(const Shape &shape);
  bool isSquare(const Shape &shape);
  bool isPentagon(const Shape &shape);
  bool checkSides(const Shape &shape);
  Point getPoint(const Shape &shape);
}

#endif