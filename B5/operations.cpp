#include "operations.hpp"

using Shape = almuhidat::Shape;
using Point = almuhidat::Point;

int vertCount(int sum, const Shape shape)
{
  return (sum + shape.size());
}

bool checkSides(const Shape &shape)
{
  // std::vector<unsigned int> dist;
  // auto function = getSquaredDistance;
  // std::transform(std::next(shape.begin()), shape.end(), shape.begin(), std::back_inserter(dist), function);

  // unsigned int lastSide = getSquaredDistance(shape.front(), shape.back());

  // using std::placeholders::_1;
  // return std::all_of(dist.begin(), dist.end(), std::bind(std::equal_to<>(), _1, lastSide));
  // -------------------------------------------------------------------------------------------------------
  // int last = getSide(shp.front(), shp.back());
  // std::vector<int> temp;
  // temp.reserve(shp.size());
  // std::transform(shp.begin() + 1, shp.end(), shp.begin(), std::back_inserter(temp), getSide);
  // return (std::all_of(temp.begin(), temp.end(), std::bind(std::equal_to<>(), std::placeholders::_1, last)));
}

bool isTriangle(const Shape &shape)
{
  return (shape.size() == 3);
}

bool isRectangle(const Shape &shape)
{
  return (shape.size() == 4);
}

bool isSquare(const Shape &shape)
{
  return (shape.size() == 4 && almuhidat::checkSides(shape));
}

bool isPentagon(const Shape &shape)
{
  return (shape.size() == 5);
}

Point getPoint(const Shape &shape)
{
  return shape.front();
}