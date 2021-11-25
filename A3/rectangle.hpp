#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace almuhidat
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t &pos, double height, double width);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &newPos) override;
    void move(double dx, double dy) override;
    shared clone() const override;

  private:
    double height_;
    double width_;
    point_t pos_;
    void scaleShape(double k) override;
  };
}
#endif
