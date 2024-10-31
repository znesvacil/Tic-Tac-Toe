#include <iostream>

#include "tic_tac_toe.hpp"

TicTacToe::TicTacToe(Rules *rules, Board *board, BoardPrinter *boardPrinter)
{
    this->rules = rules;
    this->board = board;
    this->boardPrinter = boardPrinter;
}

void TicTacToe::start()
{
    int userInput;
    cout << boardPrinter->print() << endl;
    while (this->rules->inProgress())
    {
        cout << currentMark << "'s turn!" << endl;
        while (!(cin >> userInput))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "That's not a number. Please try again:" << endl;
        }
        int validInput = rules->validator(userInput);
        board->move(validInput, this->getCurrentMark());
        cout << boardPrinter->print() << endl;
        this->toggleMark();
    }

    cout << rules->status() << endl;
}

void TicTacToe::toggleMark()
{
    if (this->currentMark == "X")
    {
        this->currentMark = "O";
    }
    else
    {
        this->currentMark = "X";
    }
}

string TicTacToe::getCurrentMark()
{
    return this->currentMark;
}
