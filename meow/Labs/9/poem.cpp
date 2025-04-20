/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW Project 9A-C

Describe: idk bro some shi about a broken poem

*/

#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
    
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();
        delete p;
        // assume that the poem p is not needed at this point

    }
}