#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace almuhidat
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t &position, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(double d_x, double d_y) override;
    shared clone() const override;

  private:
    point_t pos_;
    double radius_;
    void scaleShape(double k) override;
  };
}
#endif

