/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW LAB 3B

Describe: Write a program edit-array.cpp that creates 
an array of 10 integers, and provides the user with an 
interface to edit any of its elements.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
using namespace std;

int main () {
    ifstream file("Current_Reservoir_Levels.tsv");
    if (file.fail()) {
        cerr << "File cannot be opened." << endl;
        exit(1);
    }

    string junk;
    getline(file, junk);

    string date;
    double eastSt, eastEl, westSt, westEl;
    double maxEast = 0;
    double minEast = 1000;

    while(file >> date >> eastSt >> eastEl >> westSt >> westEl) {
        file.ignore(INT_MAX, '\n');
        if (eastSt > maxEast) {
            maxEast = eastSt;
        }
        if (eastSt < minEast) {
            minEast = eastSt;
        }
    }

    cout << "Minimum storage in East basin: " << minEast << " billion gallons." << endl;
    cout << "MAXimum storage in East basin: " << maxEast << " billion gallons." << endl;
} 
