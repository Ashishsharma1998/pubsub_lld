#pragma once

#include<set>
#include<iostream>
#include "Topic.hpp"
#include "InterfaceSub.hpp"

class Sub:public SubInterface{
  private:
    std::string name;

  public:
   Sub(std::string name){
      this->name = name;
   }

   void onMessage(Message *m){
     std::cout<<"subscriber "<<name<<" received message :"<<m->getContent()<<std::endl;
   }

};
