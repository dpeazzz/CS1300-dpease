/*
Conditionals - Homeowork 4
Author: Dawson Pease
Date: 10/5/2024
*/

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

void test ();

template <typename T>
T findLargest(T a, T b, T c, T d, T e) {
    T largest = a;

    if (b > largest) largest = b;
    if (c > largest) largest = c;
    if (d > largest) largest = d;
    if (e > largest) largest = e;

    return largest;
}

template <typename T>
T findSmallest(T a, T b, T c, T d, T e) {
    T smallest = a;

    if (b < smallest) smallest = b;
    if (c < smallest) smallest = c;
    if (d < smallest) smallest = d;
    if (e < smallest) smallest = e;

    return smallest;
}

template <typename T>
string sumEvenOddZero(T a, T b, T c, T d, T e) {
    T sum = a + b + c + d + e;
    
    if (sum == 0) {
        return "zero";
    }

    if (static_cast<int>(sum) % 2 == 0) {
        return "even";
    } else {
        return "odd";
    }
}

void GetNumbers(double& a, double& b, double& c, double& d, double& e) {
    test();
    string name;
    cout << "Enter name: ";
    cin >> name;
    cout << "Hello, " << name << " Please enter 5 integers with spaces: ";
    cin >> a >> b >> c >> d >> e;
   
}


void test() {
    
    assert(findLargest(3, 5, 2, 8, 1) == 8);
    assert(findLargest(-1, -5, -3, -2, -4) == -1);
    assert(findLargest(1.5, 2.5, 0.5, 3.5, 2.0) == 3.5);

    assert(findSmallest(3, 5, 2, 8, 1) == 1);
    assert(findSmallest(-1, -5, -3, -2, -4) == -5);
    assert(findSmallest(1.5, 2.5, 0.5, 3.5, 2.0) == 0.5);

    assert(sumEvenOddZero(1, 1, 1, 1, 1) == "odd");
    assert(sumEvenOddZero(2, 2, 2, 2, 2) == "even");
    assert(sumEvenOddZero(0, 0, 0, 0, 0) == "zero");

    cout << "All test cases passed...\n";
}

int main(int argc, char* argv[]) {
    if (argc > 1 && string(argv[1]) == "test") {
        test();
        return 0;
    }

    double a, b, c, d, e;
    char choice;
    do {
        GetNumbers(a, b, c, d, e);
        
        cout << "\nMenu:\n";
        cout << "1. Find Largest Number\n";
        cout << "2. Find Smallest Number\n";
        cout << "3. Sum Even/Odd/Zero\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Largest Number is " << findLargest(a, b, c, d, e) << endl;
                break;
            case '2':
                cout << "Smallest Number is" << findSmallest(a, b, c, d, e) << endl;
                break;
            case '3':
                cout << "The sum is " << sumEvenOddZero(a, b, c, d, e) << "." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << "Do you want to enter another set of numbers? : ";
        cin >> choice;
    } while (choice == 'y');

    return 0;
}