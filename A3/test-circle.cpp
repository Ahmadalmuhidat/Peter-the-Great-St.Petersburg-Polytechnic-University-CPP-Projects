#include <boost/test/unit_test.hpp>
#include "test-functions.hpp"
#include "circle.hpp"

double Radius = 3.0;
const almuhidat::point_t Position {1.0, 3.0};

std::unique_ptr<almuhidat::Shape> almuhidat::makeCircle()
{
  return std::make_unique<almuhidat::Circle>(almuhidat::Circle(Position, Radius));
}

BOOST_AUTO_TEST_SUITE(TEST_CIRCLE);

BOOST_AUTO_TEST_CASE(Move_Circle)
{
  almuhidat::PointToPoint(*almuhidat::makeCircle());
}

BOOST_AUTO_TEST_CASE(Scale_Circle)
{
  almuhidat::testScale(*almuhidat::makeCircle());
}

BOOST_AUTO_TEST_SUITE_END()
