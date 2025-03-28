/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW Lab 7A

Describe: Removing indentation
/meow
/meow
/meow
/meow
/meow
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;


string removeLeadingSpaces(string line);

int main() {
    string line;
    string newCode;
    while(getline(cin, line)) {
        newCode += removeLeadingSpaces(line) + "/n";
    }
    cout << newCode;
}

string removeLeadingSpaces(string line) {
    string newLine = ""; 
    int i = 0;
    while (isspace(line[i])) {
        i++;
    }
    for (;i < line.length(); i++) {
        newLine += line[i];
    }
    return newLine;
}
