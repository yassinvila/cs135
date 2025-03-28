/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab1B

Describe: Find the smaller of three integers. This is the second part.
Idk how much more you want me to write.
Like actually how many lines.
*/

#include <iostream>
using namespace std;
int main (){
    cout << "Enter integer one" << endl;
    int num1;
    cin >> num1;
    cout << "Enter integar two" << endl;
    int num2;
    cin >> num2;
    cout << "Enter integar three" << endl;
    int num3;
    cin >> num3;
    if (num1 > num2) 
    {
        if(num2>num3)
            cout << "The smaller of the three is\n" << num3 << endl;
        else cout << "The smaller of the three is\n" << num2 << endl;
    }
    else if (num2 > num1) 
    {
        if (num1>num3)
            cout << "The smaller of the three is\n" << num3 << endl;
        else cout << "The smaller of the three is\n" << num1 << endl;
    }
    return 0; 

    }
