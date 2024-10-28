#pragma once

class MainMenu
{
private:
    void playAgainOrExit();
    void printExitMessage();
    void printPlayAgainMessage();
    void printWelcomeMessage();
    void printCharacterOptions();
    void buildAndPlayGame();
    bool invalidMark(std::string mark);
    

public:
    void start();
};
