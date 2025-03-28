/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW LAB 3D

Describe: Write a program edit-array.cpp that creates 
an array of 10 integers, and provides the user with an 
interface to edit any of its elements.
meow
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
using namespace std;

int main () {
    cout << "Enter earlier date: ";
    string earlyDate; cin >> earlyDate;
    cout << "Enter later date: ";
    string lateDate; cin >> lateDate;

    ifstream file("Current_Reservoir_Levels.tsv");
    if (file.fail()) {
        cerr << "File not found" << endl;
        exit(1);
    }

    string junk;
    getline(file, junk);

    string date;
    double eastSt, eastEl, westSt, westEl; 
    string dateArray[500];
    double westArray[500];
    int size = 0;
    bool range = false; 

    while (file >> date >> eastSt >> eastEl >> westSt >> westEl)
    {
        file.ignore(INT_MAX, '\n');
        
        if (date == earlyDate) {
            range = true;
        }

        if (range)
        {
            dateArray[size] = date;
            westArray[size] = westEl;
            size++;
            
        }
        if (date == lateDate) {
            break;
        }
    }
    
    while (size > -1)
    {
        cout << dateArray[size] << " "<< westArray[size] << endl;
        size--;
    }
    
}