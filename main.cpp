#include <iostream>

#include "main_menu.hpp"
#include "data.hpp"

using namespace std;

int main()
{
    MainMenu menu;
    Data data;
    data.playerOneWins = 0;
    data.playerTwoWins = 0;
    data.tieGameCounter = 0;
    data.totalGameCounter = 0;
    menu.start(data);
}
