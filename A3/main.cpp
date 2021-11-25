#include <iostream>
#include <memory>
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  std::cout << "TEST RECTANGLE" << "\n";

  using ShapePtr = std::unique_ptr< almuhidat::Shape >;
  using Rect = almuhidat::Rectangle;
  ShapePtr rect(std::make_unique< Rect > (Rect({2, 6}, 5, 3)));

  std::cout << "Rectangle Location: (";
  std::cout << almuhidat::getX(*rect) << ", " << almuhidat::getY(*rect);
  std::cout << ")" << "\n";

  rect->move(6, 9);
  std::cout << "Rectangle Location: (";
  std::cout << almuhidat::getX(*rect) << ", " << almuhidat::getY(*rect);
  std::cout  << ")" << "\n";
  std::cout << "Area of the Rectangle: " << rect->getArea() << "\n\n";

  std::cout << "TEST CIRCLE" << "\n";

  using Circle = almuhidat::Circle;
  ShapePtr circle(std::make_unique< Circle >(Circle({2.4, 2.8}, 3)));

  std::cout << "Circle Location: (";
  std::cout << almuhidat::getX(*circle) << ", " << almuhidat::getY(*circle);
  std::cout << ")" << "\n";

  circle->move(14.3, 15.7);

  std::cout << "Circle Location: (";
  std::cout << almuhidat::getX(*circle) << ", " << almuhidat::getY(*circle);
  std::cout << ")" << "\n";
  std::cout << "Area of the Circle: " << circle->getArea() << "\n\n";

  std::cout << "TEST COMPOSITE SHAPE" << "\n";

  ShapePtr rect2(std::make_unique< Rect > (Rect({2, 2}, 4, 4)));
  using CShape = almuhidat::CompositeShape;
  ShapePtr composite(std::make_unique< CShape > (CShape(std::move(rect), std::move(circle), std::move(rect2))));

  std::cout << "Composite Shape Location: (";
  std::cout << almuhidat::getX(*composite) << ", " << almuhidat::getY(*composite);
  std::cout << ")" << "\n";
  std::cout << "Area of the Composite Shape: " << composite->getArea() << "\n";

  composite->scale(2);
  std::cout << "Composite Shape Location: (";
  std::cout << almuhidat::getX(*composite) << ", " << almuhidat::getY(*composite);
  std::cout << ")" << "\n";
  std::cout << "New Area of the Composite Shape: " << composite->getArea() << "\n";

  return 0;
}
