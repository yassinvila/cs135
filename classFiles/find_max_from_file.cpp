//File name: /Users/laptopuser/Documents/courses_macbook_pro/cs135/s25/class_days/day7_2025_2_13_file_reading/code/find_max_from_file.cpp
#include <iostream>
#include <fstream> //ifstream,
#include <climits> //INT_MAX, INT_MIN
#include <string>
using namespace std;

//find out the maximum element from a file named mydata.txt
//contents of mydata.txt is as follows.
//9
//8
//7
//8
//3

//Since we only care about the maximum,
//we read the current data,
//compare with the current maximum,
//if the current data is larger than the current maximum,//update the current maximum.
int main() {
    ifstream fin("mydata.txt");

    if (fin.fail()) {
       cerr << "the file cannot be opened" << endl;
       exit(1);
    }

    int num;
    int currMax = INT_MIN;
    while (fin >> num) {
        if (num > currMax)
           currMax = num;
    }

    fin.close(); 

    cout << "maximum = " << currMax << endl;
    return 0;
}
