/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW Project 1A

Describe: In this project, we display questions and answer them. If the answer is correct, we display true,
otherwise, we display false.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "What is -1 + 5 / 3 ?" << endl;
    string answer1; getline(cin, answer1);      /* another version of cin */
    
    if (answer1 == "0")
        cout << "true" << endl;
    else cout << "false" << endl; 

    cout << "Assume that n is properly declared and initialized. Write a condition to represent that n does NOT satisify 0 < n < 100." << endl;
    string answer2; getline(cin, answer2);
    
    if (answer2 == "(n <= 0 || n >= 100)")
        cout << "true" << endl;
    else cout << "false" << endl;
    
}