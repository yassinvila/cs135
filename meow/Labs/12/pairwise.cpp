/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW Lab 12D

Description: A program called pairwise.cpp that implements 
the function vector<int> sumPairWise(const vector<int> &v1, 
const vector<int> &v2) that returns a vector of integers 
whose elements are the pairwise sum of the elements from 
the two vectors passed as arguments. If a vector has a 
smaller size than the other, consider extra entries from 
the shorter vectors as 0. 
*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2);
int main () {
    vector<int> goku{1, 2, 3, 4};
    vector<int> vegeta{5, 6, 7, 8, 9};
    sumPairWise(goku, vegeta);
}
vector<int> sumPairWise(vector<int> &v1, vector<int> &v2) {
    int size;
    if (v1.size() > v2.size()) {
        size = v1.size();
    } 
    else size = v2.size();
    int n = 0;
    int m = 0;
    
    vector<int> meow; 
    
    for (int i = 0; i < size; i++) {
        if (i >= v2.size()) {
            n = v1[i];
            m = 0; 
        } else if (i >= v1.size()) {
            n = 0;
            m = v2[i];
        } else {
            n = v1[i];
            m = v2[i]; 
        }
           
        meow.push_back(n + m);
    }
    return meow;
}