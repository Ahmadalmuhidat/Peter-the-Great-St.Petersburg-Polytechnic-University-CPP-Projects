#include "boost/test/unit_test.hpp"
#include "test-functions.hpp"

const almuhidat::point_t Circle_Position = {3, 5};
const almuhidat::point_t Rectangle_Position = {10, 8};
const almuhidat::point_t Final_Position = {0, 11};
double Radius, Height, Width;

std::unique_ptr<almuhidat::Shape> almuhidat::makeCircle()
{
  return std::make_unique<almuhidat::Circle>(almuhidat::Circle(Circle_Position, Radius));
}

std::unique_ptr<almuhidat::Shape> almuhidat::makeRectangle()
{
  return std::make_unique<almuhidat::Rectangle>(almuhidat::Rectangle(Rectangle_Position, Height, Width));
}

std::unique_ptr<almuhidat::Shape> almuhidat::makeCompositeShape()
{
  std::make_unique<almuhidat::Circle>(almuhidat::Circle(Circle_Position, Radius));
  std::make_unique<almuhidat::Rectangle>(almuhidat::Rectangle(Rectangle_Position, Height, Width));
}

void almuhidat::PointToPoint(almuhidat::Shape& shape)
{
  double height, width, area;
  height = almuhidat::getHeight(shape);
  width = almuhidat::getWidth(shape);
  area = shape.calculateArea();
  shape.move(Final_Position);
  BOOST_CHECK_CLOSE(height, almuhidat::getHeight(shape), epsilon);
  BOOST_CHECK_CLOSE(width, almuhidat::getWidth(shape), epsilon);
  BOOST_CHECK_CLOSE(area, shape.calculateArea(), epsilon);
}

void almuhidat::testScale(almuhidat::Shape& shape)
{
  double previous_Area = shape.calculateArea();
  shape.scale(3);
  BOOST_CHECK_CLOSE(previous_Area, shape.calculateArea(), epsilon);
}
