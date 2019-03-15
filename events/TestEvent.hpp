//
// Created by michaelm on 3/14/19.
//

#ifndef GNC_TESTEVENT_HPP
#define GNC_TESTEVENT_HPP

#endif //GNC_TESTEVENT_HPP

#include <iostream>
#include "Event.hpp"

class TestEvent : public Event {
    void run() {
        std::cout << message << std::endl;
    }
};