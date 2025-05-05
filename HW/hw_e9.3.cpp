/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E9.3 CPP

Describe: imulate a circuit for controlling a hallway light 
that has switches at both ends of the hallway. Each switch 
can be up or down, and the light can be on or off. Toggling 
either switch turns the lamp on or off. Provide member functions
///
////
/////
*/ 

#include <iostream>
using namespace std;

class Circuit {
    public:
        int get_first_switch_state();
        int get_second_switch_state();
        int get_lamp_state();
        void toggle_first_switch();
        void toggle_second_switch();
    private:
        int first_switch = 0;
        int second_switch = 0;
        int lamp_state = 0;
    };
    
int Circuit::get_first_switch_state() {
    return first_switch;
}

int Circuit::get_second_switch_state() {
    return second_switch;
}

int Circuit::get_lamp_state() {
    // Lamp is on if switches are different
    lamp_state = (first_switch != second_switch);
    return lamp_state;
}

void Circuit::toggle_first_switch() {
    first_switch = 1 - first_switch;
}

void Circuit::toggle_second_switch() {
    second_switch = 1 - second_switch;
}

int main() {
    Circuit* c1 = new Circuit;

    cout << "Initial lamp: " << c1->get_lamp_state() << endl;
    c1->toggle_first_switch();
    cout << "After first toggle: " << c1->get_lamp_state() << endl;
    c1->toggle_second_switch();
    cout << "After second toggle: " << c1->get_lamp_state() << endl;

    delete c1;
    return 0;
}