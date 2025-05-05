/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW HW E3.1 CPP

• E3.1Write a program that reads an integer and prints 
whether it is negative, zero, or positive.
meow
meow
meow
meow
*/

#include <iostream>
#include <string>
using namespace std;
int main () {
    int input;
    cin >> input;
    if (input == 0)
        cout << "zero";
    else if (input > 0)
        cout << "positive";
    else cout << "negative";
}
