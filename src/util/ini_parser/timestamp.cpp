#include "timestamp.h"

#include <tuple>

namespace Ini_Parser
{
  Timestamp::Timestamp(const std::tm &time) :
    hour(tm.tm_hour),
    minute(tm.tm_min),
    second(tm.tm_sec)
  {
    this->tm.tm_hour = time.tm_hour;
    this->tm.tm_min = time.tm_min;
    this->tm.tm_sec = time.tm_sec;
  }

  Timestamp::Timestamp(const Timestamp &other) :
    hour(tm.tm_hour),
    minute(tm.tm_min),
    second(tm.tm_sec)
  {
    this->tm.tm_hour = other.tm.tm_hour;
    this->tm.tm_min = other.tm.tm_min;
    this->tm.tm_sec = other.tm.tm_sec;
  }
  
  Timestamp::Timestamp(Timestamp &&other) :
    hour(tm.tm_hour),
    minute(tm.tm_min),
    second(tm.tm_sec)
  {
    this->tm.tm_hour = other.tm.tm_hour;
    this->tm.tm_min = other.tm.tm_min;
    this->tm.tm_sec = other.tm.tm_sec;

    other.tm.tm_hour = 0;
    other.tm.tm_min = 0;
    other.tm.tm_sec = 0;
  }
  
  Timestamp &Timestamp::operator=(const Timestamp &other)
  {
    this->tm.tm_hour = other.tm.tm_hour;
    this->tm.tm_min = other.tm.tm_min;
    this->tm.tm_sec = other.tm.tm_sec;

    return (*this);
  }
  
  Timestamp &Timestamp::operator=(Timestamp &&other)
  {
    this->tm.tm_hour = other.tm.tm_hour;
    this->tm.tm_min = other.tm.tm_min;
    this->tm.tm_sec = other.tm.tm_sec;

    other.tm.tm_hour = 0;
    other.tm.tm_min = 0;
    other.tm.tm_sec = 0;

    return (*this);
  }

  bool Timestamp::operator==(const Timestamp &other)
  {
    return (std::tie(this->hour, this->minute, this->second) ==
	    std::tie(other.hour, other.minute, other.second));
  }
  
  bool Timestamp::operator!=(const Timestamp &other)
  {
    return (std::tie(this->hour, this->minute, this->second) !=
	    std::tie(other.hour, other.minute, other.second));
  }
  
  bool Timestamp::operator>(const Timestamp &other)
  {
    return (std::tie(this->hour, this->minute, this->second) >
	    std::tie(other.hour, other.minute, other.second));
  }
  
  bool Timestamp::operator<(const Timestamp &other)
  {
    return (std::tie(this->hour, this->minute, this->second) <
	    std::tie(other.hour, other.minute, other.second));
  }
  
  bool Timestamp::operator>=(const Timestamp &other)
  {
    return (std::tie(this->hour, this->minute, this->second) >=
	    std::tie(other.hour, other.minute, other.second));
  }
  
  bool Timestamp::operator<=(const Timestamp &other)
  {
    return (std::tie(this->hour, this->minute, this->second) <=
	    std::tie(other.hour, other.minute, other.second));
  }
  
  std::ostream &operator<<(std::ostream &os, const Timestamp &time)
  {
    char buff[100];

    if (std::strftime(buff, sizeof(buff), "%T", &time.tm))
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
