#include "timestamp.h"

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
    return (this->hour == other.hour &&
	    this->minute == other.minute &&
	    this->second == other.second);
  }
  
  bool Timestamp::operator!=(const Timestamp &other)
  {
    return (!(*this == other));
  }
  
  bool Timestamp::operator>(const Timestamp &other)
  {
    int this_total_seconds = (this->hour * 60 * 60) + (this->minute * 60) + this->second;
    int other_total_seconds = (other.hour * 60 * 60) + (other.minute * 60) + other.second;

    return (this_total_seconds > other_total_seconds);
  }
  
  bool Timestamp::operator<(const Timestamp &other)
  {
    return (!(*this > other) && !(*this == other));
  }
  
  bool Timestamp::operator>=(const Timestamp &other)
  {
    return ((*this > other) || (*this == other));
  }
  
  bool Timestamp::operator<=(const Timestamp &other)
  {
    return ((*this < other) || (*this == other));
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
