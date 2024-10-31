#include <iostream>

#include "battle_tic_tac_toe.hpp"
#include "board.hpp"
#include "rules.hpp"
#include "tic_tac_toe.hpp"
#include "board_printer.hpp"
#include "main_menu.hpp"
#include "paladin.hpp"
#include "alchemist.hpp"

void MainMenu::printWelcomeMessage()
{
    std::cout << "Welcome to TTT!" << endl;
    std::cout << "Choose an Option!" << endl;
    std::cout << "(1) Regular TTT" << endl;
    std::cout << "(2) Battle TTT" << endl;
}

void MainMenu::printPlayAgainMessage()
{
    std::cout << "Do you want to play again?" << endl;
    std::cout << "(1) Yes" << endl;
    std::cout << "(2) No" << endl;
}

void MainMenu::printExitMessage()
{
    std::cout << "Thanks for playing!" << endl;
}

void MainMenu::printCharacterOptions()
{
    std::cout << "(1) Paladin (Can shift marks to adjacent, empty spaces)" << endl;
    std::cout << "(2) Alchemist (Can trade places with other marks)" << endl;
}

bool MainMenu::invalidMark(string mark)
{
    string validMarks = "?!*~$%#";
    
    if (mark.length() != 1) {
        return true;
    }
    
    for(int i = 0; i < 7; i++) {
        if (mark[0] == validMarks[i] || isalpha(mark[0])) {
            return false;
        }
    }
    return true;
}

void MainMenu::buildAndPlayGame()
{
    Board *board = new Board();
    Rules *rules = new Rules(board);
    BoardPrinter *boardPrinter = new BoardPrinter(board);
    int option;
    int playerOneCharacter;
    int playerTwoCharacter;
    std::string playerOneMark;
    std::string playerTwoMark;
    
    while (!(cin >> option))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid option!" << endl;
        std::cout << "(1) Regular TTT" << endl;
        std::cout << "(2) Battle TTT" << endl;
    }
    while (option != 1 && option != 2) {
        std::cout << "Invalid option!" << endl;
        std::cout << "(1) Regular TTT" << endl;
        std::cout << "(2) Battle TTT" << endl;
        while (!(cin >> option))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid option!" << endl;
            std::cout << "(1) Regular TTT" << endl;
            std::cout << "(2) Battle TTT" << endl;
        }
    }
        if (option == 1)
        {
            TicTacToe *ticTacToe = new TicTacToe(rules, board, boardPrinter);
            ticTacToe->start();
            delete ticTacToe;
        }
        else
        {
            std::cout << "Player 1: Choose your mark!" << std::endl;
            cin >> playerOneMark;
            while (invalidMark(playerOneMark)) {
                std::cout << "That mark is invalid. Use a letter, or these symbols: ?, !, *, ~, $, %, #. Try again:" << endl;
                cin >> playerOneMark;
            }
            
            std::cout << "Ok Player 1, Now choose your character!" << std::endl;
            printCharacterOptions();
            
            while (!(cin >> playerOneCharacter))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid option!" << endl;
                printCharacterOptions();
            }
            
            while (playerOneCharacter != 1 && playerOneCharacter != 2)
            {
                cout << "Invalid option!" << endl;
                printCharacterOptions();
                while (!(cin >> playerOneCharacter))
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid option!" << endl;
                    printCharacterOptions();
                }
            }
            
            std::cout << "Player 2: Choose your mark!" << std::endl;
            cin >> playerTwoMark;
            while (invalidMark(playerTwoMark) || tolower(playerTwoMark[0]) == tolower(playerOneMark[0])) {
                if (tolower(playerTwoMark[0]) == tolower(playerOneMark[0])) {
                    std::cout << "Please use a different mark from your opponent. Try again:" << endl;
                }
                else {
                    std::cout << "That mark is invalid. Use a letter, or these symbols: ?, !, *, ~, $, %, #. Try again:" << endl;
                }
                cin >> playerTwoMark;
            }
            
            std::cout << "Ok Player 2, Now choose your character!" << std::endl;
            printCharacterOptions();
            
            while (!(cin >> playerTwoCharacter))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid option!" << endl;
                printCharacterOptions();
            }
            
            while (playerTwoCharacter != 1 && playerTwoCharacter != 2)
            {
                cout << "Invalid option!" << endl;
                printCharacterOptions();
                while (!(cin >> playerTwoCharacter))
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid option!" << endl;
                    printCharacterOptions();
                }
            }
            
            if (playerOneCharacter == 1) { //Another case where I wonder if there's a more efficient way of doing it. This sure does work!
                Player *playerOne = new Paladin(board, playerOneMark);
                if (playerTwoCharacter == 1) {
                    Player *playerTwo = new Paladin(board, playerTwoMark);
                    BattleTicTacToe *battleTicTacToe = new BattleTicTacToe(rules, board, boardPrinter, playerOne, playerTwo);
                    battleTicTacToe->start();
                    delete battleTicTacToe;
                    delete playerOne;
                    delete playerTwo;
                }
                
                else if (playerTwoCharacter == 2) {
                    Player *playerTwo = new Alchemist(board, playerTwoMark);
                    BattleTicTacToe *battleTicTacToe = new BattleTicTacToe(rules, board, boardPrinter, playerOne, playerTwo);
                    battleTicTacToe->start();
                    delete battleTicTacToe;
                    delete playerOne;
                    delete playerTwo;
                }
            }
            else if (playerOneCharacter == 2) {
                Player *playerOne = new Alchemist(board, playerOneMark);
                if (playerTwoCharacter == 1) {
                    Player *playerTwo = new Paladin(board, playerTwoMark);
                    BattleTicTacToe *battleTicTacToe = new BattleTicTacToe(rules, board, boardPrinter, playerOne, playerTwo);
                    battleTicTacToe->start();
                    delete battleTicTacToe;
                    delete playerOne;
                    delete playerTwo;
                }
                
                else if (playerTwoCharacter == 2) {
                    Player *playerTwo = new Alchemist(board, playerTwoMark);
                    BattleTicTacToe *battleTicTacToe = new BattleTicTacToe(rules, board, boardPrinter, playerOne, playerTwo);
                    battleTicTacToe->start();
                    delete battleTicTacToe;
                    delete playerOne;
                    delete playerTwo;
                }
            }
        }
    
    delete board;
    delete rules;
    delete boardPrinter;
}

void MainMenu::playAgainOrExit()
{
    int option;
    while (!(cin >> option))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid option!" << endl;
        printPlayAgainMessage();
    }
    while (option != 1 && option != 2) {
        std::cout << "Invalid option!" << endl;
        printPlayAgainMessage();
        while (!(cin >> option))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid option!" << endl;
            printPlayAgainMessage();
        }
    }
    if (option == 1)
    {
        start();
    }
    else
    {
        printExitMessage();
    }
}

void MainMenu::start()
{
    printWelcomeMessage();
    buildAndPlayGame();
    printPlayAgainMessage();
    playAgainOrExit();
}
