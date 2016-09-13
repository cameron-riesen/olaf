#include "datestamp.h"

namespace Ini_Parser
{
  Datestamp::Datestamp(const std::tm &date) :
    month(tm.tm_mon),
    day_of_month(tm.tm_mday),
    day_of_week(tm.tm_wday),
    year(tm.tm_year)
  {
    this->tm.tm_mon = date.tm_mon;
    this->tm.tm_mday = date.tm_mday;
    this->tm.tm_wday = date.tm_wday;
    this->tm.tm_year = date.tm_year;
  }

  Datestamp::Datestamp(const Datestamp &other) :
    month(tm.tm_mon),
    day_of_month(tm.tm_mday),
    day_of_week(tm.tm_wday),
    year(tm.tm_year)
  {
    this->tm.tm_mon = other.tm.tm_mon;
    this->tm.tm_mday = other.tm.tm_mday;
    this->tm.tm_wday = other.tm.tm_wday;
    this->tm.tm_year = other.tm.tm_year;
  }
  
  Datestamp::Datestamp(Datestamp &&other) :
    month(tm.tm_mon),
    day_of_month(tm.tm_mday),
    day_of_week(tm.tm_wday),
    year(tm.tm_year)
  {
    this->tm.tm_mon = other.tm.tm_mon;
    this->tm.tm_mday = other.tm.tm_mday;
    this->tm.tm_wday = other.tm.tm_wday;
    this->tm.tm_year = other.tm.tm_year;

    other.tm.tm_mon = 0;
    other.tm.tm_mday = 0;
    other.tm.tm_wday = 0;
    other.tm.tm_year = 0;
  }
  
  Datestamp &Datestamp::operator=(const Datestamp &other)
  {
    this->tm.tm_mon = other.tm.tm_mon;
    this->tm.tm_mday = other.tm.tm_mday;
    this->tm.tm_wday = other.tm.tm_wday;
    this->tm.tm_year = other.tm.tm_year;

    return (*this);
  }
  
  Datestamp &Datestamp::operator=(Datestamp &&other)
  {
    this->tm.tm_mon = other.tm.tm_mon;
    this->tm.tm_mday = other.tm.tm_mday;
    this->tm.tm_wday = other.tm.tm_wday;
    this->tm.tm_year = other.tm.tm_year;

    other.tm.tm_mon = 0;
    other.tm.tm_mday = 0;
    other.tm.tm_wday = 0;
    other.tm.tm_year = 0;

    return (*this);
  }

  std::ostream &operator<<(std::ostream &os, const Datestamp &date)
  {
    char buff[100];

    if (std::strftime(buff, sizeof(buff), "%A, %e %B %Y", &date.tm))
    {
      os << buff;
    }
    else
    {
      os << "[time parse error]";
    }
    
    return (os);
  }
}

