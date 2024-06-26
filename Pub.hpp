#pragma once

#include "Topic.hpp"

class Pub{
   private: 
    std::set<Topic*> topics;
   public:
    Pub(){} 

    void registerTopic(Topic *topic){
        topics.insert(topic);
    }

    void publish(Topic *topic , Message *msg){
        if(topics.find(topic)==topics.end()){
           std::cout<<"This publisher can't publish to topic "<<topic->getName()<<std::endl;
           return;
        }
        topic->publish(msg);
    }
};