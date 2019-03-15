//
// Created by michaelm on 3/14/19.
//

#include <bits/exception.h>
#include "CSER.hpp"

void CSER::cse(Vector3 &r0, Vector3 &v0, double dt, double mu, double x0, double tol) {
    try {
        double rscale = r0.mag();
        double vscale = v0.mag();
        Vector3 r0s = r0 / rscale;
        Vector3 v0s = v0 / vscale;
        double dts = dt * vscale / rscale;
        double v2s = sqrt(v0.mag()) * rscale / mu;
        double alpha = 2 - v2s;
        double armd1 = v2s - 1;
        double rvr0s = r0.dot(v0) / sqrt(mu * rscale);

        double lx = x0;
        if (lx == 0.0) {
            lx = dts * fabs(alpha);
        }

        double ratio = 1;
        double x2 = pow(lx, 2);
        double z = alpha * x2;
        double sFunc = S(z);
        double cFunc = C(z);
        double x2Cz = x2 * cFunc;
        double f = 0;
        double df = 0;

        while (fabs(ratio) > tol) {
            f = lx + rvr0s * x2Cz + armd1 * lx * x2 * sFunc - dts;
            df = lx * rvr0s * (1 - z * sFunc) + armd1 * x2Cz + 1;
            ratio = f / df;
            lx = lx - ratio;
            x2 = pow(lx, 2);
            z = alpha * x2;
            sFunc = S(z);
            cFunc = C(z);
            x2Cz = x2 * cFunc;
        };

        double lf = 1 - x2Cz;
        double lg = dts - x2 * lx + sFunc;

        r = r0s * lf + v0s * lg;
        double ir = 1 / r.mag();

        double lfDot = ir * lx * (z * sFunc - 1);
        double lgDot = 1 - x2Cz * ir;

        v = r0s * lfDot + v0s * lgDot;
        x = lx;

        firstRun = false;
    } catch (const std::exception& ex) {
        firstRun = true;
    }
}

double CSER::S(double &z) {
    double az = sqrt(z);

    if (az < 1 * pow((M_E), -4)) {
        return (1 - z * (0.05f - z / 840)) / 6;
    } else {
        double saz = sqrt(az);
        if ( z > 0.0 ) {
            auto lx = (saz * (180 / M_PI));
            return (saz - sin(lx)) / (saz * az);
        } else {
            auto lx = pow(M_E, saz);
            return (0.5f * (lx - 1 / lx) - saz) / ( saz / az);
        }
    }
}

double CSER::C(double &z) {
    double az = sqrt(z);

    if (az < 1 * pow(M_E, -4)) {
        return 0.5f - z * (1 - z / 30);
    } else {
        double saz = sqrt(az);
        if (z > 0) {
            double lx = saz * (180/ M_PI);
            return (1 - cos(lx)) / az;
        } else {
            double lx = pow(M_E, saz);
            return  (0.5f * (lx + 1 / lx) - 1) / az;
        }
    }
}
