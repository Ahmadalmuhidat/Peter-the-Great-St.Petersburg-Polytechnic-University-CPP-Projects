#include "shape.hpp"
#include <stdexcept>

double almuhidat::getWidth(const Shape &shape)
{
  return shape.getFrameRect().width;
}

double almuhidat::getHeight(const Shape &shape)
{
  return shape.getFrameRect().height;
}

double almuhidat::getX(const Shape &shape)
{
  return shape.getFrameRect().pos.x;
}

double almuhidat::getY(const Shape &shape)
{
  return shape.getFrameRect().pos.y;
}

void almuhidat::Shape::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("[-] Wrong coefficient value, must be more than 0.");
  }
  scaleShape(k);
}
