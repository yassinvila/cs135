/*
    Author: Yassin Vila
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: HW Lab 13A
    
    Task: Write a program recursion.cpp, defining a 
    function void printRange(int left, int right);
    that prints all numbers in range left ≤   x   ≤ right, 
    separated by spaces. (Don’t use loops, global or 
    static variables.)
*/

#include <iostream>
using namespace std;

void printRange(int left, int right);
int sumRange(int left, int right);
int sumArrayInRange(int* arr, int left, int right);
int sumArray(int* arr, int size);
bool isAlphanumeric(string s);

int main() {
    int size = 10;
    int* arr = new int[size];

    arr[0] = 12;
    arr[1] = 17;
    arr[2] = -5;
    arr[3] = 3;
    arr[4] = 7;
    arr[5] = -15;
    arr[6] = 27;
    arr[7] = 5;
    arr[8] = 13;
    arr[9] = -21;

    int sum1 = sumArray(arr, size);    
    cout << "Sum is " << sum1 << endl; 

    int sum2 = sumArray(arr, 5);       
    cout << "Sum is " << sum2 << endl; 

    delete[] arr;
    
    int x = sumRange(1, 3);
    cout << "This is " << x << endl;   // 6

    int y = sumRange(-2, 10);
    cout << "That is " << y << endl;   // 52
    
    printRange(-2, 10);
    
    cout << isAlphanumeric("ABCD") << endl;         // 1
    cout << isAlphanumeric("Abcd1234xyz") << endl;  // 1
    cout << isAlphanumeric("KLMN 8-7-6") << endl;    // 0
    
    return 0;
}

void printRange(int left, int right) {
    if (left > right) {
        return;
    } else {
        cout << left << " ";
        printRange(left + 1, right); 
    }
}

int sumRange(int left, int right) {
    if (left > right) {
        return 0; 
    } else {
        return left + sumRange(left + 1, right); 
    }
}

int sumArray(int* arr, int size) {
    return sumArrayInRange(arr, 0, size - 1);
}

int sumArrayInRange(int* arr, int left, int right) {
    if (left > right) {
        return 0; 
    } else {
        return arr[left] + sumArrayInRange(arr, left + 1, right); // Recursive step
    }
}

bool isAlphanumeric(string s) {
    if (s == "") {
        return true; 
    } else {
        char first = s[0];
        if (isalnum(first)) {
            return isAlphanumeric(s.substr(1)); 
        } else {
            return false; 
        }
    }
}
