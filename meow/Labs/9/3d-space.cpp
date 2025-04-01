/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW Project 9A

Describe: define a function length() that receives the 
coordinates of a point P passed as a pointer, and computes 
the distance from the origin to the point P:
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Coord3D {
    public:
        double x;
        double y;
        double z;
};

double length(Coord3D *p);

int main() {
    Coord3D pointP = {10, 20, 30};
    cout << length(&pointP) << endl; // would print 37.4166
}

double length(Coord3D *p) {
    double distance = sqrt((pow(p->x, 2)) + (pow(p->y, 2)) + (pow(p->z, 2)));
    return distance;
}