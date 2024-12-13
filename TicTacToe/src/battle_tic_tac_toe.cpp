#include <iostream>

#include "PrinterForResults.hpp"
#include "battle_tic_tac_toe.hpp"

BattleTicTacToe::BattleTicTacToe(Rules *rules, Board *board, BoardPrinter *boardPrinter, Player *playerOne, Player *playerTwo)
{
  this->rules = rules;
  this->board = board;
  this->boardPrinter = boardPrinter;
  this->playerOne = playerOne;
  this->playerTwo = playerTwo;
  this->currentPlayer = playerOne;
}

void BattleTicTacToe::start()
{
  int userInput;
  cout << boardPrinter->print() << endl;
  while (this->rules->inProgress())
  {
    currentPlayer->prompt();
    currentPlayer->move();
    std::cout << boardPrinter->print() << std::endl;
    togglePlayer();
  }

  cout << rules->status() << endl;
  if (currentPlayer->getMark() == playerOne->getMark())
  {
	  PrinterForResults printerResults(1,0);
  }
  else
	  PrinterForResults printerResults(0,1);
}

void BattleTicTacToe::togglePlayer()
{
  if (currentPlayer->getMark() == playerOne->getMark())
  {
    currentPlayer = playerTwo;
  }
  else
  {
    currentPlayer = playerOne;
  }
}
