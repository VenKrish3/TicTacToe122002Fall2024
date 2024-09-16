#pragma once
#ifndef DISPLAYBOARD_HPP
#define DISPLAYBOARD_HPP
#endif

#include <string>

#include "board.hpp"

class DisplayBoard {
    private:
      Board *board;
      string verticalDivider = " | ";
      string edgeSpacer = " ";
      string horizontalDivider = "\n-----------\n";

    public:
      DisplayBoard(Board *board);
      string generate();
};