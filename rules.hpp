#pragma once
#ifndef RULES_HPP
#define RULES_HPP
#endif

#include "board.hpp"

class Rules {
    private:
        Board *board;
        bool turn;
        bool threeInARow(int index_one, int index_two, int index_three);
        int winning_combos[8][3];
    public:
    	int validator(int);
    	string currentTurn();
        Rules(Board *board);
        bool inProgress();
        string status();
};
