#pragma once

#include <string>

#include "rules.hpp"
#include "board.hpp"
#include "board_printer.hpp"

class Game
{
private:
  Rules *rules;
  Board *board;
  BoardPrinter *boardPrinter;
  string currentMark = "X";

public:
  string getCurrentMark();
  Game(Rules *rules, Board *board, BoardPrinter *boardPrinter);
  void toggleMark();
  void start();
};
