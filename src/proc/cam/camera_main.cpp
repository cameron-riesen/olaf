#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>

#include <dds/dds.hpp>

int main()
{
  log4cplus::Initializer init;
  log4cplus::PropertyConfigurator config("/home/pi/Documents/olaf/config/log4cplus.properties");
  config.configure();

  log4cplus::Logger file_logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("Olaf_File_Logger"));
  log4cplus::Logger console_logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("Olaf_Console_Logger"));

  LOG4CPLUS_INFO(console_logger, "Camera main started");

  dds::domain::DomainParticipant participant(0);
}
