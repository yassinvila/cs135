/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW Lab 12B

Description: A program called optimism.cpp that implements 
the function vector<int> goodVibes(const vector<int>& v);
 that, given a vector of integers, returns a vector with 
 only the positive integers in the same order.
*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> goodVibes(const vector<int>& v);
int main () {
    vector<int> total{-10, 5, -15, 4, -12, 13, 3, 2, -1, 1};
    vector<int> postive = goodVibes(total);
}
vector<int> goodVibes(const vector<int>& v) {
    vector<int> positive;
    int size = v.size();
    for (int i = 0; i < size; i++) {
        if (v.at(i) > 0)
            positive.push_back(v.at(i));
        else 
            continue;
    }
    return positive ;
}