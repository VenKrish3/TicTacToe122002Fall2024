#include <cassert>

#include "board.hpp"
#include "display_board.hpp"

int main() {
  Board board;
  DisplayBoard *displayBoard = new DisplayBoard(&board);

  assert(displayBoard->generate() == " 1 | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 \n");

  board.move(1, "X");
  assert(displayBoard->generate() == " X | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 \n");

  board.move(2, "O");
  assert(displayBoard->generate() == " X | O | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 \n");

  board.move(3, "W");
  assert(displayBoard->generate() == " X | O | W \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 \n");
}