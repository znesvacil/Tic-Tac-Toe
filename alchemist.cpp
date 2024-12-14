#include <iostream>

#include "alchemist.hpp"

Alchemist::Alchemist(Board *board, std::string mark)
{
    this->board = board;
    this->mark = mark;
}

std::string Alchemist::getMark()
{
    return mark;
}

void Alchemist::prompt()
{
    std::cout << "You, " << getMark() << ", are the master of potions!" << std::endl;
    std::cout << "Your knowledge can help you conquer your foe, if you dare use it." << std::endl;
    std::cout << "Do you want to..." << std::endl;
    std::cout << "(1) Make a move" << std::endl;
    std::cout << "(2) Use your arcane knowledge to swap two marks??" << std::endl;
}

int Alchemist::selectOneOrTwo()
{
    int option;
    while (!(cin >> option))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid option!" << endl;
    }
    while (option != 1 && option != 2) {
        std::cout << "Invalid option!" << endl;
        cin.clear();
        while (!(cin >> option))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid option!" << endl;
        }
    }
    return option;
}

void Alchemist::move()
{
    if (selectOneOrTwo() == 1)
    {
        std::cout << "Enter a move!" << std::endl;
        int userInput;
        while (!(cin >> userInput))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "That's not a number. Please try again:" << endl;
        }
        int validInput = this->validator(userInput);
        board->move(validInput, this->mark);
        cin.clear();
    }
    
    else
    {
        if (board->totalMoves() < 2) {
            std::cout << "Unfortunately, your powers are useless at this moment. You must move instead." << endl;
            std::cout << "Enter a move!" << std::endl;
            int userInput;
            while (!(cin >> userInput))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "That's not a number. Please try again:" << endl;
            }
            int validInput = this->validator(userInput);
            board->move(validInput, this->mark);
        }
        else{
            specialMove();
        }
    }
}

int Alchemist::validator(int potentiallyInvalidInput)
{
    int validInput = potentiallyInvalidInput;
    
    while (board->isOccupied(validInput) || (validInput < 1 || validInput > 9))
    {
        if (board->isOccupied(validInput)) {
            cout << "That space is occupied. Please try again:";
        }
        if ((validInput < 1 || validInput > 9)) {
            cout << "That space doesn't exist. Please try again:";
        }
        cout << endl;
        cin.clear();
        while (!(cin >> validInput))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "That's not a number. Please try again:" << endl;
        }
    }
    return validInput;
}

void Alchemist::specialMove() {
    string invalidMark = "That's not a number. Please try again:";
    int userInput1;
    int userInput2;
    
    std::cout << "What mark should you swap?" << endl;
   
    while (!(cin >> userInput1))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << invalidMark << endl;
    }
    while (!board->isOccupied(userInput1) || (userInput1 < 1 || userInput1 > 9) ) {
        if (!board->isOccupied(userInput1)) {
            cout << "That space is empty. Please try again:";
        }
        if ((userInput1 < 1 || userInput1 > 9)) {
            cout << "That space doesn't exist. Please try again:";
        }
        cin.clear();
        while (!(cin >> userInput1))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << invalidMark << endl;
        }
        
    }
    
    std::cout << "And where should you swap it to?" << endl;
   
    while (!(cin >> userInput2))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << invalidMark << endl;
    }
    
    string mark1 = board->getValue(userInput2);
    string mark2 = board->getValue(userInput1);
    
    while (!board->isOccupied(userInput2) || (userInput2 < 1 || userInput2 > 9) || userInput1 == userInput2 || mark1 == mark2) {
        if (!board->isOccupied(userInput2)) {
            cout << "That space is empty. Please try again:";
        }
        if ((userInput2 < 1 || userInput2 > 9)) {
            cout << "That space doesn't exist. Please try again:";
        }
        if (userInput1 == userInput2) {
            cout << "That's the same space! Please try again:";
        }
        else {
            cout << "You must swap with the other mark. Please try again:";
        }
        cout << endl;
        cin.clear();
        while (!(cin >> userInput2))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << invalidMark << endl;
        }
        
    }
    
    board->move(userInput1, mark1);
    board->move(userInput2, mark2);
}
