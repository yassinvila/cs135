/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW LAB 4E

Write a program upper.cpp that prints 
the top-right half of a square, given the side length.
*/


#include <iostream>
#include <string>
using namespace std;
int main () {
    cout << "Input side length: ";
    int size; 
    cin >> size;
    cout << "\n";

   cout << "Shape:" << "\n";

   for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) { 
            cout << " ";
        }
        for (int k = 0; k < size - i; k++) {  
            cout << "*";
        }
        cout << endl; 

    }

            

} 




