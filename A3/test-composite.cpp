#include "boost/test/unit_test.hpp"
#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(TEST_COMPOSITE);

BOOST_AUTO_TEST_CASE(Scale_CompositeShape)
{
  almuhidat::testScale(*(almuhidat::makeCompositeShape()));
}

BOOST_AUTO_TEST_CASE(Test_Move_CompositeShape)
{
  almuhidat::PointToPoint(*(almuhidat::makeCompositeShape()));
}

BOOST_AUTO_TEST_SUITE_END();
