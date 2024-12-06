/*
Author: Dawson Pease
Title: Tic Tac Toe game (Final Project)
Date: 12/2/24
*/

#include "Game.h"

// Entry point func calls loop playgame
int main() {
    TicTacToe game;  
    game.playGame();  
    return 0;  
}

// Collects and validates player information
void TicTacToe::getPlayerInfo() {
    cout << "Enter your name: ";  
    cin >> playerName;
    do {
        cout << "Choose your symbol (X or O): ";  
        cin >> playerSymbol;
        playerSymbol = toupper(playerSymbol);  
        if (playerSymbol != 'X' && playerSymbol != 'O') 
            cout << "Invalid symbol! Please choose 'X' or 'O'.\n";
    } while (playerSymbol != 'X' && playerSymbol != 'O');  // Validate the symbol
    lebronSymbol = (playerSymbol == 'X') ? 'O' : 'X';  
}


// Constructor for board
TicTacToe::TicTacToe() {
    initializeBoard(); 
}

// calls for initializeboard func to set up blank 3x3 playing board
void TicTacToe::initializeBoard() {
    for (int i = 0; i < 3; ++i)  
        for (int j = 0; j < 3; ++j)  
            board[i][j] = ' ';  
}

// display board func 
void TicTacToe::displayBoard() {
    cout << "  1   2   3\n";  
    for (int i = 2; i >= 0; --i) {  
        cout << i + 1 << " ";  
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j]; 
            if (j < 2) cout << " | ";  // Add vertical separators between spaces
        }
        cout << "\n";
        if (i > 0) cout << " ---+---+---\n";  // Add horizontal separators between rows
    }
    cout << endl;
}

// Handles player moves 
bool TicTacToe::makeMove(int row, int col, char symbol) {
    if (row < 0 || row > 2 || col < 0 || col > 2) { // validate 1-3 
        cout << "Invalid! Row and column must be between 1 and 3.\n";
        return false;
    }
    if (board[row][col] != ' ') { // validates open space
        cout << "Space already occupied! Please choose another spot.\n";
        return false;
    }
    board[row][col] = symbol;  
    return true;
}

// Checks for win conditions
bool TicTacToe::checkWin(char symbol) {
    // Check rows and columns for 3 of a kind
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||  
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol))    
            return true;
    }
    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||  
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))    
        return true;

    return false;  // No winning condition met
}

// Checks if the board is completely filled
bool TicTacToe::isBoardFull() {
    for (int i = 0; i < 3; ++i)  
        for (int j = 0; j < 3; ++j)  
            if (board[i][j] == ' ')  
                return false;
    return true;  // No empty spaces left
}

// Manages the main game loop
void TicTacToe::playGame() {
    getPlayerInfo();  
    bool playerTurn = true;  

    while (true) {
        displayBoard();  // Show the current state of the board

        if (playerTurn) {
            // Player's turn
            int row, col;
            cout << playerName << "'s turn (" << playerSymbol << "). Enter row and column (1-3): ";
            cin >> row >> col;  
            if (!makeMove(row - 1, col - 1, playerSymbol)) {  
                continue;  // Retry if move is invalid
            }
            if (checkWin(playerSymbol)) {  
                displayBoard();
                displayOutcome(true);  // Display win message/ascii art
                break;
            }
        } else {
            // LeBron's turn 
            cout << "LeBron James' turn (" << lebronSymbol << ").\n";
            bool moveMade = false;
            for (int i = 0; i < 3 && !moveMade; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (makeMove(i, j, lebronSymbol)) {  
                        if (checkWin(lebronSymbol)) {  
                            displayBoard();
                            displayOutcome(false);  // Display loss message
                            return;
                        }
                        moveMade = true;
                        break;  // Break loop
                    }
                }
            }
        }

        // if draw, output draw message
        if (isBoardFull()) {
            displayBoard();
            cout << "It's a draw! LeBron James respects your skills.\n";
            break;
        }

        playerTurn = !playerTurn;  // Switch turns
    }
}

// Displays the outcome of the game based on who won
void TicTacToe::displayOutcome(bool playerWon) {
    if (playerWon) {
        cout << "Congratulations " << playerName << "! You defeated LeBron James!\n";
        cout << "  \\(^_^)/  \n";  
    } else {
        cout << "LeBron James wins! He's just unstoppable!\n";
        cout << "  (T_T)  \n";  
    }
}

