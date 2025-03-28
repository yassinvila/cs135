/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW Project 1B

Describe: In this project, we display questions and answer them. If the answer is correct, we display true,
otherwise, we display false.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Question {
    string text;
    string answer;
    string explanation;
    string version;
    string label;
    string type;
};

int main () {
    Question questions[200];
    int index = 0;

    cout << "Input File Name: ";
    string fileName; 
    getline(cin, fileName); 
    cout << endl;
    
    ifstream file(fileName);
    if (file.fail()) {
        cerr << "File not found" << endl;
        exit(1);
    }
    
    string junk;
    if (fileName == "civics_65_20.txt") {
        for (int i = 0; i < 7; i++) {
            getline(file, junk);
        }
    }

    string line;
    
    while (getline(file, line)) {

        if (line.empty()) continue; 

        Question q; 

        if (line.find("question: ") == 0) {
            q.text = line.substr(10);
            while (getline(file, line) && !line.empty() && 
                   line.find("answer: ") != 0) {
                q.text += "\n" + line;
            }
        }

        // Read the answer
        if (line.find("answer: ") == 0) {
            q.answer = line.substr(8);
            while (getline(file, line) && !line.empty() &&
                   line.find("explanation: ") != 0 &&
                   line.find("version: ") != 0 &&
                   line.find("label: ") != 0 &&
                   line.find("type: ") != 0) {
                q.answer += "\n" + line;
            }
        }

        // Read the explanation
        if (line.find("explanation: ") == 0) {
            q.explanation = line.substr(13);
            while (getline(file, line) && !line.empty() &&
                   line.find("version: ") != 0 &&
                   line.find("label: ") != 0 &&
                   line.find("type: ") != 0) {
                q.explanation += "\n" + line;
            }
        }

        // Read version
        if (line.find("version: ") == 0) {
            q.version = line.substr(9);
            while (getline(file, line) && !line.empty() && line.find("label: ") != 0) {
                q.version += "\n" + line;
            }
        }

        // Read label
        if (line.find("label: ") == 0) {
            q.label = line.substr(7);
            while (getline(file, line) && !line.empty() && line.find("type: ") != 0) {
                q.label += "\n" + line;
            }
        }

        // Read type
        if (line.find("type: ") == 0) {
            q.type = line.substr(6);
            while (getline(file, line) && !line.empty()) {
                q.type += "\n" + line;
            }
        }

        // Store only valid questions
        if (!q.text.empty() && !q.answer.empty()) {
            questions[index++] = q;
        }
    }

    string answer;
    double correct = 0;
    double totalQ = index;

    for (int i = 0; i < totalQ; i++) {
        if (questions[i].text.empty()) continue;
        
        cout << "Question " << i + 1 << ": " << questions[i].text << endl;
        int attempts = 0; // Start at 0?

        while (attempts < 3) {
            cout << "Enter your answer: "; 
            getline(cin, answer);
            attempts++;

            if (answer == questions[i].answer) {
                cout << "Number of Tries: " << attempts << endl;
                cout << "true" << "\n";
                correct++;
                break;
            } else {
                cout << "Number of Tries: " << attempts << endl;
                cout << "false" << "\n";                    
            }

            if (attempts == 3 && !questions[i].explanation.empty() ) {
                cout << "Explanation: " << questions[i].explanation << endl;
            }
        } 
        cout << endl;

    }

    double percentage = (correct / totalQ) * 100; 
    cout << "number of correct problems: " << correct << endl;
    cout << "percentage of correct: " << percentage << "%" << endl;

    if (percentage >= 90)
        cout << "excellent" << endl;
    else if (percentage >= 80)
        cout << "good" << endl;
    else if (percentage >= 60)
        cout << "pass" << endl;
    else
        cout << "please ask help ASAP" << endl;

    return 0;
}
