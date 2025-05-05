/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E7.18 CPP

Describe: Define a structure Triangle that contains three 
Point members. Write a function that computes the perimeter
of a Triangle. Write a program that reads the coordinates 
of the points, calls your function, and displays the result.
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

struct Triangle
{
    Point aPoint;
    Point bPoint;
    Point cPoint;
};

double distance(Point a, Point b);
double perimeter(Triangle A);

int main () {
    Triangle meow;
    cout << "Enter point one: ";
    cin >>  meow.aPoint.xCoor >> meow.aPoint.yCoor;
    cout << "Enter point two: ";
    cin >> meow.bPoint.xCoor >>  meow.bPoint.yCoor;
    cout << "Enter point one: ";
    cin >> meow.cPoint.xCoor >> meow.cPoint.yCoor;
    
    
    double idk = perimeter(meow);
    cout << "Distance between them is" << idk;
    return 0;
} 

double perimeter(Triangle a) {
    double aSide = distance(a.aPoint, a.bPoint);
    double bSide = distance(a.bPoint, a.cPoint);
    double cSide = distance(a.cPoint, a.aPoint);
    double everything = aSide + bSide + cSide;
    return everything;
}

double distance(Point a, Point b) {
    double dis = sqrt(pow((a.xCoor - b.xCoor), 2) + pow((a.yCoor - b.yCoor), 2));
    return dis;
}
