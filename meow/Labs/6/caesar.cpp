/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 6B

Describe: Write a program test-ascii.cpp that asks the user 
to input a line of text (which may possibly include spaces).
The program should report all characters from the input
line together with their ASCII codes.
Make sure to print exactly one space between the character 
and it’s code.
*/ 

#include <iostream>
#include <string>
using namespace std;

char shiftChar(char c, int rshift) {
    int newOne = int(c);
    if (isupper(c)) {
        newOne += rshift;
        if (newOne > 90) {
            newOne = (newOne - 90) + 64;
        }
    } else if (islower(c)) {
        newOne += rshift;
        if (newOne > 122) {
            newOne = (newOne - 122) + 96;
        }
    }
    char meow = char(newOne);
    return meow;
}

string encryptCaesar(string plaintext, int rshift) {
    int count = plaintext.length();
    string encrypt = "";
    
    for (int i = 0; i < count; i++) {
        char newChar = shiftChar(plaintext[i], rshift);
        encrypt += newChar;
    }

    return encrypt; 
}

int main () {
    string plaintext;
    cout << "Enter plaintext: "; 
    getline(cin, plaintext);
       
    int shift = 0;
    cout << "Enter shift: "; 
    cin >> shift;
    
    cout << "Ciphertext: " << encryptCaesar(plaintext, shift);
    
}