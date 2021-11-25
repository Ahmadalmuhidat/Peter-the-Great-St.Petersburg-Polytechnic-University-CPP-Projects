#include <boost/test/unit_test.hpp>
#include "test-functions.hpp"
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(TEST_CIRCLE);

BOOST_AUTO_TEST_CASE(Move_Circle)
{
  almuhidat::PointToPoint(*(almuhidat::makeCircle()));
}

BOOST_AUTO_TEST_CASE(Scale_Circle)
{
  almuhidat::testScale(*(almuhidat::makeCircle()));
}

BOOST_AUTO_TEST_SUITE_END()
