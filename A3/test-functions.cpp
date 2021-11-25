#include "boost/test/unit_test.hpp"
#include "test-functions.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

constexpr almuhidat::point_t Circle_Position = {4.5, 9.7};
constexpr almuhidat::point_t Rectangle_Position = {24, -10};
constexpr almuhidat::point_t Final_Position = {12.0, -5.0};
constexpr double Radius = 4.0;
constexpr double Height = 10.0;
constexpr double Width = 4.0;
constexpr double epsilon = std::numeric_limits< double >::epsilon();

using shape_pointer = std::unique_ptr< almuhidat::Shape >;
shape_pointer almuhidat::makeCircle()
{
  return std::make_unique< Circle > (Circle(Circle_Position, Radius));
}

shape_pointer almuhidat::makeRectangle()
{
  return std::make_unique< Rectangle > (Rectangle(Rectangle_Position, Height, Width));
}

std::unique_ptr< almuhidat::Shape > almuhidat::makeCompositeShape()
{
  shape_pointer circle(std::make_unique< Circle > (Circle(Circle_Position, Radius)));
  shape_pointer rectangle(std::make_unique< Rectangle > (Rectangle(Rectangle_Position, Height, Width)));
  using CShape = almuhidat::CompositeShape;
  return shape_pointer(std::make_unique< CShape > (CShape(std::move(circle), std::move(rectangle))));
}

void almuhidat::PointToPoint(almuhidat::Shape& shape)
{
  double height = almuhidat::getHeight(shape);
  double width = almuhidat::getWidth(shape);
  double area = shape.getArea();

  shape.move(Final_Position);

  BOOST_CHECK_CLOSE(height, almuhidat::getHeight(shape), epsilon);
  BOOST_CHECK_CLOSE(width, almuhidat::getWidth(shape), epsilon);
  BOOST_CHECK_CLOSE(area, shape.getArea(), epsilon);
  BOOST_CHECK_CLOSE(Final_Position.x, almuhidat::getX(shape), epsilon);
  BOOST_CHECK_CLOSE(Final_Position.y, almuhidat::getY(shape), epsilon);
}

void almuhidat::testScale(almuhidat::Shape& shape)
{
  double previous_Area = shape.getArea();
  double original_X = almuhidat::getX(shape);
  double original_y = almuhidat::getY(shape);

  shape.scale(2.0);

  BOOST_CHECK_CLOSE(previous_Area * 2.0 * 2.0, shape.getArea(), epsilon);
  BOOST_CHECK_CLOSE(original_X, almuhidat::getX(shape), epsilon);
  BOOST_CHECK_CLOSE(original_y, almuhidat::getY(shape), epsilon);
}
