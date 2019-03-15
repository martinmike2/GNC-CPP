//
// Created by michaelm on 3/14/19.
//

#ifndef GNC_EVENTMANAGER_HPP
#define GNC_EVENTMANAGER_HPP

#include <vector>
#include "Event.hpp"

class EventManager {
public:
    EventManager() = default;
    void addEvent(Event* event);
    void executeEvents(double now);
private:
    std::vector<Event*> events;

    std::vector<Event*> filterEvents(double now);
    void removeEvent(Event* event);

};


#endif //GNC_EVENTMANAGER_HPP
