/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E1.7

Describe: Enter three names from console, then print each of them, one in a line.
*/

#include <iostream>
#include <string>
using namespace std;
int main () {
    cout << "First Name" << endl;
    string firstname;
    cin >> firstname;
    cout << "Second Name" << endl;
    string secondname;
    cin >> secondname;
    cout << "Third Name" << endl;
    string thirdname;
    cin >> thirdname;
    cout << firstname << "\n" << secondname << "\n" << thirdname << endl;
}
