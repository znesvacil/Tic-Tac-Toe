#include <iostream>

#include "game.hpp" 

Game::Game(Rules *rules, Board *board, BoardPrinter *boardPrinter) {
    this->rules = rules;
    this->board = board;
    this->boardPrinter = boardPrinter;
}

void Game::start() {
    int userInput;
    string invalid = "That move is invalid.";
    
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << boardPrinter->print() << endl;
    while(this->rules->inProgress()) {
        cout << currentMark << "'s turn!" << endl;
        
        while (!(cin >> userInput))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << invalid << endl;
            cout << boardPrinter->print() << endl;
            cout << currentMark << "'s turn!" << endl;
        }
        
        if(board->getValue(userInput) == "X" || board->getValue(userInput) == "O") {
            cout << invalid << endl;
            cout << boardPrinter->print() << endl;
        }
        
        else if(userInput > 0 && userInput < 10) {
            board->move(userInput, this->getCurrentMark());
            cout << boardPrinter->print() << endl;
            this->toggleMark();
        }
        
        else{
            cout << invalid << endl;
            cout << boardPrinter->print() << endl;
        }
    }
    
    if (rules->status() == "T") {
        cout << "This game is a tie." << endl;
    }
    
    else{
        cout << rules->status() << " wins the game!" << endl;
    }
}

void Game::toggleMark() {
    if(this->currentMark == "X") {
        this->currentMark = "O";
    } else {
        this->currentMark = "X";
    }
}

string Game::getCurrentMark() {
    return this->currentMark;
}
