#include "composite-shape.hpp"
#include <algorithm>

almuhidat::CompositeShape::CompositeShape(shape_pointer source):
size_(0),
capacity_(2),
members_(std::make_unique<shape_pointer[]>(capacity_))
{
  members_[size_] = source->clone();
}

almuhidat::CompositeShape::CompositeShape(const CompositeShape &source):
size_(source.size_),
capacity_(source.capacity_),
members_(std::make_unique<shape_pointer[]>(source.capacity_))
{
  for(size_t i=0; i < size_; ++i)
  {
    members_[i] = source.members_[i]->clone();
  }
}

double almuhidat::CompositeShape::calculateArea() const
{
  double result = 0.0;
  for (size_t i=0; i < size_; i++)
  {
    result += members_[i]->calculateArea();
  }
  return result;
}

almuhidat::rectangle_t almuhidat::CompositeShape::calculateFrameRect() const
{
  double maxX, minY, minX, maxY, width, height, x, y;
  maxX = getX(*members_[0]) + (getWidth(*members_[0]) / 2);
  minY = getY(*members_[0]) - (getHeight(*members_[0]) / 2);
  minX = getX(*members_[0]) - (getWidth(*members_[0]) / 2);
  maxY = getY(*members_[0]) + (getHeight(*members_[0]) / 2);
  for(size_t i=1; i < size_; i++)
  {
    maxX = std::max((getX(*members_[i]) + getWidth(*members_[i]) / 2), maxX);
    maxY = std::max((getY(*members_[i]) + getHeight(*members_[i]) / 2), maxY);
    minX = std::max((getX(*members_[i]) - getWidth(*members_[i]) / 2), minX);
    minY = std::max((getY(*members_[i]) - getHeight(*members_[i]) / 2), minY);
  }
  width = maxX - minX;
  height = maxY - minY;
  x = (minX + maxX) / 2;
  y = (minY + maxY) / 2;
  return {width, height, {x, y}};
}

void almuhidat::CompositeShape::move(const point_t &point)
{
  double point_X, point_Y;
  point_X = point.x - getX(*this);
  point_Y = point.y - getY(*this);
  move(point_X, point_Y);
}

void almuhidat::CompositeShape::move(double dx, double dy)
{
  for(size_t i=0; i < size_; i++)
  {
    members_[i]->move(dx, dy);
  }
}

size_t almuhidat::CompositeShape::size() const
{
  return size_;
}

size_t almuhidat::CompositeShape::capacity() const
{
  return capacity_;
}

almuhidat::CompositeShape::shape_pointer almuhidat::CompositeShape::operator[](const size_t index) const
{
  return members_[index];
}

std::shared_ptr<almuhidat::Shape> almuhidat::CompositeShape::clone() const 
{
  std::make_shared<almuhidat::CompositeShape>(*this);
}