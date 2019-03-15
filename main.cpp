#include <iostream>
#include <krpc.hpp>
#include <krpc/services/space_center.hpp>
#include <krpc/services/krpc.hpp>

#include "Vector3.hpp"
#include "CSER.hpp"
#include <cmath>
#include <zconf.h>
#include "events/TestEvent.hpp"
#include "events/EventManager.hpp"

bool guiding = true;

int main() {

    auto conn = krpc::connect("TEST");

    krpc::services::SpaceCenter sc(&conn);
    krpc::services::KRPC krpc(&conn);


    auto vessel = sc.active_vessel();
    auto reference_frame = vessel.orbit().body().reference_frame();

    auto * r0 = new Vector3(vessel.position(reference_frame));
    auto * v0 = new Vector3(vessel.velocity(reference_frame));
    double x0 = 0;
    double tol = 1 * pow(10, -5);

    CSER* cser = new CSER();
    EventManager* eventManager = new EventManager();

    while(guiding) {
        double dt = (double) krpc.get_status().time_per_rpc_update();

        double mu = vessel.orbit().body().gravitational_parameter();

        if (! cser->firstRun) {
            r0 = &cser->r;
            v0 = &cser->v;
            x0 = cser->x;
        }

        cser->cse(*r0, *v0, dt, mu, x0, tol);

        TestEvent* testEvent = new TestEvent();
        testEvent->time = 0;
        testEvent->message = "Test Message";

        eventManager->addEvent(testEvent);
        eventManager->executeEvents(sc.ut());
        usleep(static_cast<__useconds_t>(dt));
    }

    return 0;

}