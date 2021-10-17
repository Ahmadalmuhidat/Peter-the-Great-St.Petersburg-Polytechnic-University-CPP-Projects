#ifndef CONTAINER_HPP
#define CONTAINER_HPP
#include <iterator>

namespace almuhidat
{
  class Container
  {
  public:
    class iterator: public std::iterator<std::bidirectional_iterator_tag, int>
    {
    public:
      iterator(int val): value_(val){};
      iterator &operator++();
      iterator operator++(int);
      iterator &operator--();
      iterator operator--(int);
      bool operator==(const iterator &src);
      bool operator!=(const iterator &src);
      int operator*();

    protected:
      int current_;
      int value_;
    };

    class reverse_iterator: public iterator
    {
    public:
      reverse_iterator(int value) : iterator(value){};
      reverse_iterator &operator++();
      reverse_iterator operator++(int);
      reverse_iterator &operator--();
      reverse_iterator operator--(int);
    };

    iterator begin()
    {
      return iterator(1);
    }

    iterator end()
    {
      return iterator(11);
    }

    reverse_iterator rbegin()
    {
      return reverse_iterator(10);
    }

    reverse_iterator rend()
    {
      return reverse_iterator(0);
    }
  };
}
#endif
