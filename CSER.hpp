//
// Created by michaelm on 3/14/19.
//

#ifndef GNC_CSER_HPP
#define GNC_CSER_HPP

#include "Vector3.hpp"
#include <cmath>

class CSER {
public:
    CSER() = default;

    void cse(Vector3 &r0, Vector3 &v0, double dt, double mu, double x0 = 0.0, double tol = (5 * pow(M_E, -5)));

    Vector3 r;
    Vector3 v;
    double x;

    bool firstRun = true;

private:
    double S(double &z);
    double C(double &z);
};


#endif //GNC_CSER_HPP
