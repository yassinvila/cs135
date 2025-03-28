/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW LAB 4A

Describe: Write a program box.cpp that asks the user to
input width and height and prints a solid rectangular box of the requested
size using asterisks.
*/


#include <iostream>
#include <string>
using namespace std;
int main () {
    cout << "Input width: ";
    int width; 
    cin >> width;
    
    
    cout << "Input height: ";
    int height;
    cin >> height;
    cout << "\n";

    cout << "Shape:" << "\n"; 
    for (int i = 0; i < height; i++) {
        for (int x = 0; x < width; x++) {
            cout << "*";
        }
        cout << endl;
    } 




}