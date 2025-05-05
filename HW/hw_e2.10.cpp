/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: E2.10

Describe: Write a program that asks the user to input
•The number of gallons of gas in the tank
•The fuel efficiency in miles per gallon
•The price of gas per gallon
Then print the cost per 100 miles and how far the car can go with the gas in the tank.
*/

#include <iostream>
using namespace std;
int main () {
    int gallonsOfgas;
    double mpg;
    double priceOfgas;

    cout << "The number of gallons of gas in the tank" << endl;
    cin >> gallonsOfgas;
    cout << "The fuel efficiency in miles per gallon" << endl;
    cin >> mpg;
    cout << "The price of gas per gallon" << endl;
    cin >> priceOfgas;

    double cost;
    cost = (100 / mpg) * priceOfgas;
    double far;
    far = mpg * gallonsOfgas;
    cout << "The cost of per 100 miles is " << cost << "." << endl;
    cout << "The car can go " << far << " miles with the gas in the tank" << endl;



}