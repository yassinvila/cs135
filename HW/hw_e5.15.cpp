/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E5.15 CPP

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

void sort3(int& a, int&b, int&c) {
    sort2(a, b);
    sort2(b, c);
    sort2(a, b);
    
}

int main() {
    int x, y, z;
    cout << "Int x = ";
    cin >> x; cout << "\n";
    
    cout << "Int y = ";
    cin >> y; cout << "\n";
    
    cout << "Int z = ";
    cin >> z; cout << "\n";
    
    sort3(x, y, z);
    cout << "Int x = " << x << "\n";
    cout << "Int y = " << y << "\n";
    cout << "Int x = " << z << "\n";
    
    return 0;
}