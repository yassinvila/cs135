/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW Lab 7B

Describe: Removing indentation
/meow
/meow
/meow
/meow
/meow
/meow
meow meow
*/

#include <iostream>
#include <cctype>

using namespace std;

//count char
int countChar(string line, char c) {
    int count = 0;
    string newline;
    for(int i = 0; i < line.length(); i++) {
        if(line[i] == c) {
        count++;
        }
    }
    return count;
}

//remove leading spaces
    string removeLeadingSpaces(string line) {
    string newline = "";
    bool leading = true;
    for(int i = 0; i < line.length(); i++) {
        if(!isspace(line[i])) {
            leading = false;
        }
    if(leading == false) {
        newline += line[i];
        }
    }
    return newline;
}

//main
int main() {
    string line = "";
    int indent = 0;
    while(getline(cin, line)) {
        string newstring = removeLeadingSpaces(line);

        if (newstring.empty()) {
                cout << endl;
            continue;
        }

        if (newstring[0] == '}') {
            indent--;
        }

        for (int i = 0; i < indent; i++) {
            cout << '\t';
        }

        cout << newstring << endl;

        indent += countChar(newstring, '{');
        indent -= countChar(newstring, '}');

        if (newstring[0] == '}') {
            indent++;
        }
    }
}
