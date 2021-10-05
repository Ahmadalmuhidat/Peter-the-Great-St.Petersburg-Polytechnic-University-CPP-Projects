#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace almuhidat
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t pos, double height, double width);
    double calculateArea() const override;
    rectangle_t calculateFrameRect() const override;
    void move(const point_t &newPos) override;
    void move(double dx, double dy) override;
    shared clone() const override;

  private:
    double height, width;
    point_t position;
    void scaleShape(double k) override;
  };
}
#endif
