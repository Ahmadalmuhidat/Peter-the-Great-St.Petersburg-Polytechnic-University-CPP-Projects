#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <limits>
#include "rectangle.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

double epsilon = std::numeric_limits< double >::epsilon();

namespace almuhidat
{
  std::unique_ptr<Shape> makeCircle();
  std::unique_ptr<Shape> makeRectangle();
  std::unique_ptr<Shape> makeCompositeShape();
  void PointToPoint(Shape& shape);
  void testScale(Shape& shape);
}
#endif
