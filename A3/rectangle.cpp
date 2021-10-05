#include "rectangle.hpp"

almuhidat::Rectangle::Rectangle(almuhidat::point_t pos, double height, double width):
  height(height),
  width(width),
  position(pos)
  {}

double almuhidat::Rectangle::calculateArea() const
{
  return (height * width);
}

almuhidat::rectangle_t almuhidat::Rectangle::calculateFrameRect() const
{
  return almuhidat::rectangle_t{height, width, position};
}

void almuhidat::Rectangle::move(const almuhidat::point_t &newPos)
{
  position = newPos;
}

void almuhidat::Rectangle::move(double dx, double dy)
{
  position.x += dx;
  position.y += dy;
}

almuhidat::Shape::shared almuhidat::Rectangle::clone() const
{
  return std::make_shared<Rectangle>(*this);
}

void almuhidat::Rectangle::scaleShape(double k)
{
  height *= k;
  width *= k;
}
