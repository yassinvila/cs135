/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E7.1 CPP

Describe: Write a function void sort2(double* p, double* q)
that receives two pointers and sorts the values to which 
they point. If you call sort2(&x, &y) then x <= y after the call.

*/
#include <iostream>
#include <string>
using namespace std;

void sort2(double* p, double* q);
int main () {
    double x = 9.2;
    double y = 3.2;
    
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
    
    sort2(&x, &y);
    
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
    return 0;
}

void sort2(double* p, double* q) {
    if(*p > *q) {
        double temp = *p;
        *p = *q;
        *q = temp;
    }
    
}