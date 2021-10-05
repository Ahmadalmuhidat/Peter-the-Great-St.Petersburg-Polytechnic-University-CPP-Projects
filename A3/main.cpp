#include <iostream>
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"


using shape_pointer = std::unique_ptr<almuhidat::Shape>;
using namespace almuhidat;

int main()
{
  std::cout << "TEST RECTANGLE" << std::endl;
  double RX, RY;
  int Width, Height, RDX, RDY;
  std::cout << "X: ";
  std::cin >> RX;
  std::cout << "Y: ";
  std::cin >> RY;
  std::cout << "Rectangle Width: ";
  std::cin >> Width;
  std::cout << "Rectangle Height: ";
  std::cin >> Height;
  almuhidat::point_t rectangle_point{RX, RY};
  shape_pointer rectangle(std::make_unique<almuhidat::Rectangle>
               (almuhidat::Rectangle(rectangle_point, Height, Width)));
  std::cout << "Rectangle Location: (" << almuhidat::getX(*rectangle) <<
               " " << almuhidat::getY(*rectangle) << ")" << std::endl;
  rectangle->move(RDX, RDY);
  std::cout << "Rectangle Location: (" << almuhidat::getX(*rectangle) <<
               " " << almuhidat::getY(*rectangle) << ")" << std::endl;
  std::cout << "Area of the Rectangle: " << rectangle->calculateArea() << std::endl;
  std::cout << "---------------------------------/" << std::endl;

  std::cout << "TEST CIRCLE" << std::endl;
  double CX, CY;
  int Radius, CDX, CDY;
  std::cout << "X: ";
  std::cin >> CX;
  std::cout << "Y: ";
  std::cin >> CY;
  std::cout << "Radius: ";
  std::cin >> Radius;
  almuhidat::point_t circle_point{CX, CY};
  shape_pointer circle(std::make_unique<almuhidat::Circle>
               (almuhidat::Circle(circle_point, Radius)));
  std::cout << "Circle Location: (" << almuhidat::getX(*circle) <<
               "," << almuhidat::getY(*circle) << ")" << std::endl;
  circle->move(CDX, CDY);
  std::cout << "Circle Location: (" << almuhidat::getX(*circle) <<
               "," << almuhidat::getY(*circle) << ")" << std::endl;
  std::cout << "Area of the Circle: " << circle->calculateArea() << std::endl;
  std::cout << "---------------------------------/" << std::endl;

  std::cout << "TEST COMPOSITE SHAPE" << std::endl;
  double CPX, CPY;
  int Width2, Height2;
  std::cout << "Rectangle 2 X & Y: ";
  std:: cin >> CPX >> CPY;
  std::cout <<  "Rectangle 2 Width: ";
  std::cin >> Width2;
  std::cout << "Rectangle 2 Height: ";
  std::cin >> Height2;
  shape_pointer rectangle_2(std::make_unique<almuhidat::Rectangle>
               (almuhidat::Rectangle({CPX, CPY}, Height2, Width2)));
  shape_pointer composite(std::unique_ptr<almuhidat::CompositeShape>
               (almuhidat::CompositeShape(std::move(rectangle), std::move(rectangle_2), std::move(circle))));
  std::cout << "Composite Shape Location: (" << almuhidat::getX(*composite) <<
               " " << almuhidat::getY(*composite) << ")" << std::endl;
  std::cout << "Area of the Composite Shape: " << composite->calculateArea() << std::endl;
  composite->scale(6);
  std::cout << "Composite Shape Location: (" << almuhidat::getX(*composite) <<
               "," << almuhidat::getY(*composite) << ")" << std::endl;
  std::cout << "New Area of the Composite Shape: " << composite->calculateArea() << std::endl;

  return 0;
}
