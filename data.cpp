#include "data.hpp"
#include <iostream>
#include <fstream>

void Data::printFile()
{
    std::ofstream report("TTTGameReport.txt");

    report << "Total games played: " << totalGameCounter << std::endl;
    report << "Total games Player One won: " << playerOneWins << std::endl;
    report << "Total games Player Two won: " << playerTwoWins << std::endl;
    report << "Total games tied: " << tieGameCounter << std::endl;
    report << "Thanks again for playing!" << std::endl;
    report.close();
}

