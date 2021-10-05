#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace almuhidat
{
  class Circle: public Shape
  {
  public:
    Circle(point_t position, double radius);
    double calculateArea() const override;
    rectangle_t calculateFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(double d_x, double d_y) override;
    shared clone() const override;

  private:
    point_t position_;
    double radius_;
    void scaleShape(double k) override;
  };
}
#endif

