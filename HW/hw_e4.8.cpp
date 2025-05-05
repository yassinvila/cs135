/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E4.8 CPP

Describe: E4.8 - 1 character per line
///
////
/////
*/

#include <iostream>
#include <string>
using namespace std;

int main () {
    string input;
    cout << "Provide an input: ";
    getline(cin, input);


    for (int i = 0; i < input.length(); i++) {
        cout << input.substr(i, 1) << endl;
    }

}