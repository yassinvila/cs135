/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW Project 2A

Describe: Ask the user to input an integer in the range 0 < n < 100. If
the number is out of range, the program should keep asking
to re-enter until a valid number is input.
*/

#include <iostream>
using namespace std;
int main () {
    cout << "Input an integer in the range 0 < n < 100" << endl;
    int n; cin >> n;

    while (n <= 0 || n >= 100)
    {
        cout << "Input vaild number" << endl;
        cin >> n;
    }
    
    n = n * n;
    cout << "Number squared is " << n << endl;
}
