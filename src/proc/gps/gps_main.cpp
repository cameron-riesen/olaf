#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>

int main()
{
  log4cplus::Initializer init;
  
  log4cplus::BasicConfigurator config;
  config.configure();

  log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("TEST"));

  LOG4CPLUS_INFO(logger, LOG4CPLUS_TEXT("GPS main started"));
}
