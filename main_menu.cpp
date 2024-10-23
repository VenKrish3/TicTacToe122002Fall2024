#include <iostream>

#include "battle_tic_tac_toe.hpp"
#include "board.hpp"
#include "rules.hpp"
#include "tic_tac_toe.hpp"
#include "board_printer.hpp"
#include "main_menu.hpp"

using namespace std;

void MainMenu::printWelcomeMessage()
{
  cout << "Welcome to TTT!" << endl;
  cout << "Choose an Option!" << endl;
  cout << "(1) Regular TTT" << endl;
  cout << "(2) Battle TTT" << endl;
}

void MainMenu::printPlayAgainMessage()
{
  cout << "Do you want to play again?" << endl;
  cout << "(1) Yes" << endl;
  cout << "(2) No" << endl;
}

void MainMenu::printExitMessage()
{
  cout << "Goodbye!" << endl;
}

void MainMenu::buildAndPlayGame(int option)
{
  Board *board = new Board();
  Rules *rules = new Rules(board);
  BoardPrinter *boardPrinter = new BoardPrinter(board);
  if (option == 1)
  {
    TicTacToe *ticTacToe = new TicTacToe(rules, board, boardPrinter);
    ticTacToe->start();
    delete ticTacToe;
  }
  else
  {
    BattleTicTacToe *battleTicTacToe = new BattleTicTacToe(rules, board, boardPrinter);
    battleTicTacToe->start();
    delete battleTicTacToe;
  }

  delete board;
  delete rules;
  delete boardPrinter;
}

void MainMenu::playAgainOrExit()
{
  if (selectOneOrTwo() == 1)
  {
    start();
  }
  else
  {
    printExitMessage();
  }
}

int MainMenu::selectOneOrTwo()
{
  int option;
  cin >> option;
  return option;
}

void MainMenu::start()
{
  printWelcomeMessage();
  buildAndPlayGame(selectOneOrTwo());
  printPlayAgainMessage();
  playAgainOrExit();
}
