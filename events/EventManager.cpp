//
// Created by michaelm on 3/14/19.
//

#include "EventManager.hpp"

void EventManager::addEvent(Event *event) {
    events.push_back(event);
}

void EventManager::executeEvents(double now) {
    std::vector<Event*> filter = filterEvents(now);

    for (auto &i : filter) {
        i->run();
    }
}

std::vector<Event*> EventManager::filterEvents(double now) {

    std::vector<Event*> filter;

    for (int i = 0; i < events.size(); ++i) {
        if ( events[i]->time <= now) {
            filter.push_back(events[i]);
            events.erase(events.begin() + i);
        }

    }

    return filter;
}
