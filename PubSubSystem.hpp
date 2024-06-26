#pragma once

#include<set>
#include<map>
#include "Topic.hpp"
#include "Sub.hpp"
#include "Pub.hpp"
#include "GlobalLock.hpp"

class PubSubSystem{
  private:
      static PubSubSystem *instance;
      std::set<Topic*> topics;
      std::map<Topic*,std::set<Sub*>> subcribers;
      std::map<Topic*,std::set<Pub*>> publishers;

    PubSubSystem(){
        std::cout<<"instance has been instantiated"<<std::endl;
    }  

  public:
    
    //double lock checking
   static PubSubSystem* getInstance(){
        if(instance==nullptr){
            std::lock_guard<std::mutex> lock(GlobalLock::mtx);
             if(instance==nullptr){
                instance = new PubSubSystem();
             }
        }
        return instance;
    }
  
    void addTopic(Topic* t , Pub *p){
      std::lock_guard<std::mutex> lock(GlobalLock::mtx);  
      topics.insert(t);
      publishers[t].insert(p);  
      p->registerTopic(t);
    }

    void addSubcriber(Topic *t,Sub *s){
        std::lock_guard<std::mutex> lock(GlobalLock::mtx);
        subcribers[t].insert(s);
        t->addSub(s);
    }

    void publish(Topic *t,Message *m , Pub *p){
        std::lock_guard<std::mutex> lock(GlobalLock::mtx);
        p->publish(t,m);
    }

    std::set<Topic*> getAllTopics(){
        return topics;
    }

    std::map<Topic*,std::set<Sub*>> getAllSubscribers(){
        return subcribers;
    } 
    
    std::map<Topic*,std::set<Pub*>> getAllPublishers(){
        return publishers;
    }
};

PubSubSystem* PubSubSystem::instance=nullptr;

