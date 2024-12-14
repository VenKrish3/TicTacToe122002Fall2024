#include <iostream>

#include "tic_tac_toe.hpp"
#include "PrinterForResults.hpp"


TicTacToe::TicTacToe(Rules *rules, Board *board, BoardPrinter *boardPrinter)
{
  this->rules = rules;
  this->board = board;
  this->boardPrinter = boardPrinter;
}

void TicTacToe::start()
{
  PrinterForResults printerResults(0,0);
  int userInput;
  cout << boardPrinter->print() << endl;
  while (this->rules->inProgress())
  {
    cout << "Make your move!" << endl;
    cin >> userInput;
    int validInput = rules->validator(userInput);
    board->move(validInput, this->getCurrentMark());
    cout << boardPrinter->print() << endl;
    this->toggleMark();
  }

  cout << rules->status() << endl;
  if (this->currentMark == "X")
  {
	  printerResults.addP1();
  }
  else
	  printerResults.addP2();
}

void TicTacToe::toggleMark()
{
  if (this->currentMark == "X")
  {
    this->currentMark = "O";
  }
  else
  {
    this->currentMark = "X";
  }
}

string TicTacToe::getCurrentMark()
{
  return this->currentMark;
}
