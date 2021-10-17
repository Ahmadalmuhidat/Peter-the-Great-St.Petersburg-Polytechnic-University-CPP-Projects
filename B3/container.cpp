#include "container.hpp"
#include <iostream>

almuhidat::Container::iterator &almuhidat::Container::iterator::operator++()
{
  this->current_++;
  this->value_ *= this->current_;
  return *this;
}

almuhidat::Container::iterator almuhidat::Container::iterator::operator++(int)
{
  iterator temp(*this);
  this->operator++();
  return temp;
}

almuhidat::Container::iterator &almuhidat::Container::iterator::operator--()
{
  this->value_ /= this->current_;
  this->current_--;
  return *this;
}

almuhidat::Container::iterator almuhidat::Container::iterator::operator--(int)
{
  iterator temp(*this);
  this->operator--();
  return temp;
}

bool almuhidat::Container::iterator::operator==(const iterator &src)
{
  if (this->value_ == src.value_)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool almuhidat::Container::iterator::operator!=(const iterator &src)
{
  if (this->value_ != src.value_)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int almuhidat::Container::iterator::operator*()
{
  return this->value_;
}

almuhidat::Container::reverse_iterator &almuhidat::Container::reverse_iterator::operator++()
{
  this->current_--;
  this->value_--;
  return *this;
}

almuhidat::Container::reverse_iterator almuhidat::Container::reverse_iterator::operator++(int)
{
  almuhidat::Container::reverse_iterator temp(*this);
  this->current_--;
  this->value_--;
  return temp;
}

almuhidat::Container::reverse_iterator &almuhidat::Container::reverse_iterator::operator--()
{
  this->current_++;
  this->value_++;
  return *this;
}

almuhidat::Container::reverse_iterator almuhidat::Container::reverse_iterator::operator--(int)
{
  almuhidat::Container::reverse_iterator temp(*this);
  this->current_++;
  this->value_++;
  return temp;
}
