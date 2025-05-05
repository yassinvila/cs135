/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E9.5 CPP

Describe: Implement a class Rectangle. Provide a constructor 
to construct a rectangle with a given width and height, 
member functions get_perimeter and get_area that compute the 
perimeter and area, and a member function void resize(double
factor) that resizes the rectangle by multiplying the width
and height by the given factor.
///
////
/////
*/ 

#include <iostream>
using namespace std;

class Rectangle {
public:
    // Constructor
    Rectangle(double w, double h);

    // Accessor functions
    double get_perimeter() const;
    double get_area() const;

    // Resizes the rectangle
    void resize(double factor);

private:
    double width;
    double height;
};


Rectangle::Rectangle(double w, double h) {
    width = w;
    height = h;
}

double Rectangle::get_perimeter() const {
    return 2 * (width + height);
}

double Rectangle::get_area() const {
    return width * height;
}

void Rectangle::resize(double factor) {
    width *= factor;
    height *= factor;
}

// --- Optional main() for testing ---
int main() {
    Rectangle r(4.0, 3.0);
    cout << "Perimeter: " << r.get_perimeter() << endl;
    cout << "Area: " << r.get_area() << endl;

    r.resize(2.0);
    cout << "After resizing by factor of 2:\n";
    cout << "Perimeter: " << r.get_perimeter() << endl;
    cout << "Area: " << r.get_area() << endl;

    return 0;
}