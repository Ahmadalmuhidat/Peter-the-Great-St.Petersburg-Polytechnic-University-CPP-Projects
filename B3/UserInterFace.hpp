#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP
#include "PhoneBook.hpp"
#include <map>
#include <vector>
#include <iosfwd>

namespace almuhidat
{
  std::istream& operator>>(std::istream & stream, almuhidat::phoneBook::Record & record);

  class UserInterFace
  {
  public:
    using bookmark = std::pair<std::string, almuhidat::phoneBook::iterator>;
    using bookmarksList = std::map<std::string, almuhidat::phoneBook::iterator>;
    using iterator = bookmarksList::iterator;

    UserInterFace();
    void readCommand();
    void Dispaly(std::string markName);
    void add(almuhidat::phoneBook::Record record);
    void addWithBookmark(std::string markName, std::string number, std::string name);
    void storeBookmark(std::string markName, std::string newMarkName);
    void addBefore(std::string markName, almuhidat::phoneBook::Record record);
    void addAfter(std::string markName, almuhidat::phoneBook::Record record);
    using difference_type = almuhidat::phoneBook::addressType::difference_type;
    void move(std::string markName, difference_type stepNumber);
    void moveFirst(std::string markName);
    void moveLast(std::string markName);
    void Delete(std::string markName);

  private:
    bookmarksList bookmarks_;
    almuhidat::phoneBook book_;
  };
}
#endif
