#pragma once
#include "rules.hpp"

class Data {
private:
public:
    int totalGameCounter;
    int tieGameCounter;
    int playerOneWins;
    int playerTwoWins;
    void printFile();
};
