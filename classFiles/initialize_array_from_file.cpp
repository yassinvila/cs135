//File name: /Users/laptopuser/Documents/courses_macbook_pro/cs135/s25/class_days/day7_2025_2_13_file_reading/code/initialize_array_from_file.cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//read the contents of a file named mydata.txt,
//save the data into an array
//Then print out the elements in the array.
//Note: if we just want to get statistic data
//like max, min, average, sum,
//we do not need to use an array to save the data.
//However, if we want to save the indivial records,
//then we need to use an array.
//For example, in Lab 3 D,
//if we need to save the data in a given period of time,
//then print them backwards,
//we need to save those data in an array.

//The format of mydata.txt is as follows.
//9
//8
//7
//8
//3
int main() {
    ifstream fin("mydata.txt");

    if (fin.fail()) {
       cerr << "file cannot be opened" << endl;
       exit(1);
    }

    const int CAPACITY = 10;
    int arr[CAPACITY];

    int count = 0;
    int num;
    //as long as the array is not full and there are valid int from file -- fin >> num return true
    while (count < CAPACITY  && fin >> num) {
        arr[count] = num;
        count++;
    }

    //print elements in arr from the last element to the first element 
    for (int i = count-1; i >= 0; i--)
        cout << arr[i] << endl;

    fin.close();

    return 0;
}
