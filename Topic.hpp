#pragma once
#include "Sub.hpp"
#include<set>
#include<string>

class Topic{
    private:
     std::string name;
     std::set<Sub*> subcribers;
     
    public:
     Topic(std::string name){
       this->name=name;
     }   

     std::string getName(){
        return name;
     }

     void addSub(Sub *s){
        subcribers.insert(s);
     } 

     void removeSub(Sub *s){
        subcribers.erase(s);
     }

     void publish(Message *m){
       for(auto sub:subcribers){
           sub->onMessage(m);
       }
     }
};