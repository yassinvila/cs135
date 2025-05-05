#include <iostream>
using namespace std;
int main (){
    cout << "Enter a int" << endl;
    int num;
    cin >> num; 
    if (num % 2 == 0) 
    {
        if (num % 5 == 0)
            cout << "Divisible by 2 and 5." << endl;
        else cout << "Divisble by only 2." << endl;
    }    
    else if (num % 5 == 0)
    {
        if (num % 2 == 0)
            cout << "Divisible by 2 and 5." << endl;
        else cout << "Divisible by only 5.";
    }
    else cout << "Divisible by neither" << endl;
    return 0;

}