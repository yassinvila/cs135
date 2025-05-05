/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 11B

Description: profile stuff
meow
meow
meow
meow
meow
meow
*/

#include <iostream>
#include <string>
using namespace std;

class Profile {
private:
    string username;
    string displayname;

public:
    Profile(string usrn, string dspn) {
        username    = usrn;
        displayname = dspn;
    }
    Profile() {
        username    = "";
        displayname = "";
    }

    string getUsername() {
        return username;
    }
    string getFullName() {
        return displayname + " (@" + username + ")";
    }
    void setDisplayName(string dspn) {
        displayname = dspn;
    }
};


class Network {
private:
    static const int MAX_USERS = 20;   
    int numUsers;                       
    Profile profiles[MAX_USERS];        

    
    int findID(string usrn) {
        for (int i = 0; i < numUsers; i++) {
            if (profiles[i].getUsername() == usrn) {
                return i;
            }
        }
        return -1;  // didn’t find it
    }

public:
    
    Network() {
        numUsers = 0;
    }

    bool addUser(string usrn, string dspn) {
        
        if (usrn == "") {
            return false;
        }
        
        for (int i = 0; i < (int)usrn.size(); i++) {
            char c = usrn[i];
            bool isDigit = (c >= '0' && c <= '9');
            bool isLower = (c >= 'a' && c <= 'z');
            bool isUpper = (c >= 'A' && c <= 'Z');
            if (!(isDigit || isLower || isUpper)) {
                return false;
            }
        }
        
        if (findID(usrn) != -1) {
            return false;
        }
        
        if (numUsers >= MAX_USERS) {
            return false;
        }
        
        profiles[numUsers] = Profile(usrn, dspn);
        numUsers++;
        return true;
    }
};


int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     
  cout << nw.addUser("luigi", "Luigi") << endl;     

  cout << nw.addUser("mario", "Mario2") << endl;    
  cout << nw.addUser("mario 2", "Mario2") << endl;  
  cout << nw.addUser("mario-2", "Mario2") << endl;  

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   

  cout << nw.addUser("yoshi", "Yoshi") << endl;      
}