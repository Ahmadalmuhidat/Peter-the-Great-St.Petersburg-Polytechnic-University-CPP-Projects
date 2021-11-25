#include "rectangle.hpp"

almuhidat::Rectangle::Rectangle(const almuhidat::point_t &pos, double height, double width):
  height_(height),
  width_(width),
  pos_(pos)
  {}

double almuhidat::Rectangle::getArea() const
{
  return (height_ * width_);
}

almuhidat::rectangle_t almuhidat::Rectangle::getFrameRect() const
{
  return {height_, width_, pos_};
}

void almuhidat::Rectangle::move(const almuhidat::point_t &newPos)
{
  pos_ = newPos;
}

void almuhidat::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

almuhidat::Shape::shared almuhidat::Rectangle::clone() const
{
  return std::make_shared< Rectangle >(*this);
}

void almuhidat::Rectangle::scaleShape(double k)
{
  height_ *= k;
  width_ *= k;
}
