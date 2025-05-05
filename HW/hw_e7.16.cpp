/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E7.14 CPP

Describe: Define a structure Point. A point has an x- and a y-coordinate. 
Write a function double distance(Point a, Point b) that computes the distance
 from a to b. Write a program that reads the coordinates of the points, calls
  your function, and displays the result.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Point
{
    double xCoor;
    double yCoor;
};

double distance(Point a, Point b);
int main () {
    Point meow;
    meow.xCoor = 5.7;
    meow.yCoor = 7.8;
    
    Point ruff;
    ruff.xCoor = 8.5;
    ruff.yCoor = 4.2;
    double space = distance(meow, ruff);
    cout << "Distance between them is" << space;
    return 0;
} 

double distance(Point a, Point b) {
    double aDis = sqrt(pow((a.xCoor - b.xCoor), 2) + pow((a.yCoor - b.yCoor), 2));
    return aDis;
}