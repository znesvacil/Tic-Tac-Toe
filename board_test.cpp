#include <cassert>
#include <iostream>

#include "board.hpp"

using namespace std;
/*
int main()
{
  cout << "Running the tests..." << endl;

  Board board;

  board.move(1, "X");
  assert(board.getValue(1) == "X");

  board.move(2, "O");
  assert(board.getValue(2) == "O");

  board.move(3, "W");
  assert(board.getValue(3) == "W");

  board.move(4, "Y");
  assert(board.getValue(4) == "Y");
    
  board.move(5, "B");
  assert(board.getValue(5) == "B");
    
  board.move(6, "N");
  assert(board.getValue(6) == "N");
    
  board.move(7, "A");
  assert(board.getValue(7) == "A");
    
  board.move(8, "F");
  assert(board.getValue(8) == "F");
    
  board.move(9, "L");
  assert(board.getValue(9) == "L");
 
  // Make sure there are no segmentation faults
  board.move(1000, "X");
  assert(board.getValue(1000) == "");

  // Make sure there are no segmentation faults
  board.move(-1, "X");
  assert(board.getValue(-1) == "");

  board.clear();
  for(int i = 1; i <= 9; i++) {
     assert(board.getValue(i) == to_string(i));
  }

  cout << "All of the tests have passed!" << endl;
}
*/
