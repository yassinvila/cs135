//File name: /Users/laptopuser/Documents/courses_macbook_pro/cs135/s25/class_days/day7_2025_2_13_file_reading/code/get_test1_average_from_file.cpp
#include <iostream>
#include <fstream>
#include <climits>
#include <string>
using namespace std;

//Read a file scores_cs135_s25.txt in the following format.
//Name Test1 Test2 Test3 Test4
//Ann 100 87 82 60
//Bob 85 22 98 35
//Charles 3 99 45 56
//Deb 95 10 21 55
int main() {
    ifstream fin("scores_135_s25.txt");

    if (fin.fail()) {
       cerr << "file cannot be opened" << endl;
       exit(1);
    }

    string headers;
    getline(fin, headers);

    string name;
    int test1;
    //int test2;
    //int test3;
    //int test4;

    //fin >> name;
    //fin >> test1;

    //fin.ignore(INT_MAX, '\n');

    int sum = 0; //sum of test1 scores for all students
    int numStudents = 0; //num of students in this file
    //while (fin >> name && fin >> test1) {
    while (fin >> name >> test1) {
        fin.ignore(INT_MAX, '\n');
        //cout << test1 << endl;
        sum += test1; //sum += test1;
        numStudents++;
    }

    double average = 1.0 * sum / numStudents;

    cout << "average = " << average << endl;
    fin.close();

    return 0;
}
