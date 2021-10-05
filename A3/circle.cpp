#include "circle.hpp"

almuhidat::Circle::Circle(almuhidat::point_t position, double radius) :
position_(position),
radius_(radius)
{}

double almuhidat::Circle::calculateArea() const
{
  const double PI = 3.14;
  return (radius_ * radius_ * PI);
}

almuhidat::rectangle_t almuhidat::Circle::calculateFrameRect() const
{
  return almuhidat::rectangle_t{2 * radius_, 2 * radius_, position_};
}

void almuhidat::Circle::move(const almuhidat::point_t &newPos)
{
  position_ = newPos;
}

void almuhidat::Circle::move(double d_x, double d_y)
{
  position_.x += d_x;
  position_.y += d_y;
}

almuhidat::Shape::shared almuhidat::Circle::clone() const
{
  return std::make_shared<almuhidat::Circle>(*this);
}

void almuhidat::Circle::scaleShape(double k)
{
  radius_ *= k;
}
