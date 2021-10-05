#include <boost/test/unit_test.hpp>
#include "test-functions.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(TEST_RECTANGLE);

BOOST_AUTO_TEST_CASE(Move_Rectangle)
{
  almuhidat::PointToPoint(*almuhidat::makeRectangle());
}

BOOST_AUTO_TEST_CASE(Scale_Rectangle)
{
  almuhidat::testScale(*almuhidat::makeRectangle());
}

BOOST_AUTO_TEST_SUITE_END();
