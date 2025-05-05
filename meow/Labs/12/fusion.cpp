/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW Lab 12C

Description: a program called fusion.cpp that implements 
the function void gogeta(vector<int> &goku, vector<int> 
&vegeta) that appends elements of the second vector into 
the first and empties the second vector.
*/

#include <vector>
#include <iostream>
using namespace std;

void gogeta(vector<int> &goku, vector<int> &vegeta);
int main () {
    vector<int> goku{1, 2, 3, 4};
    vector<int> vegeta{5, 6, 7, 8, 9};
    gogeta(goku, vegeta);
}
void gogeta(vector<int> &goku, vector<int> &vegeta){
    for (int i = 0; i < vegeta.size(); i++) {
        goku.push_back(vegeta[i]);
    }
    vegeta.clear();
}