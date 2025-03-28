/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW LAB 4F

Write a program trapezoid.cpp that 
prints an upside-down trapezoid of given width and height.
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

    if (width < 2 * height - 1) {
        cout << "Impossible shape!" << endl;
        return 0;
    }
    
    int spaces = 0;
    int stars = width;

   cout << "Shape:" << "\n";

   for (int i = 0; i < height; i++) {
        
        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }

        for (int k = 0; k < stars; k++) {
            cout << "*";
        }

        cout << endl;
        spaces += 1;
        stars -= 2;
    }

            

} 




