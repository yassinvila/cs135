/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW LAB 4C

Describe: Write a program cross.cpp that asks 
the user to input the shape size, 
and prints a diagonal cross of that dimension.
*/


#include <iostream>
#include <string>
using namespace std;
int main () {
    cout << "Input size: ";
    int size; 
    cin >> size;
    cout << "\n";

   cout << "Shape:" << "\n";
   int  middle = size / 2;
   int row = 0;

   for (int i = 0; i < size; i++) {
        for (int x = 0; x < size; x++) {
            if (x == i || x == size - 1 - i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

            

} 




