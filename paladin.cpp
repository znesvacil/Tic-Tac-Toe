#include <iostream>

#include "paladin.hpp"

Paladin::Paladin(Board *board, std::string mark)
{
    this->board = board;
    this->mark = mark;
}

std::string Paladin::getMark()
{
    return mark;
}

void Paladin::prompt()
{
    std::cout << "You, " << getMark() << ", are a powerful knight." << std::endl;
    std::cout << "If you desire, you can move worlds (or maybe just marks)." << std::endl;
    std::cout << "Do you want to..." << std::endl;
    std::cout << "(1) Make a move" << std::endl;
    std::cout << "(2) Use your strength to shift a mark to an adjacent square??" << std::endl;
}

int Paladin::selectOneOrTwo()
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
        while (!(cin >> option))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid option!" << endl;
        }
    }
    return option;
}

void Paladin::move()
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
    }
    else
    {
        if (board->totalMoves() < 1) {
            std::cout << "There is nothing on this board to shift. Your strength would be wasted. Please move instead." << endl;
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
        else
        {
            specialMove();
        }
    }
}

int Paladin::validator(int potentiallyInvalidInput)
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
        while (!(cin >> validInput))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "That's not a number. Please try again:" << endl;
        }
    }
    return validInput;
}

void Paladin::specialMove() {
    string invalidMark = "That's not a number. Please try again:";
    int userInput1;
    int userInput2;
    
    std::cout << "What mark will you shift?" << endl;
   
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
        cout << endl;
        while (!(cin >> userInput1))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << invalidMark << endl;
        }
        
    }
    
    std::cout << "And where will you shift it to?" << endl;
   
    while (!(cin >> userInput2))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << invalidMark << endl;
    }
    while (board->isOccupied(userInput2) || (userInput2 < 1 || userInput2 > 9) || !adjacentTile(userInput1, userInput2) || userInput1 == userInput2) {
        if (board->isOccupied(userInput2)) {
            cout << "That space is occupied. Please try again:";
        }
        if ((userInput2 < 1 || userInput2 > 9)) {
            cout << "That space doesn't exist. Please try again:";
        }
        if (!adjacentTile(userInput1, userInput2)) {
            cout << "That space is too far. Please try again:";
        }
        if (userInput1 == userInput2) {
            cout << "That's the same space! Please try again:";
        }
        cout << endl;
        while (!(cin >> userInput2))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << invalidMark << endl;
        }
        
    }
    
    string mark1 = board->getValue(userInput1);
    
    board->move(userInput2, mark1);
    board->move(userInput1, to_string(userInput1));
}

bool Paladin::adjacentTile(int input1, int input2) //Is there a more efficient way to do this? I'd very much love to know 
{
    if (input1 == 1 && (input2 == 2 || input2 == 4 || input2 == 5)) {
        return true;
    }
    else if (input1 == 2 && (input2 == 1 || input2 == 3 || input2 == 4 || input2 == 5 || input2 == 6)) {
        return true;
    }
    else if (input1 == 3 && (input2 == 2 || input2 == 5 || input2 == 6)) {
        return true;
    }
    else if (input1 == 4 && (input2 == 1 || input2 == 2 || input2 == 5 || input2 == 7 || input2 == 8)) {
        return true;
    }
    else if (input1 == 5 && input2 != 5) {
        return true;
    }
    else if (input1 == 6 && (input2 == 2 || input2 == 3 || input2 == 5 || input2 == 8 || input2 == 9)) {
        return true;
    }
    else if (input1 == 7 && (input2 == 4 || input2 == 5 || input2 == 8)) {
        return true;
    }
    else if (input1 == 8 && (input2 == 4 || input2 == 5 || input2 == 6 || input2 == 7 || input2 == 9)) {
        return true;
    }
    else if (input1 == 9 && (input2 == 5 || input2 == 6 || input2 == 8)) {
        return true;
    }
    else {
        return false;
    }
}
