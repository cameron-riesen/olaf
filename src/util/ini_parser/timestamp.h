#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <ctime>
#include <ostream>

namespace Ini_Parser
{
  struct Timestamp
  {
  public:
    Timestamp(const std::tm &time);
    Timestamp(const Timestamp &other);
    Timestamp(Timestamp &&other);
    
    Timestamp &operator=(const Timestamp &other);
    Timestamp &operator=(Timestamp &&other);
    bool operator==(const Timestamp &other);
    bool operator!=(const Timestamp &other);
    bool operator>(const Timestamp &other);
    bool operator<(const Timestamp &other);
    bool operator>=(const Timestamp &other);
    bool operator<=(const Timestamp &other);
    
    ~Timestamp() = default;

    int &hour;
    int &minute;
    int &second;
    
  private:
    friend std::ostream &operator<<(std::ostream &os, const Timestamp &time);
    std::tm tm;
  };

  std::ostream &operator<<(std::ostream &os, const Timestamp &time);
}

#endif // TIMESTAMP_H

