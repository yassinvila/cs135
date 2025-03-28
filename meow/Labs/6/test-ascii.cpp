/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 6A

Describe: Write a program test-ascii.cpp that asks the user 
to input a line of text (which may possibly include spaces).
The program should report all characters from the input
line together with their ASCII codes.
Make sure to print exactly one space between the character 
and it’s code.
*/ 

#include <iostream>
#include <string>
using namespace std;

int main () {
    string input;
    cout << "Input: "; getline(cin, input);
    
    int count = input.length();
    for(int i = 0; i < count; i++) {
        char c = input[i];
        cout << c << " " << (int)c << "\n";
    }
    
}