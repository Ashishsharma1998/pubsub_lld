#pragma once
#include<string>
class Message{
   private:
    std::string content;
   public:
    Message(std::string content){
        this->content=content;
    } 

    std::string getContent(){
        return content;
    }
};