#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

struct Question {
    string text;
    string answer;
    string explanation;
    string types[5]; // Store multiple types per question
    int typeCount;
};

int main() {
    Question questions[200];
    string types[50]; // Fixed array for storing unique types
    int questionIndex = 0, typeIndex = 0;

    cout << "Enter a txt file name with at least question and answer entries: ";
    string fileName;
    getline(cin, fileName);
    
    ifstream file(fileName);
    if (file.fail()) {
        cerr << "File not found" << endl;
        exit(1);
    }
    
    if (fileName == "civics_65_20.txt") {
        for (int i = 0; i < 7; i++) file.ignore(INT_MAX, '\n');
    }
    
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines
        Question q;
        q.typeCount = 0;

        if (line.find("question: ") == 0) {
            q.text = line.substr(10);
            while (getline(file, line) && !line.empty() && line.find("answer: ") != 0) {
                q.text += "\n" + line;
            }
        }
        
        if (line.find("answer: ") == 0) {
            q.answer = line.substr(8);
            while (getline(file, line) && !line.empty()) {
                if (line.find("explanation: ") == 0) {
                    q.explanation = line.substr(13);
                    while (getline(file, line) && !line.empty() &&
                           line.find("version: ") != 0 &&
                           line.find("label: ") != 0 &&
                           line.find("type: ") != 0) {
                        q.explanation += "\n" + line;
                    }
                }
                if (line.find("type: ") == 0) {
                    string typeLine = line.substr(6);
                    size_t pos = 0;
                    while ((pos = typeLine.find(';')) != string::npos) {
                        q.types[q.typeCount++] = typeLine.substr(0, pos);
                        typeLine.erase(0, pos + 1);
                    }
                    q.types[q.typeCount++] = typeLine;
                    
                    for (int i = 0; i < q.typeCount; i++) {
                        bool exists = false;
                        for (int j = 0; j < typeIndex; j++) {
                            if (types[j] == q.types[i]) {
                                exists = true;
                                break;
                            }
                        }
                        if (!exists) {
                            types[typeIndex++] = q.types[i];
                        }
                    }
                    break;
                }
            }
        }
        questions[questionIndex++] = q;
    }
    file.close();
    
    // Sort types alphabetically using bubble sort
    for (int i = 0; i < typeIndex - 1; i++) {
        for (int j = 0; j < typeIndex - i - 1; j++) {
            if (types[j] > types[j + 1]) {
                swap(types[j], types[j + 1]);
            }
        }
    }
    
    cout << "\nAvailable Question Types:\n";
    for (int i = 0; i < typeIndex; i++) {
        cout << i + 1 << ". " << types[i] << endl;
    }
    
    cout << "\nEnter a type: ";
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice < 1 || choice > typeIndex) {
        cerr << "Invalid choice!" << endl;
        return 1;
    }
    
    string selectedType = types[choice - 1];
    cout << "\nSelected Type: " << selectedType << "\n";
    
    int correct = 0, total = 0;
    for (int i = 0; i < questionIndex; i++) {
        for (int j = 0; j < questions[i].typeCount; j++) {
            if (questions[i].types[j] == selectedType) {
                total++;
                int attempts = 0;
                string userAnswer;
                while (attempts < 3) {
                    cout << "\nQuestion " << total << ": " << questions[i].text << "\nEnter you answer: ";
                    getline(cin, userAnswer);
                    
                    if (userAnswer == questions[i].answer) {
                        cout << "number of tries: " << (attempts + 1) << "\ntrue\n";
                        correct++;
                        break;
                    } else {
                        cout << "number of tries: " << (attempts + 1) << "\nfalse\n";
                        attempts++;
                    }
                }
                if (attempts == 3) {
                    cout << "\nExplanation: " << questions[i].explanation << "\n";
                }
                break;
            }
        }
    }
    
    double percentage = total > 0 ? (double)correct / total * 100 : 0;
    cout << "\nnumber of correct problems: " << correct << "\npercentage of correct: " << percentage << "%\n";
    
    if (percentage >= 90) cout << "Excellent!" << endl;
    else if (percentage >= 80) cout << "Good!" << endl;
    else if (percentage >= 60) cout << "Pass." << endl;
    else cout << "please ask help ASAP" << endl;
    
    return 0;
}
