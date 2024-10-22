#include <iostream>

#include "battle_tic_tac_toe.hpp"
#include "board.hpp"
#include "rules.hpp"
#include "tic_tac_toe.hpp"
#include "board_printer.hpp"
#include "main_menu.hpp"

using namespace std;

void MainMenu::start()
{
  cout << "Welcome to TTT!" << endl;
  cout << "Choose an Option!" << endl;
  cout << "(1) Regular TTT" << endl;
  cout << "(2) Battle TTT" << endl;

  int option;
  cin >> option;

  if (option == 1)
  {
    Board board;
    Rules *rules = new Rules(&board);
    BoardPrinter *boardPrinter = new BoardPrinter(&board);
    TicTacToe *ticTacToe = new TicTacToe(rules, &board, boardPrinter);
    ticTacToe->start();
  }
  else
  {
    BattleTicTacToe *battleTicTacToe = new BattleTicTacToe();
    battleTicTacToe->start();
  }
}
