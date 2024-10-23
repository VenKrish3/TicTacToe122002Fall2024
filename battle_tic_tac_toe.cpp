#include <iostream>

#include "battle_tic_tac_toe.hpp"

BattleTicTacToe::BattleTicTacToe(Rules *rules, Board *board, BoardPrinter *boardPrinter)
{
  this->rules = rules;
  this->board = board;
  this->boardPrinter = boardPrinter;
}

void BattleTicTacToe::start()
{
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
}

void BattleTicTacToe::toggleMark()
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

string BattleTicTacToe::getCurrentMark()
{
  return this->currentMark;
}
