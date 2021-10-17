#include <boost/test/unit_test.hpp>
#include "tools.hpp"

BOOST_AUTO_TEST_SUITE(Testing_Sort)

BOOST_AUTO_TEST_CASE(At_Sorting_Ascending)
{
  int result[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector< int > Vtest{5, 3, 4, 1, 2, 7, 6, 10, 8, 9};

  almuhidat::Sort<almuhidat::at, std::vector<int>>(Vtest, almuhidat::a);

  BOOST_CHECK_EQUAL_COLLECTIONS(Vtest.begin(), Vtest.end(), result, result + 5);
}

BOOST_AUTO_TEST_CASE(At_Sorting_Descending)
{
  int result[]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector< int > Vtest{5, 3, 4, 1, 2, 7, 6, 10, 8, 9};

  almuhidat::Sort<almuhidat::at, std::vector<int>>(Vtest, almuhidat::b);

  BOOST_CHECK_EQUAL_COLLECTIONS(Vtest.begin(), Vtest.end(), result, result + 5);
}

BOOST_AUTO_TEST_CASE(Bracket_Sorting_Ascending)
{
  int result[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector< int > Vtest{5, 3, 4, 1, 2, 7, 6, 10, 8, 9};

  almuhidat::Sort<almuhidat::bracket, std::vector<int>>(Vtest, almuhidat::a);

  BOOST_CHECK_EQUAL_COLLECTIONS(Vtest.begin(), Vtest.end(), result, result + 10);
}

BOOST_AUTO_TEST_CASE(Bracket_Sorting_Descending)
{
  int result[]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector< int > Vtest{5, 3, 4, 1, 2, 7, 6, 10, 8, 9};

  almuhidat::Sort<almuhidat::bracket, std::vector<int>>(Vtest, almuhidat::b);

  BOOST_CHECK_EQUAL_COLLECTIONS(Vtest.begin(), Vtest.end(), result, result + 10);
}

BOOST_AUTO_TEST_CASE(Itr_Sorting_Ascending)
{
  int result[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector< int > Vtest{5, 3, 4, 1, 2, 7, 6, 10, 8, 9};

  almuhidat::Sort<almuhidat::itr, std::vector<int>>(Vtest, almuhidat::a);

  BOOST_CHECK_EQUAL_COLLECTIONS(Vtest.begin(), Vtest.end(), result, result + 10);
}

BOOST_AUTO_TEST_CASE(Itr_Sorting_Descending)
{
  int result[]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector< int > Vtest{5, 3, 4, 1, 2, 7, 6, 10, 8, 9};

  almuhidat::Sort<almuhidat::itr, std::vector<int>>(Vtest, almuhidat::b);

  BOOST_CHECK_EQUAL_COLLECTIONS(Vtest.begin(), Vtest.end(), result, result + 10);
}

BOOST_AUTO_TEST_SUITE_END();