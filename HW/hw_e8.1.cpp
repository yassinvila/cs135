/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E8.1 CPP

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
#include <fstream>
#include <cstdlib> 
using namespace std;

int main() {
    ofstream file("hello.txt");

    file << "Hello, World!";
    
    file.close();
    ifstream fin("hello.txt");
    if (file.fail()) {
        cerr << "FIle can't be opened" << endl;
        exit(1);
    }
    
    string text;
    getline(fin, text);
    cout << text;
    


}