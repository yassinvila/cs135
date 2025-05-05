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
        username = usrn;
        displayname = dspn;
    }
    Profile() {
        username = "";
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
    bool following[MAX_USERS][MAX_USERS];

    int findID(const string& usrn) {
        for (int i = 0; i < numUsers; i++) {
            if (profiles[i].getUsername() == usrn) {
                return i;
            }
        }
        return -1;
    }

public:
    Network() {
        numUsers = 0;
        for (int i = 0; i < MAX_USERS; i++) {
            for (int j = 0; j < MAX_USERS; j++) {
                following[i][j] = false;
            }
        }
    }

    bool addUser(string usrn, string dspn) {
        if (usrn == "") return false;
        for (int i = 0; i < (int)usrn.size(); i++) {
            char c = usrn[i];
            bool isDigit = (c >= '0' && c <= '9');
            bool isLower = (c >= 'a' && c <= 'z');
            bool isUpper = (c >= 'A' && c <= 'Z');
            if (!(isDigit || isLower || isUpper)) {
                return false;
            }
        }
        if (findID(usrn) != -1) return false;
        if (numUsers >= MAX_USERS) return false;
        profiles[numUsers] = Profile(usrn, dspn);
        numUsers++;
        return true;
    }

    bool follow(string usrn1, string usrn2) {
        int id1 = findID(usrn1);
        int id2 = findID(usrn2);
        if (id1 == -1 || id2 == -1) {
            return false;
        }
        following[id1][id2] = true;
        return true;
    }

    void printDot() {
        cout << "digraph {\n";
        for (int i = 0; i < numUsers; i++) {
            cout << "  \"@" << profiles[i].getUsername() << "\"\n";
        }
        cout << "\n";
        for (int i = 0; i < numUsers; i++) {
            for (int j = 0; j < numUsers; j++) {
                if (following[i][j]) {
                    cout << "  \"@" << profiles[i].getUsername()
                         << "\" -> \"@" << profiles[j].getUsername()
                         << "\"\n";
                }
            }
        }
        cout << "}\n";
    }
};

int main() {
    Network nw;

    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    nw.addUser("wario", "Wario");
    
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    nw.follow("mario2", "luigi");

    nw.printDot();
}