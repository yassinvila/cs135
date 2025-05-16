    /*
    Author: Yassin Vila
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: HW Lab 12A

    Description: program a function called vector<int> 
    makeVector(int n) that returns a vector of n integers 
    that range from 0 to n-1.
    */

    #include <vector>
    #include <iostream>
    using namespace std;

    vector<int> makeVector(int n);
    int main () {
        int input;
        cout << "Enter amoount of integers: ";
        cin >> input;
        vector<int> meow = makeVector(input);
    }

    vector<int> makeVector(int n) {
        vector<int> meow;
        for (int i = 0; i < n; i++) {
            meow.push_back(i);
        }
        return meow;
    }