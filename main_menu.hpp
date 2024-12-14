#pragma once
#include "data.hpp"

class MainMenu
{
private:
    void printExitMessage();
    void printPlayAgainMessage();
    void printWelcomeMessage();
    void printCharacterOptions();
    void buildAndPlayGame(Data data);
    bool invalidMark(std::string mark);
    

public:
    void start(Data data);
};
