#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include "shape.hpp"

namespace almuhidat
{
  class CompositeShape : public Shape
  {
  public:
    using shape_pointer = std::shared_ptr<almuhidat::Shape>;
    using shape_arr = std::unique_ptr<shape_pointer[]>;

    CompositeShape(shape_pointer source);
    CompositeShape(const CompositeShape &source);
    CompositeShape(CompositeShape &&source) noexcept = default;
    double calculateArea() const;
    rectangle_t calculateFrameRect() const;
    void move(const point_t &point) override;
    void move(double dx, double dy) override;
    size_t size() const;
    size_t capacity() const;
    shape_pointer operator[](const size_t index) const;
    shape_pointer clone() const override;

  private:
    size_t size_;
    size_t capacity_;
    std::unique_ptr<shape_pointer[]> members_;
    void scaleShape(double k) override;
  };
}
#endif
