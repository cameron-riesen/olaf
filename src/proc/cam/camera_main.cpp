#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>

#include "cam_config_msg_DCPS.hpp"

#include <iostream>

int main()
{
  log4cplus::Initializer init;
  log4cplus::PropertyConfigurator config("/home/pi/Documents/olaf/config/log4cplus.properties");
  config.configure();

  log4cplus::Logger file_logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("Olaf_File_Logger"));
  log4cplus::Logger console_logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("Olaf_Console_Logger"));

  LOG4CPLUS_INFO(console_logger, "Camera main started");

  dds::domain::DomainParticipant participant(0);
  dds::topic::Topic<Cam_Messages::Config_Message> topic(participant, "cam_messages_config_message");
  dds::pub::Publisher publisher(participant);
  dds::pub::DataWriter<Cam_Messages::Config_Message> data_writer(publisher, topic);

  Cam_Messages::Config_Message config_message(false, 10, 10, 1000);

  auto matches = data_writer.publication_matched_status();

  std::cout << "Waiting..." << "\n";
  
  while (matches.current_count() < 1)
  {
    matches = data_writer.publication_matched_status();
  }

  data_writer.write(config_message);

  std::cout << "wrote message" << "\n";
}
