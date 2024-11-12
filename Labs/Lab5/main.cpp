/*
 Loops Lab
    Updated By: Dawson Pease
    CSCI 111
    Date: 11/12/2024

    Program prints geometric shapes of given height with * using loops

*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void printTriangle(int height) {
    // ... (existing code)
}

void printFlippedTriangle(int height) {
    for (int row = height; row >= 1; row--) {
        for (int col = 1; col <= row; col++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void printSquare(int height) {
    for (int row = 1; row <= height; row++) {
        for (int col = 1; col <= height; col++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void clearScreen() {
    // ... (existing code)
}

int main(int argc, char* argv[]) {
    char choice;
    do {
        clearScreen(); // FIXME6
        int height;
        cout << "Program prints geometric shapes of given height with *\n";
        cout << "Please enter the height of the shape: ";
        cin >> height;

        printTriangle(height); // FIXME7
        printFlippedTriangle(height); // FIXME7
        printSquare(height); // FIXME6

        cout << "Do you want to continue? (y/n): ";
        cin >> choice; // FIXME9
    } while (choice == 'y' || choice == 'Y'); // FIXME10

    return 0;
}