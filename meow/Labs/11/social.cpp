/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 11A

Description: profile stuff
meow
meow
meow
*/

#include <iostream>
using namespace std;

class Profile {
private:
    string username;
    string displayname;

public:
    Profile(string usrn, string dspn);
    Profile();
    string getUsername();
    string getFullName();
    void setDisplayName(string dspn);
};

Profile::Profile(string usrn, string dspn) {
    username    = usrn;
    displayname = dspn;
}

Profile::Profile() {
    username    = "";
    displayname = "";
}

string Profile::getUsername() {
    return username;
}

string Profile::getFullName() {
    return displayname + " (@" + username + ")";
}

void Profile::setDisplayName(string dspn) {
    displayname = dspn;
}

int main() {
    Profile p1("marco", "Marco");    
    cout << p1.getUsername() << endl;  
    cout << p1.getFullName() << endl;   
    
    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl;   
    cout << p1.getFullName() << endl;  
    
    Profile p2("tarma1", "Tarma Roving");    
    cout << p2.getUsername() << endl;   
    cout << p2.getFullName() << endl;   
}