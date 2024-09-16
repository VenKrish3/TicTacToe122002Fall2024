#include <sstream>

#include "display_board.hpp"

DisplayBoard::DisplayBoard(Board *board) {
    this->board = board;
}

string DisplayBoard::generate() {
  stringstream ss;
  ss << this->edgeSpacer
  << board->getValue(1)
  << this->verticalDivider
  << board->getValue(2)
  << this->verticalDivider
  << board->getValue(3)
  << this->edgeSpacer
  << this->horizontalDivider
  << " 4 | 5 | 6 \n-----------\n 7 | 8 | 9 \n";
  return ss.str();
}