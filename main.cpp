#include "Message.hpp"
#include "Pub.hpp"
#include "Sub.hpp"
#include "Topic.hpp"
#include "PubSubSystem.hpp"
#include<vector>
#include<thread>



void publishing(PubSubSystem *instance , std::vector<Topic*> &topics , std::vector<Message*> &msgs ,Pub* pub){
    for(int i=0;i<topics.size();i++){
        instance->publish(topics[i],msgs[i],pub);
    }
}


int main(){
    
    PubSubSystem *instance = PubSubSystem::getInstance(); 

    //created topic
    Topic *topic1 = new Topic("topic1");
    Topic *topic2 = new Topic("topic2");
    
    //created publisher
    Pub *pub1 = new Pub();
    Pub *pub2 = new Pub();
    
    //register toopic
    instance->addTopic(topic1,pub1);
    instance->addTopic(topic2,pub2);

    //created msg
    Message *msg1 = new Message("msg1");
    Message *msg2 = new Message("msg2");


    //created subs
    Sub *sub1 = new Sub("sub1");
    Sub *sub2 = new Sub("sub2");
    Sub *sub3 = new Sub("sub3");
    
    instance->addSubcriber(topic1 , sub1);
    instance->addSubcriber(topic2 , sub2);
    instance->addSubcriber(topic2 , sub3);
    

    std::vector<Topic*> topics = {topic1,topic2};
    std::vector<Message*> msgs = {msg1,msg2};  
    std::thread th1(publishing,instance,std::ref(topics) , std::ref(msgs),pub1);
    std::thread th2(publishing,instance,std::ref(topics) , std::ref(msgs),pub2);

    th1.join();
    th2.join();
 
   
   return 0;
}