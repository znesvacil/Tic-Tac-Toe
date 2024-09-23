#include <cassert>
#include <iostream>

#include "board.hpp"
#include "rules.hpp"

using namespace std;
/*
int main() {
    cout << "Starting the tests" << endl;

    Board board;
    Rules *rules = new Rules(&board);

    assert(rules->inProgress());

    board.move(1, "X");
    assert(rules->inProgress());

    board.move(2, "X");
    assert(rules->inProgress());

    board.move(3, "X");
    assert(!rules->inProgress());

    board.clear();

    board.move(1, "O");
    assert(rules->inProgress());

    board.move(2, "O");
    assert(rules->inProgress());

    board.move(3, "O");
    assert(!rules->inProgress());

    board.clear();
    
    board.move(4, "S");
    assert(rules->inProgress());

    board.move(5, "S");
    assert(rules->inProgress());

    board.move(6, "S");
    assert(!rules->inProgress());
    
    board.clear();
   
    board.move(7, "Y");
    assert(rules->inProgress());

    board.move(8, "Y");
    assert(rules->inProgress());

    board.move(9, "Y");
    assert(!rules->inProgress());
    
    board.clear();

    board.move(1, "F");
    assert(rules->inProgress());
    assert(rules->status() == "");

    board.move(4, "F");
    assert(rules->inProgress());
    assert(rules->status() == "");

    board.move(7, "F");
    assert(!rules->inProgress());
    assert(rules->status() == "F");

    board.clear();

    board.move(2, "P");
    assert(rules->inProgress());

    board.move(5, "P");
    assert(rules->inProgress());

    board.move(8, "P");
    assert(!rules->inProgress());
 
    board.clear();
    
    board.move(3, "W");
    assert(rules->inProgress());

    board.move(6, "W");
    assert(rules->inProgress());

    board.move(9, "W");
    assert(!rules->inProgress());
    
    board.clear();
    
    board.move(1, "T");
    assert(rules->inProgress());

    board.move(5, "T");
    assert(rules->inProgress());

    board.move(9, "T");
    assert(!rules->inProgress());
    
    board.clear();
    
    board.move(3, "V");
    assert(rules->inProgress());

    board.move(5, "V");
    assert(rules->inProgress());

    board.move(7, "V");
    assert(!rules->inProgress());

    board.clear();
    
    board.move(1, "A");
    assert(rules->inProgress());
    
    board.move(2, "B");
    assert(rules->inProgress());
    
    board.move(3, "C");
    assert(rules->inProgress());
    
    board.move(4, "D");
    assert(rules->inProgress());
    
    board.move(5, "E");
    assert(rules->inProgress());
    
    board.move(6, "F");
    assert(rules->inProgress());
    
    board.move(7, "G");
    assert(rules->inProgress());
    
    board.move(8, "H");
    assert(rules->inProgress());
 
    board.move(9, "I");
    assert(!rules->inProgress());
    assert(rules->status() == "T");
    
    cout << "All of the tests passed!" << endl;
}
*/
