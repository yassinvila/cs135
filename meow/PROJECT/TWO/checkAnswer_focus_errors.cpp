/* 
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: PROJECT 2C

In this project, we display questions and answer them. If the answer is correct, 
we display true,otherwise, we display false. This project can serve as a study 
guide for our courses or Civics (History and Government) Questions for the 
Naturalization Test, as in https://www.uscis.gov/sites/default/files/document/questions-and-answers/100q.pdf.
*/
    

#include <iostream>
#include <string>
#include <fstream>
#include <climits>
#include <cstdlib>
using namespace std;

struct Question {
    string text;
    string answer;
    string explanation;
    string version;
    string label;
    string type;
};

string trim(string str);
int count_occurrences(string str, char ch);
string* extract_type(string type, int& num_types_curr_item);
void insert_order_unique(string types[], int type_capacity, int& type_count, string toAdd);
void insert_order_unique(string types[], int type_capacity, int& type_count, Question ques[], int ques_size);
string choose_type(string* types, int type_count);
void randomize(Question ques[], int size);
void feedback(int numCorrect, int numQuestions);
void answer_by_type(Question ques[], int size, string chosenType);
void read_file(string fileName, Question ques[], int capacity, int& size);
void display(Question ques[], int size);
bool type_related(string type_to_focus, string curr_type);
void reorder(Question ques[], int size, int idx);

bool type_related(string type_to_focus, string curr_type) {
    int n;
    string* focus_types = extract_type(type_to_focus, n);
    for (int i = 0; i < n; i++) {
        if (curr_type.find(focus_types[i]) != string::npos) {
            delete[] focus_types;
            return true;
        }
    }
    delete[] focus_types;
    return false;
}

void reorder(Question ques[], int size, int idx) {
    string type_to_focus = ques[idx].type;
    for (int i = idx + 1; i < size - 1; i++) {
        for (int j = size - 1; j > i; j--) {
            if (type_related(type_to_focus, ques[j].type) &&
                !type_related(type_to_focus, ques[i].type)) {
                Question temp = ques[i];
                ques[i] = ques[j];
                ques[j] = temp;
                break;
            }
        }
    }
}

#ifndef UNIT_TEST
int main() {
    const int CAPACITY = 1000;
    Question ques[CAPACITY];
    int size = 0;

    read_file("cs135_midterm_f24_v1.txt", ques, CAPACITY, size);
    read_file("cs135_midterm_f24_v2.txt", ques, CAPACITY, size);
    read_file("cs135_midterm_s24_v1.txt", ques, CAPACITY, size);

    const int TYPE_CAPACITY = 30;
    string types[TYPE_CAPACITY];
    int typeCount = 0;
    insert_order_unique(types, TYPE_CAPACITY, typeCount, ques, size);

    string chosenType = choose_type(types, typeCount);
    answer_by_type(ques, size, chosenType);

    return 0;
}
#endif

string trim(string str) {
    int firstChar = str.find_first_not_of(' ');
    int lastChar = str.find_last_not_of(' ');
    if (firstChar == string::npos || lastChar == string::npos) {
        return "";
    }
    return str.substr(firstChar, lastChar - firstChar + 1);
}

int count_occurrences(string str, char ch) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ch) count++;
    }
    return count;
}

string* extract_type(string type, int& num_types_curr_item) {
    num_types_curr_item = count_occurrences(type, ';') + 1;
    string* TYPE = new string[num_types_curr_item];
    int pos = 0;
    for (int i = 0; i < num_types_curr_item; i++) {
        int nextPos = type.find(';', pos);
        string piece = (nextPos == string::npos) ? type.substr(pos) : type.substr(pos, nextPos - pos);
        TYPE[i] = trim(piece);
        pos = nextPos + 1;
    }
    return TYPE;
}

void insert_order_unique(string types[], int type_capacity, int& type_count, string toAdd) {
    if (type_count >= type_capacity) return;
    int i = 0;
    while (i < type_count && types[i] < toAdd) i++;
    if (i < type_count && types[i] == toAdd) return;
    for (int j = type_count; j > i; j--) {
        types[j] = types[j - 1];
    }
    types[i] = toAdd;
    type_count++;
}

void insert_order_unique(string types[], int type_capacity, int& type_count, Question ques[], int ques_size) {
    for (int i = 0; i < ques_size; i++) {
        int num_types = 0;
        string* extracted = extract_type(ques[i].type, num_types);
        for (int j = 0; j < num_types; j++) {
            insert_order_unique(types, type_capacity, type_count, extracted[j]);
        }
        delete[] extracted;
    }
}

string choose_type(string* types, int type_count) {
    cout << "0. ALL TYPES" << endl;
    for (int i = 0; i < type_count; i++) {
        cout << i + 1 << ". " << types[i] << endl;
    }
    int choice;
    while (true) {
        cout << "Enter a type: ";
        cin >> choice;
        if (choice >= 0 && choice <= type_count) break;
        cout << "Invalid choice. Try again.\n";
    }
    cin.ignore(INT_MAX, '\n');
    return (choice == 0) ? "" : types[choice - 1];
}

void randomize(Question ques[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Question temp = ques[i];
        ques[i] = ques[j];
        ques[j] = temp;
    }
}

void feedback(int numCorrect, int numQuestions) {
    cout << "number of correct problems: " << numCorrect << endl;
    double percent = (double)numCorrect / numQuestions * 100;
    cout << "percentage of correct: " << percent << "%" << endl;
    if (percent >= 90) cout << "excellent" << endl;
    else if (percent >= 80) cout << "good" << endl;
    else if (percent >= 70) cout << "pass" << endl;
    else cout << "please ask help ASAP" << endl;
}

void answer_by_type(Question ques[], int size, string chosenType) {
    randomize(ques, size);
    int correct = 0;
    for (int i = 0; i < size; i++) {
        if (chosenType != "" && ques[i].type.find(chosenType) == string::npos) continue;
        cout << "question " << ques[i].version << " " << ques[i].label << ": " << ques[i].text << endl;
        int tries = 0;
        string userAns;
        bool correctAns = false;
        while (tries < 3) {
            cout << "Enter your answer: ";
            getline(cin, userAns);
            tries++;
            if (trim(userAns) == trim(ques[i].answer)) {
                cout << "true\n";
                correct++;
                correctAns = true;
                break;
            } else {
                cout << "false\n";
            }
        }
        if (!correctAns && !ques[i].explanation.empty()) {
            cout << ques[i].explanation << endl;
        }
        cout << endl;
    }
    feedback(correct, size);
}

void read_file(string fileName, Question ques[], int capacity, int& size) {
    ifstream infile(fileName);
    if (infile.fail()) {
        cerr << "File not found" << endl;
        exit(1);
    }

    string line;
    while (getline(infile, line)) {
        if (line.empty() || line.find("question: ") != 0)
            continue;

        ques[size].text = line.substr(10);
        while (getline(infile, line) && line.find("answer: ") != 0) {
            if (!line.empty())
                ques[size].text += "\n" + line;
        }

        if (line.find("answer: ") == 0) {
            ques[size].answer = line.substr(8);
            while (getline(infile, line) && line.find("explanation: ") != 0 && line.find("version: ") != 0) {
                if (!line.empty())
                    ques[size].answer += "\n" + line;
            }
        }

        if (line.find("explanation: ") == 0) {
            ques[size].explanation = line.substr(13);
            while (getline(infile, line) && line.find("version: ") != 0) {
                if (!line.empty())
                    ques[size].explanation += "\n" + line;
            }
        }

        if (line.find("version: ") == 0) {
            ques[size].version = line.substr(9);
            while (getline(infile, line) && line.find("label: ") != 0) {
                if (!line.empty())
                    ques[size].version += "\n" + line;
            }
        }

        if (line.find("label: ") == 0) {
            ques[size].label = line.substr(7);
            while (getline(infile, line) && line.find("type: ") != 0) {
                if (!line.empty())
                    ques[size].label += "\n" + line;
            }
        }

        if (line.find("type: ") == 0) {
            ques[size].type = line.substr(6);
            while (getline(infile, line) && !line.empty() && line.find("question: ") != 0) {
                ques[size].type += "\n" + line;
            }
        }

        size++;
    }
}
