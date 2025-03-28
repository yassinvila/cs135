/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 6D

Describe: Write a program test-ascii.cpp that asks the user 
to input a line of text (which may possibly include spaces).
The program should report all characters from the input
line together with their ASCII codes.
Make sure to print exactly one space between the character 
and it’s code.
meow
meow
meow
meow
meow
meow
meow
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

string decryptCaesar(string ciphertext, int rshift) {
    string decrypt = "";
    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        int asc = int(c);
        if (c >= 'a' && c <= 'z') {
            c = c - rshift;
            if (c < 97) {
                c = 122 - (96 - c);
            }
        } else if (c >= 'A' && c <= 'Z') {
            c = c - rshift;
            if (c < 65) {
                c = 90 - (64 - c);
            }
        } else c = c;
        decrypt += char(c);
    }
    return decrypt;
}

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

string decryptVigenere(string ciphertext, string keyword) {
    string decrypt = "";
    int count = 0;
    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        if (c >= 'a' && c <= 'z') {
            c = c - (keyword[count] - 'a');
            if (c < 97) {
                c = 122 - (96 - c);
            }
            count++;
            
        } else if (c >= 'A' && c <= 'Z') {
            c = c - (keyword[count] - 'a');
            if (c < 65) {
                c = 90 - (64 - c);
            }
            count++;
        } else c = c;
        decrypt += char(c);
        
        if (count == keyword.length()) {
            count = 0;
        }
    }
    
    return decrypt;

}


int main () {
    cout << "\n\n";

    string plaintext;
    cout << "Enter plaintext: "; 
    getline(cin, plaintext);
    cout << endl;
    
    cout << "= Caesar =" << "\n";
       
    int rshift = 0;
    cout << "Enter shift: "; 
    cin >> rshift;
    cout << "\n";
    
    string ciphertextC = encryptCaesar(plaintext, rshift);
    cout << "Ciphertext: " << ciphertextC << "\n";
    cout << "Decrypted: " << decryptCaesar(ciphertextC, rshift) << "\n";
    
    cout << "= Vigenere =" << "\n";
    
    string keyword;
    cout << "Enter keyword: "; 
    cin >> keyword;
    cout << "\n";

    string ciphertextV = encryptVigenere(plaintext, keyword);
    cout << "Ciphertext: " << ciphertextV << "\n";
    cout << "Decrypted: " << decryptVigenere(ciphertextV, keyword) << "\n";
    
    
    
}