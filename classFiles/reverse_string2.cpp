//File name: /Users/laptopuser/Documents/courses_macbook_pro/cs135/s25/class_days/day8_2025_2_18_string/code/reverse_string2.cpp
#include <iostream>
#include <string>
using namespace std;

//Enter a string from console,
//generate and print out its reversed version.
int main() {
    cout << "Enter a string: ";
    string original;
    //cin >> original; //can only take a word, not a whole sentence that might contain spaces
    getline(cin, original);

    //string reversed = "";
    string reversed("");

    //option 1: starting from smallest index to the largest index, pad the current character to the left of the current reversed string
//    for (int i = 0; i < original.length(); i++)
//        reversed = original[i] + reversed;
//        //reversed += original[i]; //? not for this application, since reversed += original[i]; is interpreted as
//        //reversed = reversed + original[i];

    for (int i = original.length() -1; i >= 0; i--)
        //reversed = reversed + original[i];
        reversed += original[i];

    cout << "reversed string: \"" << reversed << "\"" << endl;
    return 0;
}
