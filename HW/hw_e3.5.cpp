/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW HW E3.1 CPP

• Write a program that reads three numbers and prints 
“increasing” if they are in increasing order, 
“decreasing” if they are in decreasing order, 
and “neither” otherwise. Here, “increasing” means 
“strictly increasing”, with each value larger than 
its predecessor. The sequence 3 4 4 would not be 
considered increasing.
*/

#include <iostream>
#include <string>
using namespace std;
int main () {
    int input1; int input2; int input3;
    cout << "Input number #1: " ; cin >> input1;
    cout << "Input number #2: " ; cin >> input2;
    cout << "Input number #3: " ; cin >> input3;

    if ( input1 == input2 || input2 == input3 || input1 == input3)
        cout << "Neither";
    else if (input1 > input2 && input2 > input3)
        cout << "Decreasing";
    else if (input3 > input2 && input2 > input1)
        cout << "Increasing";
    else cout << "Neither";
}