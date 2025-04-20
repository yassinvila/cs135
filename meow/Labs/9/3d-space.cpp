/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW Project 9A-C

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

//find the from origin to 3d coord
double length(Coord3D *p);

//finds which set of points is farther. refers to length function
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2);

//allocates memory n init (idk)
Coord3D* createCoord3D(double x, double y, double z);

//velocity bro
void move(Coord3D *ppos, Coord3D *pvel, double dt);

//deletes the memory so ur pc doesnt crash
void deleteCoord3D(Coord3D *p);

int main() {
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};
    
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);
    move(ppos, pvel, 10.0);
    
    cout << "Coordinates after 10 seconds: " << 
    (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;
    
    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
    
    cout << length(&pointP) << endl; // would print 37.4166
    
    cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl << endl;
    
    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
    cout << "ans = " << ans << endl;
    
    //move(&ppos, &pvel, 2.0);
    //cout << ppos->x << " " << ppos->y << " " << ppos->z << endl;
}

double length(Coord3D *p) {
    double distance = sqrt((pow(p->x, 2)) + (pow(p->y, 2)) + (pow(p->z, 2)));
    return distance;
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2) {
    if (length(p1) < length(p2)) {
        return p2;
    } else return p1;
}

void move(Coord3D *ppos, Coord3D *pvel, double dt){
    ppos->x = ppos->x + (pvel->x * dt);
    ppos->y = ppos->y + (pvel->y * dt);
    ppos->z = ppos->z + (pvel->z *dt);
}

Coord3D * createCoord3D(double x, double y, double z) {
    Coord3D *meow = new Coord3D;
    meow->x = x;
    meow->y = y;
    meow->z = z;
    return meow; 
}

void deleteCoord3D(Coord3D *p) {
    delete p;
}