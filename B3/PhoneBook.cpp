#include "PhoneBook.hpp"
#include <string>
#include <iostream>

almuhidat::phoneBook::phoneBook()
{
  this->currentRecord_ = this->addressList_.end();
}

almuhidat::phoneBook::iterator almuhidat::phoneBook::add(almuhidat::phoneBook::Record record)
{
  this->addressList_.push_back(record);
  if (this->addressList_.size() != 1)
  {
    this->currentRecord_ = std::prev(this->addressList_.end());
  }
  else
  {
    this->currentRecord_ = this->addressList_.begin();
  }
  return this->currentRecord_;
}

almuhidat::phoneBook::iterator almuhidat::phoneBook::addAfter(almuhidat::phoneBook::iterator pos, almuhidat::phoneBook::Record record)
{
  pos = this->addressList_.insert(std::next(pos), record);
  return pos;
}

almuhidat::phoneBook::iterator almuhidat::phoneBook::addBefore(almuhidat::phoneBook::iterator pos, almuhidat::phoneBook::Record record)
{
  pos = this->addressList_.insert(pos, record);
  return pos;
}

almuhidat::phoneBook::iterator almuhidat::phoneBook::Delete(almuhidat::phoneBook::iterator pos)
{
  return this->addressList_.erase(pos);
}

void almuhidat::phoneBook::update(almuhidat::phoneBook::Record record)
{
  if (this->currentRecord_ != this->addressList_.end())
  {
    this->currentRecord_ = this->addressList_.erase(this->currentRecord_++);
    this->currentRecord_ = this->addressList_.insert(this->currentRecord_, record);
  }
}

void almuhidat::phoneBook::previous()
{
  if (this->currentRecord_ != this->addressList_.begin())
  {
    this->currentRecord_--;
  }
}

bool almuhidat::phoneBook::empty()
{
  return addressList_.empty();
}

void almuhidat::phoneBook::forward()
{
  if (std::next(this->currentRecord_) != this->addressList_.end())
  {
    this->currentRecord_++;
  }
}

void almuhidat::phoneBook::Display()
{
  if (this->currentRecord_ != this->addressList_.end())
  {
    std::cout << this->currentRecord_->first << " " << this->currentRecord_->second << std::endl;
  }
}

almuhidat::phoneBook::iterator almuhidat::phoneBook::begin()
{
  return this->addressList_.begin();
}

almuhidat::phoneBook::iterator almuhidat::phoneBook::end()
{
  return this->addressList_.end();
}