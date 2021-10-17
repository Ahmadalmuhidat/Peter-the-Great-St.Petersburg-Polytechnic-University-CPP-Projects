#ifndef TOOLS_HPP
#define TOOLS_HPP
#include <iostream>
#include <vector>
#include <forward_list>

namespace almuhidat
{
  template < typename A >
  struct bracket
  {
    typedef std::size_t index;
    static typename A::reference Extract(A &vector, index i)
    {
      return vector[i];
    }

    static index first(A &vector)
    {
      return 0;
    }

    static index last(A &vector)
    {
      return vector.size();
    }
  };

  template < typename A >
  struct at
  {
    typedef typename A::size_type index;
    static typename A::reference Extract(A &vector, index i)
    {
      return vector.at(i);
    }

    static index first(A &vector)
    {
      return 0;
    }

    static index last(A &vector)
    {
      return vector.size();
    }
  };

  template < typename A >
  struct itr
  {
    typedef typename A::iterator index;
    static typename A::reference Extract(A &vector, index i)
    {
      return *i;
    }

    static index first(A &vector)
    {
      return vector.begin();
    }

    static index last(A &vector)
    {
      return vector.end();
    }
  };

  template < typename T >
  bool a(T a, T b)
  {
    return a > b;
  }

  template < typename T >
  bool b(T a, T b)
  {
    return a < b;
  }

  template < template < typename A > class List, typename A >
  void Sort(A &array, bool (*compare)(typename A::value_type &, typename A::value_type &))
  {
    typedef typename List< A >::index index;
    for (index i = List< A >::first(array); i != List< A >::last(array); i++)
    {
      for (index j = i; j != List< A >::last(array); j++)
      {
        if (compare(List< A >::Extract(array, i), List< A >::Extract(array, j)))
        {
          std::swap(List< A >::Extract(array, i), List< A >::Extract(array, j));
        }
      }
    }
  }

  template < typename A >
  void Display(const A &array)
  {
    for (typename A::const_iterator it = array.begin(); it != array.end(); it++)
    {
      std::cout << *it << " ";
    }
    std::cout << "\n";
  }
}
#endif
