#ifndef KEY_NOT_FOUND_EXCEPTION_H
#define KEY_NOT_FOUND_EXCEPTION_H

#include <exception>
#include <string>

namespace Ini_Parser
{
  //! \class Key_Not_Found_Exception
  //!
  //! \brief Thrown when a key is not found in the ini file tag
  class Key_Not_Found_Exception : public std::exception
  {
  public:
    //! \brief Constructor
    //!
    //! \param key_name The name of the key being searched for
    Key_Not_Found_Exception(const std::string &key_name);

    //! \brief Print error
    virtual const char* what() const throw();

  private:
    std::string name;
  };
}


#endif // KEY_NOT_FOUND_EXCEPTION_H
