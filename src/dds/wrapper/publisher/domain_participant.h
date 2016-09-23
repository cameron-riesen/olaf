#ifndef DOMAIN_PARTICIPANT_H
#define DOMAIN_PARTICIPANT_H

#include <ace/Log_Msg.h>

#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>

#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/WaitSet.h>

#include "dds/DCPS/StaticIncludes.h"

#include "publisher.h"
#include "subscriber.h"
#include "topic.h"

class Domain_Participant
{
public:
  Domain_Participant(int &argc, char **argv, DDS::DomainId_t did, DDS::DomainParticipantQos qos, DDS::DomainParticipantListener *list, DDS::StatusMask mask);

  /* Publisher *create_p(DDS::PublisherQos qos, DDS::PublisherListener *lis, DDS::StatusMask mask); */
  /* Subscriber *create_s(DDS::SubscriberQos qos, DDS::SubscriberListener *lis, DDS::StatusMask mask); */
  /* Topic *create_t(std::string topic, std::string name, DDS::TopicQos qos, DDS::TopicListener *list, DDS::StatusMask);  */

private:
  DDS::DomainParticipant_var participant;
};

#endif // DOMAIN_PARTICIPANT_H
