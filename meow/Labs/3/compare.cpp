/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW LAB 3C

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
    cout << "Enter starting date: "; 
    string startDate; cin >> startDate; 

    cout << "Enter ending date: ";
    string endDate; cin >> endDate;

    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File can't be opened." << endl;
        exit(1); 
    }

    string junk;
    getline(fin, junk);

    string date;
    double eastSt, eastEl, westSt, westEl;
    bool range = false;

    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
        fin.ignore(INT_MAX, '\n');
        if (date == startDate) {
            range = true;
        }

        if (range) {
            cout << date;
            if (eastEl > westEl)
                cout << " East" << endl;
            else cout << " West" << endl;
            if (date == endDate) {
                break;
            }
        }            
        }
}