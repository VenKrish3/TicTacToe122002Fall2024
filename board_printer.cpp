#include <sstream>

#include "board_printer.hpp"

BoardPrinter::BoardPrinter(Board *board) {
    this->board = board;
}

string BoardPrinter::print() {
    stringstream ss;
    ss << this->edgeSpace
       << board->getValue(1)
       << this->verticalDivider
       << board->getValue(2)
       << this->verticalDivider
       << board->getValue(3)
       << this->edgeSpace
       << this->horizontalDivider
       << "   |   |   \n-----------\n   |   |   ";
    return ss.str();
}