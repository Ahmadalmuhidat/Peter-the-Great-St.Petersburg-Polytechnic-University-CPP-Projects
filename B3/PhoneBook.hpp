#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP
#include <list>
#include <string>

namespace almuhidat
{
  class phoneBook
  {
  public:
    using Record = std::pair<std::string, std::string>;
    using addressType = std::list<Record>;

    phoneBook();
    using iterator = addressType::iterator;
    iterator add(Record record);
    iterator addAfter(iterator pos, Record record);
    iterator addBefore(iterator pos, Record record);
    iterator Delete(iterator pos);
    void update(Record record);
    void previous();
    void forward();
    void Display();
    // void search(iterator & it, addressType::difference_type stepNumber);
    bool empty();
    iterator begin();
    iterator end();

  private:
    addressType addressList_;
    iterator currentRecord_;
  };
}
#endif
