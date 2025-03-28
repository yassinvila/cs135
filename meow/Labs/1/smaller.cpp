/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab1A

Describe: Find the smaller of two integers.
*/

#include <iostream>
using namespace std;
int main (){
    cout << "Enter integer one" << endl;
    int num1;
    cin >> num1;
    cout << "Enter integar two" << endl;
    int num2;
    cin >> num2;
    if (num1 > num2)
        cout << "The smaller of the two is\n" << num2 << endl;
    else cout << "The smaller of the two is\n" << num1 << endl;
    return 0; 
    }
