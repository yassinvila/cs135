/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW Project 2A

Describe: In this project, we display questions and answer them. If the answer 
is correct, we display true, otherwise, we display false.
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

void read_file(string fileName, Question ques[], int capacity, int& size);
void display(Question ques[], int size);

int main () {
    const int CAPACITY = 1000;
    Question ques[CAPACITY];
    int size = 0;
    
    string fileName1 = "cs135_midterm_f24_v1.txt";
    read_file(fileName1, ques, CAPACITY, size);
    cout << size;
   
    string fileName2 = "cs135_midterm_f24_v2.txt";
    read_file(fileName2, ques, CAPACITY, size);
    cout << size;

    string fileName3 = "cs135_midterm_s24_v1.txt";
    read_file(fileName3, ques, CAPACITY, size);
    cout << size;

    display(ques, size);

    return 0;
}

void read_file(string fileName, Question ques[], int capacity, int& size) {
    ifstream infile(fileName);
    if (infile.fail()) {
        cerr << "File not found" << endl;
        exit(1);
    }
    string line;
    
    while (getline(infile, line)) {
        
        if(line.find("question: ") != 0) {
            continue;
        } else if (line.find("question: ") == 0) {
            ques[size].text = line.substr(10);
            
            while(getline(infile, line) && line.find("answer: ") != 0) {
                ques[size].text += "\n" + line;
            }
        }
        
        if(line.find("answer: ") == 0) {
            ques[size].answer = line.substr(8);

            while(getline(infile, line) && line.find("explanation: ") != 0) {
                ques[size].answer += "\n" + line;
            }
        }
        
        if(line.find("explanation: ") == 0) {
            ques[size].explanation = line.substr(13);

            while(getline(infile, line) && line.find("version: ") != 0) {
                ques[size].explanation += "\n" + line;
            }
        }
        
        if(line.find("version: ") == 0) {
            ques[size].version = line.substr(9);

            while(getline(infile, line) && line.find("label: ") != 0) {
                ques[size].version += "\n" + line;
            }
        }
        
        if(line.find("label: ") == 0) {
            ques[size].label = line.substr(8);
            
            while(getline(infile, line) && line.find("type: ") != 0) {
                ques[size].label += "\n" + line;
            }
        }
        
        if(line.find("type: ") == 0) {
            ques[size].type = line.substr(6);

            while(getline(infile, line) && !line.empty() && line.find("question: ") != 0) {
                ques[size].type += "\n" + line;
            }
        }
        size++;
    }
}


void display(Question ques[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << endl; //start labeling from 1
        
        cout << "question: " << ques[i].text << endl;

        cout << "answer: " << ques[i].answer << endl;
                
        cout << "explanation: " << ques[i].explanation << endl;
        cout << "type: " << ques[i].type << endl;
        cout << "version: " << ques[i].version << endl;
        cout << "label: " << ques[i].label << endl;
        cout << endl;
    }
}
