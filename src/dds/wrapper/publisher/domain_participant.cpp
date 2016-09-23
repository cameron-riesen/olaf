#include "domain_participant.h"

#include <iostream>

Domain_Participant::Domain_Participant(int &argc, char **argv, DDS::DomainId_t did, DDS::DomainParticipantQos qos, DDS::DomainParticipantListener *list, DDS::StatusMask mask)
{
  // int arg_count = 3;
  // char **arg_vector = new char*[arg_count];
  // arg_vector[0] = new char[9+1];
  // arg_vector[1] = new char[13+1];
  // arg_vector[2] = new char[17+1];

  // std::strcpy(arg_vector[0], "publisher");
  // std::strcpy(arg_vector[1], "-DCPSInfoRepo");
  // std::strcpy(arg_vector[2], "file://simple.ior");
  
  DDS::DomainParticipantFactory_var factory = TheParticipantFactoryWithArgs(argc, argv);
  this->participant = factory->create_participant(did, qos, list, mask);

  if (!this->participant)
  {
    std::cout << "Fucked up son...\n" << std::endl;
  }
}

// Publisher *Domain_Participant::create_p(DDS::PublisherQos qos, DDS::PublisherListener *lis, DDS::StatusMask mask)
// {
//   return (new Publisher());
// }

// Subscriber *Domain_Participant::create_s(DDS::SubscriberQos qos, DDS::SubscriberListener *lis, DDS::StatusMask mask)
// {
//   return (new Subscriber());
// }

// Topic *Domain_Participant::create_t(std::string topic, std::string name, DDS::TopicQos qos, DDS:TopicListener *list, DDS::StatusMask)
// {
//   return (new Topic());
// }
