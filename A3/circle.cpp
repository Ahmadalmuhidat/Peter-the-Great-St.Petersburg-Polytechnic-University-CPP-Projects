#include "circle.hpp"

almuhidat::Circle::Circle(const almuhidat::point_t &position, double radius):
  pos_(position),
  radius_(radius)
  {}

double almuhidat::Circle::getArea() const
{
  constexpr double PI = 3.14;
  return ( radius_ * radius_ * PI );
}

almuhidat::rectangle_t almuhidat::Circle::getFrameRect() const
{
  return almuhidat::rectangle_t { 2 * radius_, 2 * radius_, pos_ };
}

void almuhidat::Circle::move(const almuhidat::point_t &newPos)
{
  pos_ = newPos;
}

void almuhidat::Circle::move(double d_x, double d_y)
{
  pos_.x += d_x;
  pos_.y += d_y;
}

almuhidat::Shape::shared almuhidat::Circle::clone() const
{
  return std::make_shared< almuhidat::Circle >(*this);
}

void almuhidat::Circle::scaleShape(double k)
{
  radius_ *= k;
}
