/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E5.14 CPP

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

void sort2(int& a, int& b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    } else return;
}

int main() {
    int x, y;
    cout << "Int x = ";
    cin >> x; cout << endl;
    
    cout << "Int y = ";
    cin >> y; cout << endl;
    sort2(x, y);
    cout << "Int x = " << x << endl;
    cout << "Int y = " << y << endl;
    
    return 0;
}