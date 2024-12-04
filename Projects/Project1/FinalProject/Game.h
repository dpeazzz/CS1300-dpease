#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    string playerName;
    char playerSymbol;
    char lebronSymbol;

public:
    TicTacToe();
    void initializeBoard();
    void displayBoard();
    void getPlayerInfo();
    bool makeMove(int row, int col, char symbol);
    bool checkWin(char symbol);
    bool isBoardFull();
    void playGame();
    void displayOutcome(bool playerWon);
};

#endif
