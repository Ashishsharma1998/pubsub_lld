#pragma once

#include "Message.hpp"
class SubInterface{
    public:
     virtual void onMessage(Message *m)=0;
};