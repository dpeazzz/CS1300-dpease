/*
Author: Dawson Pease
Title: Tic Tac Toe game (Final Project)
Date:12/2/24
*/

#include "Game.h"

TicTacToe::TicTacToe() {
    initializeBoard();
}

void TicTacToe::initializeBoard() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

void TicTacToe::displayBoard() {
    cout << "  1   2   3\n";
    for (int i = 2; i >= 0; --i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i > 0) cout << " ---+---+---\n";
    }
    cout << endl;
}

void TicTacToe::getPlayerInfo() {
    cout << "Enter your name: ";
    cin >> playerName;
    do {
        cout << "Choose your symbol (X or O): ";
        cin >> playerSymbol;
        playerSymbol = toupper(playerSymbol);
    } while (playerSymbol != 'X' && playerSymbol != 'O');
    lebronSymbol = (playerSymbol == 'X') ? 'O' : 'X';
}

bool TicTacToe::makeMove(int row, int col, char symbol) {
    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
        return false;
    board[row][col] = symbol;
    return true;
}

bool TicTacToe::checkWin(char symbol) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i)
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol))
            return true;

    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
            return true;

    return false;
}

bool TicTacToe::isBoardFull() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void TicTacToe::playGame() {
    getPlayerInfo();
    bool playerTurn = true;

    while (true) {
        displayBoard();
        if (playerTurn) {
            int row, col;
            cout << playerName << "'s turn (" << playerSymbol << "). Enter row and column (1-3): ";
            cin >> row >> col;
            if (!makeMove(row - 1, col - 1, playerSymbol)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }
            if (checkWin(playerSymbol)) {
                displayBoard();
                displayOutcome(true);
                break;
            }
        } else {
            // LeBron James' turn
            cout << "LeBron James' turn (" << lebronSymbol << ").\n";
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (makeMove(i, j, lebronSymbol)) {
                        if (checkWin(lebronSymbol)) {
                            displayBoard();
                            displayOutcome(false);
                            return;
                        }
                        goto nextTurn;
                    }
                }
            }
        }
    nextTurn:
        if (isBoardFull()) {
            displayBoard();
            cout << "It's a draw! LeBron James respects your skills.\n";
            break;
        }
        playerTurn = !playerTurn;
    }
}

void TicTacToe::displayOutcome(bool playerWon) {
    if (playerWon) {
        cout << "Congratulations " << playerName << "! You defeated LeBron James!\n";
        cout << "  \\(^_^)/  \n";
    } else {
        cout << "LeBron James wins! He's just unstoppable!\n";
        cout << "  (T_T)  \n";
    }
}

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
