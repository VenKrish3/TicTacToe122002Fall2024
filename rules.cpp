#include "rules.hpp"

Rules::Rules(Board *board) {
    this->board = board;
    winning_combos[0][0] = 1;
    winning_combos[0][1] = 2;
    winning_combos[0][2] = 3;

    winning_combos[1][0] = 1;
    winning_combos[1][1] = 4;
    winning_combos[1][2] = 7;

    winning_combos[2][0] = 2;
    winning_combos[2][1] = 5;
    winning_combos[2][2] = 8;
}

bool Rules::inProgress() {
    for(int i = 0; i < 3; i++) {
        if(this->threeInARow(winning_combos[i][0], winning_combos[i][1], winning_combos[i][2])) {
            return false;
        }
    }
    
    return true;
}

string Rules::status() {
    for(int i = 0; i < 3; i++) {
        if(this->threeInARow(winning_combos[i][0], winning_combos[i][1], winning_combos[i][2])) {
            return board->getValue(winning_combos[i][0]);
        }
    }
    
    return "";
}

bool Rules::threeInARow(int index_one, int index_two, int index_three) {
    return board->getValue(index_one) == board->getValue(index_two) && board->getValue(index_two) == board->getValue(index_three);
}