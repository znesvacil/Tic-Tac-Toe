#include <cassert>
#include <iostream>

#include "board.hpp"
#include "board_printer.hpp"

/*
int main() {
    Board board;
    BoardPrinter *boardPrinter = new BoardPrinter(&board);

    assert(boardPrinter->print() == " 1 | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 ");

    board.move(1, "X");
    assert(boardPrinter->print() == " X | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 ");

    board.move(2, "O");
    assert(boardPrinter->print() == " X | O | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 ");

    board.move(3, "W");
    assert(boardPrinter->print() == " X | O | W \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 ");
    
    board.move(4, "H");
    assert(boardPrinter->print() == " X | O | W \n-----------\n H | 5 | 6 \n-----------\n 7 | 8 | 9 ");
    
    board.move(5, "Y");
    assert(boardPrinter->print() == " X | O | W \n-----------\n H | Y | 6 \n-----------\n 7 | 8 | 9 ");
    
    board.move(6, "M");
    assert(boardPrinter->print() == " X | O | W \n-----------\n H | Y | M \n-----------\n 7 | 8 | 9 ");
    
    board.move(7, "N");
    assert(boardPrinter->print() == " X | O | W \n-----------\n H | Y | M \n-----------\n N | 8 | 9 ");
    
    board.move(8, "K");
    assert(boardPrinter->print() == " X | O | W \n-----------\n H | Y | M \n-----------\n N | K | 9 ");
    
    board.move(9, "A");
    assert(boardPrinter->print() == " X | O | W \n-----------\n H | Y | M \n-----------\n N | K | A ");
    
    cout << "All tests passed!" <<endl;
}*/

