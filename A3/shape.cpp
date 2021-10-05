#include "shape.hpp"

double almuhidat::getWidth(const Shape &shape)
{
  return shape.calculateFrameRect().width;
}

double almuhidat::getHeight(const Shape &shape)
{
  return shape.calculateFrameRect().height;
}

double almuhidat::getX(const Shape &shape)
{
  return shape.calculateFrameRect().position.x;
}

double almuhidat::getY(const Shape &shape)
{
  return shape.calculateFrameRect().position.y;
}

void almuhidat::Shape::scale(double k)
{
  scaleShape(k);
}
