//
// Created by michaelm on 3/14/19.
//

#include <cmath>
#include "Vector3.hpp"
#include <tuple>

Vector3::Vector3(double x, double y, double z) :
    x(x), y(y), z(z){
}

Vector3::Vector3(std::tuple<double, double, double> tuple):
    x(std::get<0>(tuple)), y(std::get<1>(tuple)), z(std::get<2>(tuple)){
}

Vector3::Vector3() : x(0.0), y(0.0), z(0.0) {
}

double Vector3::dot(Vector3 other) {
    return x * other.getX() + y * other.getY() + z * other.getZ();
}

double Vector3::mag() {
    return sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2)));
}

Vector3 Vector3::cross(Vector3 other) {
    return {
            y * other.getZ() - z * other.getY(),
            z * other.getX() - x * other.getZ(),
            x * other.getY() - y * other.getX()
    };
}

Vector3 Vector3::operator+(double right) {
    return {
        x + right,
        y + right,
        z + right
    };
}

Vector3 Vector3::operator*(double right) {
    return {
        x * right,
        y * right,
        z * right
    };
}

Vector3 Vector3::operator/(double other) {
    return {
        x / other,
        y / other,
        z / other
    };
}

Vector3 Vector3::projectOn(Vector3 other) {
    return Vector3();
}

Vector3 Vector3::operator+(Vector3 right) {
    return {
        x + right.getX(),
        y + right.getY(),
        z + right.getZ()
    };
}

Vector3 Vector3::operator+(int right) {
    return {
        x + right,
        y + right,
        z + right
    };
}

Vector3 Vector3::operator*(Vector3 right) {
    return {
        x * right.getX(),
        y * right.getY(),
        z * right.getZ()
    };
}

Vector3 Vector3::operator*(int right) {
    return {
        x * right,
        y * right,
        z * right
    };
}

Vector3 Vector3::operator/(Vector3 right) {
    return {
        x / right.getX(),
        y / right.getY(),
        z / right.getZ()
    };
}

Vector3 Vector3::operator/(int other) {
    return {
        x / other,
        y / other,
        z / other
    };
}
