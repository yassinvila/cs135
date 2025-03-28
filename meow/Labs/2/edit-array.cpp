/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW Project 2C

Describe: Write a program edit-array.cpp that creates 
an array of 10 integers, and provides the user with an 
interface to edit any of its elements.
*/

#include <iostream>
using namespace std;
int main () {
    int myData[10];
    int i, v;

    for (int x = 0; x < 10; x++) {
        myData[x] = 1; 
    }

    do {
        cout << "Current Array:" << endl;
        for (int j = 0; j < 10; j++) {
            cout << myData[j] << " ";
        }

        cout << "Input index: "; cin >> i; cout << endl; 
        cout << "Input Value "; cin >> v; cout << endl;

        if (i < 0 || i >= 10) {
            cout << "Index out of range" << endl;
            break;
        }
        
        myData[i] = v;

    } while (true); 
        return 0;
    

}
