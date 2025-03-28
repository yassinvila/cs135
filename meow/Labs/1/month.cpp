/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab1D

Describe: Number of days in a given month.
Idk how much more you want me to write.
Like actually how many lines.
*/

#include <iostream>
using namespace std;
int main () {
    cout << "Enter Year: ";
    int year;
    cin >> year;
    cout << "Enter Month: ";
    int month;
    cin >> month;
    int day = 0;
    int leap = 0;

    if (year % 4 == 0) 
    {
        if (year % 100 == 0) 
        {
            if (year % 400 == 0)
                leap = 1;
            else leap = 0;
        }
        else leap = 1;
    }
    else leap = 0;



    if (month == 2)        
        day = leap + 28;
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        day = day + 31;
    else day = day + 30;

    cout << "\n" << day << " Days" << endl;
    return 0; 
}