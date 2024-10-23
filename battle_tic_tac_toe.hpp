#pragma once

#include <string>

#include "rules.hpp"
#include "board.hpp"
#include "board_printer.hpp"

class BattleTicTacToe
{
private:
  Rules *rules;
  Board *board;
  BoardPrinter *boardPrinter;
  string currentMark = "X";

public:
  string getCurrentMark();
  BattleTicTacToe(Rules *rules, Board *board, BoardPrinter *boardPrinter);
  void toggleMark();
  void start();
};
