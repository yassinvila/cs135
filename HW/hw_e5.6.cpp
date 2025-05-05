/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E4.8 CPP

Describe: E5.6 returns a string containing 
the middle character in str if the length of str 
is odd, or the two middle characters if the length is even. 
For example, middle("middle") returns "dd
///
////
/////
*/

#include <iostream>
#include <string>
using namespace std;

string middle(string str) {
    int len = str.length();
    int mid = len / 2;

    if (len % 2 == 0) { 
        return str.substr(mid - 1, 2);
    } else { 
        return str.substr(mid, 1);
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    cout << "Middle character(s): " << middle(input) << endl;
    return 0;
}