/*
Author: Yassin Vila
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW LAB 5

Describe: Write a program numbers.cpp that defines a function
If n is divisible by d, the function should return true, otherwise return false.
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
using namespace std;

bool isDivisibleBy(int n, int d) {
    if (d == 0) {
        return false;
    } else if (n % d == 0) {
        return true;
    } else return false;
}

bool isPrime(int n) {
    if (n < 2) {
        return false;
    } else if (n % n == 0 && n % 1 == 0) {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
    return true;
    }
} 

int nextPrime(int n) {
    int i = n;

    while (true) {
        i++;  
        if (i < 2) continue;

        bool prime = true; 
        if (i % i == 0 && i % 1 == 0) { 
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    prime = false; 
                    break;
                }
            }
        }

        if (prime) {
            break;
        }
    }
    return i;
}

int countPrimes(int a, int b) {
    int count = 0;
    for (int i = a; i <= b; i++) {
        if (i < 2) continue;
        bool meow = true;

        if (i % i == 0 && i % 1 == 0) { 
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    meow = false;
                    break;
                }
            }
        }
        
        if (meow) {
            count++;
        }
    }

    return count;
}

bool isTwinPrime(int n) {
    if (isPrime(n)) {
        if (isPrime(n-2) || isPrime(n+2)) {
            return true;
        } else return false;
    } else return false;
}

int nextTwinPrime(int n) {
    int abc = n;
    while (true) {
    abc++;
        if(isPrime(abc)) {
            if(isTwinPrime(abc)) {
                return abc;
            }
        }
    }
}

int largestTwinPrime(int a, int b) {
    int large = -1;
    for (int c = b; c >= a; c--) {
        if(isPrime(c) && isTwinPrime(c)) {
            return c;
        }
    }

    return -1;

}

int main () {
    cout << "Input integer one: ";
    int int1; cin >> int1; cout << endl;

    cout << "Input integar two: ";
    int int2; cin >> int2; cout << endl;

    if (isDivisibleBy(int1, int2)) {
        cout << "Yes";
    } else cout << "No";

    if (isPrime(int1)) {
        cout << "true";
    } else cout << "false";

    cout << "The next prime is " << nextPrime(int1) << endl;

    if (isTwinPrime(int1)) {
        cout << "twin prime";
    } else cout << "not twin prime";

    cout << "The next twin prime is " << nextTwinPrime(int1) << endl;

    cout << "The large twin prime in range is " << largestTwinPrime(int1, int2);
}