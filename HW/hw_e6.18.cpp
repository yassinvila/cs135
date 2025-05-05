/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E6.18 CPP

Describe: Write a function
vector<int> append(vector<int> a, vector<int> b)
that appends one vector after another. For example, if a is
1 4 9 16 and b is 9 7 4 9 11 then append returns the vector
1 4 9 16 9 7 4 9 11
*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> append(vector<int> a, vector<int> b);
int main () {
    vector<int> a{1, 2, 3, 4};
    vector<int> b{1, 2, 3, 4};
    append(a, b);
    return 0;
}
vector<int> append(vector<int> a, vector<int> b) {
    vector<int> append = a;
    for (int i = 0; i < b.size(); i++) {
        append.push_back(b.at(i));
    }
    return append;
}