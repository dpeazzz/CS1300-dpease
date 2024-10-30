/*
Author: Dawson Isaiah Pease III Jr
Date: 10/29/24
Assignment: Guess the number game
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL)); // random number generator

    string name;
    int guess, secretNumber, tries = 6;
    char playAgain;

    do {
        cout << "Welcome to -- Guess the Number -- game!\n";
        cout << "What is your name? ";
        getline(cin, name);

        cout << "Hello, " << name << ". I am thinking of a number between 1 and 20.\n";
        secretNumber = rand() % 20 + 1;

        while (tries > 0) {
            cout << "You have " << tries << " tries left. Take a guess: ";
            cin >> guess;

            if (guess == secretNumber) {
                cout << "Congratulations, " << name << "! You WIN!! You guessed my number in " << 6 - tries + 1 << " guesses.\n";
                break;
            } else if (guess > secretNumber) {
                cout << "Your guess is too high.\n";
            } else {
                cout << "Your guess is too low.\n";
            }
            tries--;
        }

        if (tries == 0) {
            cout << "Sorry, you've run out of tries. The number was " << secretNumber << ".\n";
        }

        cout << "Would you like to play again? Enter [y/n], anything else to quit: ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'n');

    cout << "Thanks for playing!\n";

    return 0;
}


