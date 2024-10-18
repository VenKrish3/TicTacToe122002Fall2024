#include <iostream>
#include <cassert>

#include "board.hpp"
#include "game.hpp"

using namespace std;

int main()
{
  cout << "Starting the tests" << endl;

  Board board;
  Rules *rules = new Rules(&board);
  BoardPrinter *printer = new BoardPrinter(&board);
  Game *game = new Game(rules, &board, printer);

  assert(game->getCurrentMark() == "X");

  game->toggleMark();

  assert(game->getCurrentMark() == "O");

  game->toggleMark();

  assert(game->getCurrentMark() == "X");

  cout << "All tests have passed" << endl;
}
