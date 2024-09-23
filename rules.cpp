#include "rules.hpp"

Rules::Rules(Board *board) {
    this->board = board;
    winning_combos[0][0] = 1;
    winning_combos[0][1] = 2;
    winning_combos[0][2] = 3;
    
    winning_combos[1][0] = 4;
    winning_combos[1][1] = 5;
    winning_combos[1][2] = 6;
    
    winning_combos[2][0] = 7;
    winning_combos[2][1] = 8;
    winning_combos[2][2] = 9;

    winning_combos[3][0] = 1;
    winning_combos[3][1] = 4;
    winning_combos[3][2] = 7;

    winning_combos[4][0] = 2;
    winning_combos[4][1] = 5;
    winning_combos[4][2] = 8;
    
    winning_combos[5][0] = 3;
    winning_combos[5][1] = 6;
    winning_combos[5][2] = 9;
    
    winning_combos[6][0] = 1;
    winning_combos[6][1] = 5;
    winning_combos[6][2] = 9;
    
    winning_combos[7][0] = 3;
    winning_combos[7][1] = 5;
    winning_combos[7][2] = 7;
}

bool Rules::inProgress() {
    for(int i = 0; i < 8; i++) {
        if(this->threeInARow(winning_combos[i][0], winning_combos[i][1], winning_combos[i][2])) {
            return false;
        }
    }
    
    if(DetectTie() == true) {
        return false;
    }
        
    return true;
}

string Rules::status() {
    for(int i = 0; i < 8; i++) {
        if(this->threeInARow(winning_combos[i][0], winning_combos[i][1], winning_combos[i][2])) {
            return board->getValue(winning_combos[i][0]);
        }
    }
    
    if(DetectTie() == true) {
        return "T";
    }
    
    return "";
}

bool Rules::DetectTie() {
    int Tie = 0;
    
    for(int i = 0; i < 8; i++) {
        if(this->threeInARow(winning_combos[i][0], winning_combos[i][1], winning_combos[i][2])) {
            return false;
        }
    }
    
    for(int i = 1; i <= 9; i++) {
        if(board->getValue(i) != to_string(i)) {
            Tie++;
        }
    }
    
    if(Tie == 9) {
        return true;
    }
    
    else {
        return false;
    }
}

bool Rules::threeInARow(int index_one, int index_two, int index_three) {
    return board->getValue(index_one) == board->getValue(index_two) && board->getValue(index_two) == board->getValue(index_three);
}
