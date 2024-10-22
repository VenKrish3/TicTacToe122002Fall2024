#include <iostream>

#include "board.hpp"
#include "rules.hpp"
#include "tic_tac_toe.hpp"
#include "board_printer.hpp"

using namespace std;

int main()
{
  Board board;
  Rules *rules = new Rules(&board);
  BoardPrinter *boardPrinter = new BoardPrinter(&board);
  TicTacToe *ticTacToe = new TicTacToe(rules, &board, boardPrinter);

  ticTacToe->start();
}
