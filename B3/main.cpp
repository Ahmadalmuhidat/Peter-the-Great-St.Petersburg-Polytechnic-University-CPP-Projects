#include "PhoneBook.hpp"
#include "container.hpp"
#include "UserInterFace.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iterator>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    throw std::invalid_argument("[-] there must be only one argument [task number].");
    return 0;
  }

  int labNumber = 0;
  std::istringstream istr(argv[1]);
  istr >> labNumber;
  if (istr.fail())
  {
    throw std::invalid_argument("[-] first argument must be a number.");
    return 0;
  }

  try
  {
    switch (labNumber)
    {
    case 1:
    {
      almuhidat::UserInterFace userInterFace;
      userInterFace.readCommand();
      break;
    }
    case 2:
    {
      almuhidat::Container Container;
      std::copy(Container.begin(), Container.end(), std::ostream_iterator<int>(std::cout, " "));
      std::copy(Container.rbegin(), Container.rend(), std::ostream_iterator<int>(std::cout, " "));
      break;
    }

    default:
      throw std::invalid_argument("[-] first argument must be between 1 and 2.");
      return 1;
    }
  }
  catch (const std::invalid_argument &ia)
  {
    std::cerr << ia.what() << '\n';
  }
  catch (const std::runtime_error &re)
  {
    std::cerr << re.what() << "\n";
  }
  catch (...)
  {
    std::cerr << "[-] Unknowen error." << std::endl;
  }

  return 0;
}