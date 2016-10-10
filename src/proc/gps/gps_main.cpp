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

  LOG4CPLUS_INFO(console_logger, LOG4CPLUS_TEXT("GPS main started"));

  dds::domain::DomainParticipant participant(0);

  dds::topic::Topic<Cam_Messages::Config_Message> topic(participant, "cam_messages_config_message");
  dds::sub::Subscriber subscriber(participant);
  dds::sub::DataReader<Cam_Messages::Config_Message> data_reader(subscriber, topic);

  dds::core::cond::WaitSet wait_set;

  dds::sub::cond::ReadCondition read_condition(data_reader, dds::sub::status::DataState::new_data());

  wait_set += read_condition;

  std::cout << "Subscriber waiting..." << "\n";

  wait_set.wait();

  auto samples = data_reader.read();

  std::for_each(samples.begin(),
                samples.end(),
                [](const dds::sub::Sample<Cam_Messages::Config_Message> &message)
                {
                  std::cout << "Got it.\n";
                });
}
