#include "board.hpp"

void Board::move(int index, string mark)
{
    if (index > 0 && index < 10)
    {
        this->marks[index - 1] = mark;
    }
}

string Board::getValue(int index)
{
    if (index > 0 && index < 10)
    {
        return this->marks[index - 1];
    }
    else
    {
        return "";
    }
}

void Board::clear()
{
    for (int i = 0; i < 9; i++)
    {
        this->marks[i] = to_string(i + 1);
    }
}

int Board::totalMoves() //Originally I kept the full() function, but I needed to check for how many spaces had marks, and that was redundant
{
    int moves = 0;
    for (int i = 0; i < 9; i++)
    {
        if (this->marks[i] != to_string(i + 1))
        {
            moves++;
        }
    }
    return moves;
}

bool Board::isOccupied(int index)
{
    if (isalpha(getValue(index)[0]) || ispunct(getValue(index)[0]))
    {
        return true;
    }
        else {
        return false;
    }
}
