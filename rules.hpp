#pragma once
#ifndef RULES_HPP
#define RULES_HPP
#endif

#include "board.hpp"

class Rules {
    private:
        Board *board;
        bool three_in_a_row(int index_one, int index_two, int index_three);
        int winning_combos[8][3];
    public:
        Rules(Board *board);
        bool in_progress();
};