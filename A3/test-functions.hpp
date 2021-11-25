#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include "shape.hpp"

namespace almuhidat
{
  std::unique_ptr< Shape > makeCircle();
  std::unique_ptr< Shape > makeRectangle();
  std::unique_ptr< Shape > makeCompositeShape();
  void PointToPoint(Shape& shape);
  void testScale(Shape& shape);
}
#endif
