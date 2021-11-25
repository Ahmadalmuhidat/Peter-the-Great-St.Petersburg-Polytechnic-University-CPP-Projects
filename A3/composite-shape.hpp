#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include "shape.hpp"
#include <stdexcept>

namespace almuhidat
{
  class CompositeShape: public Shape
  {
  public:
    template < typename... Shapes >
    CompositeShape(Shapes... sources);
    CompositeShape(const CompositeShape &source);
    CompositeShape(CompositeShape &&source) noexcept = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double dx, double dy) override;
    using shape_pointer = std::shared_ptr< almuhidat::Shape >;
    shape_pointer clone() const override;

  private:
    size_t size_;
    using shape_arr = std::unique_ptr< shape_pointer[] >;
    shape_arr members_;
    void scaleShape(double k) override;
  };

  template < typename... Shapes >
  CompositeShape::CompositeShape(Shapes... sources):
    size_(sizeof...(Shapes)),
    members_(std::make_unique< shape_pointer[] >(size_))
  {
    if ( size_ == 0 )
    {
      throw std::invalid_argument("[-] the shape size can not be 0");
    }
    std::unique_ptr< Shape > tempContainer[] = {std::move(sources)...};
    for (size_t i = 0; i < size_; i++)
    {
      members_[i] = std::move(tempContainer[i]);
    }
  }
}
#endif
