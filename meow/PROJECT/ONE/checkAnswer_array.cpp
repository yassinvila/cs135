/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW Project 1B

Describe: In this project, we display questions and answer them. If the answer is correct, we display true,
otherwise, we display false.
*/

#include <iostream>
#include <string>
using namespace std;
int main () {
    string questions[] = {
        "Given char arr[] = {'A', 'B', 'C'}, what is arr[1]?",
        "Given string arr[] = {\"Hello\", \"Hi\", \"Hey\"}, what is arr[2]?",
        "Given two double variables a and b, find out the return of a^b, that is, a raised to the power of b. Hint: use pow function.",
        "Suppose n is properly declared and initialized as an integer. Write a statement to throw away the least significant digit from n. For example, if n is 12, after the statement, n changes to be 1.",
        "Assume that n is properly declared and initialized. Write a statement to declare lastDigit as an integer and initialize it to be the least significant digit of integer n. Suppose n is 123, after the statement, lastDigit is 3.",
        "What is the output?\n#include <iostream>\nusing namespace std;\n\nint main() {\n int count = 0;\n for (int i = -6; i < 2; i += 3)\n count++;\n\n cout << count << endl;\n return 0;\n}",
        "Write a condition to represent that char variable ch is none of the following: 'a', 'b', or 'c'."
    };
    string answers[] = {
        "'B'",
        "\"Hey\"",
        "pow(a, b)",
        "n /= 10;",
        "int lastDigit = n % 10;",
        "3",
        "(ch != 'a' && ch != 'b' && ch != 'c')"
    };    
    double correct = 0;

    for (int i = 0; i < 7; i++) {
        string userAnswer = "";
        cout << questions[i] << endl;
        cout << "Enter your answer: ";
        getline(cin, userAnswer);
        cout << userAnswer << endl; 
               
        if (answers[i] == userAnswer) {
            correct++;
            cout << "true" << "/n" << endl;
        }
        else cout << "false" << "/n" << endl;
    }
    
    double percentage = (correct / 7) * 100;
    cout << "Number of Correct Problems: " << correct << endl;
    cout << "Percentage of Correct: " << percentage << "%" << endl; 
    
    if (percentage >= 90)
        cout << "Excellent";
    else if (percentage >=80)
        cout << "Good";
    else if (percentage >= 60)
        cout << "Pass";
    else cout << "Please ask help ASAP";

    return 0;
}
