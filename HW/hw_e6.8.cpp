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
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size);

int main() {
    int a[] = {1, 2, 3};
    int b[] = {1, 2, 3};
    int size_a = sizeof(a) / sizeof(a[0]);
    int size_b = sizeof(b) / sizeof(b[0]);
    cout << equals(a, size_a, b, size_b);
    
    return 0;
}

bool equals(int a[], int a_size, int b[], int b_size) {
    if (a_size != b_size) {
        return false;
    }
    
    for (int i = 0; i < a_size; i++) {
            if (a[i] != b[i]) return false;
    }
    return true;
}