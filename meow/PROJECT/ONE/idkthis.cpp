#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Question {
    string text;
    string answer;
    string explanation;
};

int main () {
    Question questions[200];
    int index = 0;

    cout << "Input File Name: ";
    string fileName; getline(cin, fileName); 
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
        if (line.empty()) continue; // Skip empty lines

        Question q; // Create a new question object

        if (line.find("question: ") == 0) {
            q.text = line.substr(10);

            while (getline(file, line) && !line.empty() && line.find("answer: ") != 0) {
                q.text += "\n" + line;
        }

        if (line.find("answer: ") == 0) {
            q.answer = line.substr(8);

            // Read additional fields (explanation or stop at type)
            while (getline(file, line) && !line.empty()) {
                if (line.find("explanation: ") == 0) {
                    q.explanation = line.substr(13);

                    // Handle multi-line explanations
                    while (getline(file, line) && !line.empty() &&
                           line.find("version: ") != 0 &&
                           line.find("label: ") != 0 &&
                           line.find("type: ") != 0) {
                        q.explanation += "\n" + line;
                    }
                }

                // Stop reading if "type: " appears (no explanation present)
                if (line.find("type: ") == 0) {
                    break;
                }
            }
        }

        questions[index++] = q; // Store the question
    }

    string answer;
    double correct = 0;

    for (int i = 0; i < index; i++) {
        cout << "Question " << i + 1 << ": " << questions[i].text << endl;
        cout << "Enter you answer: "; 
        getline(cin, answer);
        
        int attempts = 0; // Start at 0?

        while (attempts < 3) {
            attempts++;

            if (answer == questions[i].answer) {
                cout << "Number of Tries: " << attempts << endl;
                cout << "True" << endl;
                correct++;
                break;
            } else {
                cout << "Number of Tries: " << attempts << endl;
                cout << "False" << endl;    
                cout << "Enter you answer: "; getline(cin, answer);     
                
                if (attempts == 3)
                    cout << "Explanation: " << questions[i].explanation << endl;
            }
        } 

    }
    
    double percentage = (correct / index) * 100;
        
        cout << "Number of correct problems: " << correct << endl;
        cout << "Percentage of correct: " << percentage << "%" << endl;

        if (percentage >= 90)
            cout << "Excellent";
        else if (percentage >=80)
            cout << "Good";
        else if (percentage >= 60)
            cout << "Pass";
        else cout << "Please ask help ASAP";




}
