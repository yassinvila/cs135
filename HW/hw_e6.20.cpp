/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E6.20 CPP

Describe: Write a function

vector<int> merge_sorted(vector<int> a, vector<int> b)
that merges two sorted vectors, producing a new sorted 
vector. Keep an index into each vector, indicating how 
much of it has been processed already. Each time, append 
the smallest unprocessed element from either vector, then 
advance the index. 
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> merge_sorted(vector<int> a, vector<int> b);
int main () {
    vector<int> a{1, 2, 3, 4};
    vector<int> b{7, 6, 4};
    merge_sorted(a, b);
    return 0;
}

vector<int> merge_sorted(vector<int> a, vector<int> b) {
    vector<int> merge;

    for (int i = 0; i < a.size(); i++) {
        merge.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        merge.push_back(b[i]);
    }

    sort(merge.begin(), merge.end());

    return merge;
}
