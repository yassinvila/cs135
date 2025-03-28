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

string encryptVigenere(string plaintext, string keyword) {
    string encrypt = "";
    int stand = keyword.length();
    int count = 0;
    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];
        int shift = (keyword[count] - 'a');
        int newone;

        if (c >= 'a' && c <= 'z') {
            newone = int(c) + shift;
            if (newone > 122) {
                newone = (newone - 122) + 96;
            }
            count++;
        }
        else if (c >= 'A' && c <= 'Z') {
            newone = int(c) + shift;
            if (newone > 90) {
                newone = (newone - 90) + 64;
            }
            count++;
        } else newone = c;
        encrypt += char(newone);
        
        if (count == stand){
            count = 0;
        }
    }

    return encrypt; 
}

int main () {
    string plaintext;
    cout << "Enter plaintext: "; 
    getline(cin, plaintext);
       
    string keyword;
    cout << "Enter keyword: "; 
    cin >> keyword;
    
    cout << "Ciphertext: " << encryptVigenere(plaintext, keyword);
    
}