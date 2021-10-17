#include "UserInterFace.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>


std::istream & almuhidat::operator>>(std::istream &stream, almuhidat::phoneBook::Record &record)
{
  const char BOUND_CHAR = '\"';

  std::istream::sentry sentry(stream);
  if (sentry)
  {
    stream >> std::ws >> record.first;
    char c;
    stream >> c;
    if (stream.fail())
    {
      return stream;
    }
    if (c != BOUND_CHAR)
    {
      stream.setstate(std::istream::failbit);
      return stream;
    }
    std::string tmp;
    std::getline(stream, tmp);
    tmp = tmp.substr(0, tmp.rfind(BOUND_CHAR));
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\\'), tmp.end());
    record.second = tmp;
  }
  return stream;
}

almuhidat::UserInterFace::UserInterFace(): 
  book_()
{
  this->bookmarks_.emplace("current", this->book_.end());
}

void almuhidat::UserInterFace::readCommand()
{
  const std::string INVALID_COMMAND = "<INVALID COMMAND>";

  while (std::cin)
  {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream line(input);

    if (std::cin.fail())
    {
      if (std::cin.eof())
      {
        break;
      }
      else
      {
        throw std::runtime_error("Invalid input.");
      }
    }
    else
    {
      std::string inputWord, tmp;
      line >> inputWord;
      if (inputWord == "add")
      {
        almuhidat::phoneBook::Record record;
        line >> record;
        if (!line.fail())
        {
          add(record);
        }
        else
        {
          std::cout << INVALID_COMMAND << std::endl;
        }
      }
      else if (inputWord == "store")
      {
        std::string markName, newMarkName;
        line >> markName;
        line >> newMarkName;
        storeBookmark(markName, newMarkName);
      }
      else if (inputWord == "insert")
      {
        std::string markName;
        line >> tmp;
        line >> markName;
        almuhidat::phoneBook::Record record;
        line >> record;

        if (!line.fail())
        {
          if (tmp == "before")
          {
            this->addBefore(markName, record);
          }
          else if (tmp == "after")
          {
            this->addAfter(markName, record);
          }
        }
        else
        {
          std::cout << INVALID_COMMAND << std::endl;
        }
      }
      else if (inputWord == "delete")
      {
        line >> tmp;
        this->Delete(tmp);
      }
      else if (inputWord == "show")
      {
        line >> tmp;
        this->Dispaly(tmp);
      }
      else if (inputWord == "move")
      {
        line >> tmp;
        std::string keyWord;
        line >> keyWord;
        if (keyWord == "first")
        {
          moveFirst(tmp);
        }
        else if (keyWord == "last")
        {
          moveLast(tmp);
        }
        else
        {
          std::istringstream stream(keyWord);
          almuhidat::UserInterFace::difference_type steps;
          stream >> steps;

          if (stream.fail())
          {
            std::cout << "<INVALID STEP>" << std::endl;
          }
          move(tmp, steps);
        }
      }
      else
      {
        std::cout << INVALID_COMMAND << std::endl;
      }
    }
  }
}

void almuhidat::UserInterFace::Dispaly(std::string markName)
{
  almuhidat::UserInterFace::iterator tmp = this->bookmarks_.find(markName);
  if (tmp != this->bookmarks_.end())
  {
    if (tmp->second != this->book_.end())
    {
      std::cout << tmp->second->first << " " << tmp->second->second << std::endl;
    }
    else
    {
      std::cout << "<EMPTY>" << std::endl;
    }
  }
  else
  {
    std::cout << "<INVALID BOOKMARK>" << std::endl;
  }
}

void almuhidat::UserInterFace::storeBookmark(std::string markName, std::string newMarkName)
{
  almuhidat::UserInterFace::iterator it = this->bookmarks_.find(markName);
  if (it != this->bookmarks_.end())
  {
    if (!(this->bookmarks_.emplace(newMarkName, it->second).second))
    {
      this->bookmarks_[newMarkName] = it->second;
    }
  }
  else
  {
    std::cout << "<INVALID BOOKMARK>" << std::endl;
  }
}

void almuhidat::UserInterFace::addWithBookmark(std::string markName, std::string number, std::string name)
{
  almuhidat::phoneBook::Record record = std::make_pair(number, name);
  almuhidat::phoneBook::iterator it = this->book_.add(record);
  this->bookmarks_.emplace(markName, it);
}

void almuhidat::UserInterFace::addBefore(std::string markName, almuhidat::phoneBook::Record record)
{
 almuhidat::UserInterFace::iterator position = this->bookmarks_.find(markName);
  if (position != this->bookmarks_.end())
  {
    almuhidat::phoneBook::iterator it = this->book_.addBefore(position->second, record);
    if (this->bookmarks_.size() == 1)
    {
      position->second = it;
    }
  }
  else
  {
    std::cout << "<INVALID BOOKMARK>" << std::endl;
  }
}

void almuhidat::UserInterFace::addAfter(std::string markName, almuhidat::phoneBook::Record record)
{
  almuhidat::UserInterFace::iterator position = this->bookmarks_.find(markName);
  if (position != this->bookmarks_.end())
  {
    almuhidat::phoneBook::iterator it = book_.addAfter(position->second, record);
    if (this->bookmarks_.size() == 1)
    {
      position->second = it;
    }
  }
  else
  {
    std::cout << "<INVALID BOOKMARK>" << std::endl;
  }
}

void almuhidat::UserInterFace::add(almuhidat::phoneBook::Record record)
{
  if (book_.empty())
  {
    almuhidat::phoneBook::iterator it = book_.add(record);
    almuhidat::UserInterFace::iterator currentPosition = this->bookmarks_.find("current");
    currentPosition->second = it;
  }
  else
  {
    book_.add(record);
  }
}

void almuhidat::UserInterFace::moveFirst(std::string markName)
{
  almuhidat::UserInterFace::iterator position = this->bookmarks_.find(markName);
  position->second = book_.begin();
}

void almuhidat::UserInterFace::moveLast(std::string markName)
{
  almuhidat::UserInterFace::iterator position = this->bookmarks_.find(markName);
  position->second = std::prev(book_.end());
}

void almuhidat::UserInterFace::move(std::string markName, almuhidat::UserInterFace::difference_type stepNumber)
{
  almuhidat::UserInterFace::iterator position = bookmarks_.find(markName);

  if (position != bookmarks_.end())
  {
    for (almuhidat::UserInterFace::difference_type count = 0; count < std::abs(stepNumber); ++count)
    {
      (stepNumber > 0) ? ++position->second : --position->second;
    }
  }
}

void almuhidat::UserInterFace::Delete(std::string markName)
{
  if (!book_.empty())
  {
    almuhidat::UserInterFace::iterator position = this->bookmarks_.find(markName);
    almuhidat::phoneBook::iterator oldIt = position->second;
    position->second = book_.Delete(position->second);
    if (position->second == book_.end())
    {
      std::advance(position->second, -1);
    }
    for (almuhidat::UserInterFace::iterator it = this->bookmarks_.begin(); it != this->bookmarks_.end(); ++it)
    {
      if (it->second == oldIt)
      {
        it->second = position->second;
      }
    }
  }
}
