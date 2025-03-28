/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW LAB 4G

Write a program checkerboard3x3.cpp that asks the user to
input width and height and prints a checkerboard of 3-by-3 squares. (It
should work even if the input dimensions are not a multiple of three.)
meow
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
    
    int spaces = 0;
    int stars = width;

   cout << "Shape:" << "\n";

   for (int i = 0; i < height; i++) { 
    for (int j = 0; j < width; j++) { 

        if (((i / 3) + (j / 3)) % 2 == 0) {
            cout << "*";
        } else {
            cout << " ";
        }
    }
    cout << endl; 
}

            

} 




