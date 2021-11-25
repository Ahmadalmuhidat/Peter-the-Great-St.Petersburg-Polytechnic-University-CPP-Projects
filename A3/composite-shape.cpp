#include "composite-shape.hpp"
#include <algorithm>

using CompositeShape = almuhidat::CompositeShape;
CompositeShape::CompositeShape(const CompositeShape &source):
  size_(source.size_),
  members_(std::make_unique< shape_pointer[] >(size_))
{
  for(size_t i = 0; i < size_; ++i)
  {
    members_[i] = source.members_[i]->clone();
  }
}

double CompositeShape::getArea() const
{
  double result = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    result += members_[i]->getArea();
  }
  return result;
}

almuhidat::rectangle_t CompositeShape::getFrameRect() const
{
  double maxX = getX(*members_[0]) + (getWidth(*members_[0]) / 2);
  double minY = getY(*members_[0]) - (getHeight(*members_[0]) / 2);
  double minX = getX(*members_[0]) - (getWidth(*members_[0]) / 2);
  double maxY = getY(*members_[0]) + (getHeight(*members_[0]) / 2);
  for(size_t i = 1; i < size_; i++)
  {
    maxX = std::max((getX(*members_[i]) + getWidth(*members_[i]) / 2), maxX);
    maxY = std::max((getY(*members_[i]) + getHeight(*members_[i]) / 2), maxY);
    minX = std::max((getX(*members_[i]) - getWidth(*members_[i]) / 2), minX);
    minY = std::max((getY(*members_[i]) - getHeight(*members_[i]) / 2), minY);
  }
  double width = maxX - minX;
  double height = maxY - minY;
  double x = (minX + maxX) / 2;
  double y = (minY + maxY) / 2;
  return { width, height, {x, y} };
}

void CompositeShape::move(const point_t &point)
{
  double point_X = point.x - getX(*this);
  double point_Y = point.y - getY(*this);
  move(point_X, point_Y);
}

void CompositeShape::move(double dx, double dy)
{
  for(size_t i = 0; i < size_; i++)
  {
    members_[i]->move(dx, dy);
  }
}

std::shared_ptr< almuhidat::Shape > CompositeShape::clone() const
{
  return std::make_shared< CompositeShape >(*this);
}

void CompositeShape::scaleShape(double k)
{
  almuhidat::point_t compPos = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++)
  {
    double dx = almuhidat::getX(*members_[i]) - compPos.x;
    double dy = almuhidat::getY(*members_[i]) - compPos.y;
    members_[i]->move({compPos.x + dx * k, compPos.y + dy * k});
    members_[i]->scale(k);
  }
}
