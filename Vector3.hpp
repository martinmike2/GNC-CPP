//
// Created by michaelm on 3/14/19.
//

#ifndef GNC_VECTOR3_HPP
#define GNC_VECTOR3_HPP


#include <tuple>

class Vector3 {
public:
    Vector3(double x, double y, double z);
    Vector3();
    Vector3(std::tuple<double, double, double> tuple);

    double dot(Vector3 other);
    double mag();
    Vector3 cross(Vector3 other);
    Vector3 projectOn(Vector3 other);


    Vector3 operator + (Vector3 right);
    Vector3 operator + (int right);
    Vector3 operator + (double right);
    Vector3 operator * (Vector3 right);
    Vector3 operator * (int right);
    Vector3 operator * (double right);
    Vector3 operator / (Vector3 right);
    Vector3 operator / (int other);
    Vector3 operator / (double other);

     double getX() { return x; }
     double getY() { return y; }
     double getZ() { return z; }
private:
     double x;
     double y;
     double z;

};


#endif //GNC_VECTOR3_HPP
