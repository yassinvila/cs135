/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW Project 2B

Describe: Write a program print-interval.cpp that asks the 
user to input two integers L and U (representing the lower 
and upper limits of the interval), and print out all 
integers in the range L ≤ i < U separated by spaces. 
Notice that we include the lower limit, but exclude the 
upper limit.
*/

#include <iostream>
using namespace std;
int main () {
    int low; int upp;
    cout << "Input lower limit" << endl; cin >> low;
    cout << "Input upper limit" << endl; cin >> upp;
    
    for(int i = low; i < upp; i++)
    cout << i << " ";
}