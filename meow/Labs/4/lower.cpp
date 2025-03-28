/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW LAB 4D

Write a program lower.cpp that prints the 
bottom-left half of a square, given the side length.
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
   int row = 1;

   for (int i = 0; i < size; i++) {
        for (int x = 0; x < row; x++) {
            cout << "*";
        }
        row++;
        cout << endl;
    }

            

} 




