/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab1C

Describe: Leap year calculator. 
Idk how much more you want me to write.
Like actually how many lines.
*/

#include <iostream>
using namespace std;
int main () {
    cout << "Enter an year" << endl;
    int year;
    cin >> year;

    if (year % 4 != 0)
        cout << "Common Year";
    else if (year % 100 != 0)
        cout << "Leap Year";
    else if (year % 400 != 0)
        cout << "Common Year";
    else cout << "Leap Year";
    return 0;
}