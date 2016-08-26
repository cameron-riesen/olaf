#ifndef LOGGER_H
#define LOGGER_H

#include <thread>
#include <mutex>

class Logger
{
public:
  virtual void log_debug(const std::string &msg) = 0;
  virtual void log_info(const std::string &msg) = 0;
  virtual void log_warning(const std::string &msg) = 0;
  virtual void log_error(const std::string &msg, const int level) = 0;
  virtual void log_fatal(const std::string &msg) = 0;

protected:
  std::mutex write_mutex;
  
private:

};

#endif // LOGGER_H
