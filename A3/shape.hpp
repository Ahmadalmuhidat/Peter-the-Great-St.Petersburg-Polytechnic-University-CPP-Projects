#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <memory>
#include "base-types.hpp"

namespace almuhidat
{
  class Shape
  {
  public:
    using shared = std::shared_ptr<almuhidat::Shape>;

    virtual double calculateArea() const = 0;
    virtual rectangle_t calculateFrameRect() const = 0;
    virtual void move(const point_t &newPos) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual shared clone() const = 0;
    void scale(double k);
    virtual ~Shape() = default;

  private:
    virtual void scaleShape(double k) = 0;
  };

  double getWidth(const Shape &shape);
  double getHeight(const Shape &shape);
  double getX(const Shape &shape);
  double getY(const Shape &shape);
}
#endif
