//
// Created by michaelm on 3/14/19.
//

#ifndef GNC_EVENT_HPP
#define GNC_EVENT_HPP


#include <string>

struct Event {
    double time;
    std::string message;

    virtual void run() {};
};


#endif //GNC_EVENT_HPP
