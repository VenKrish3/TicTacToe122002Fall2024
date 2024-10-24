#include <iostream>

#include "goblin.hpp"

Goblin::Goblin(Board *board, std::string mark)
{
  this->board = board;
  this->mark = mark;
}

std::string Goblin::getMark()
{
  return mark;
}

void Goblin::move()
{
  std::cout << "Make your move!" << std::endl;
  int userInput;
  std::cin >> userInput;
  int validInput = this->validator(userInput);
  std::cout << "I am a goblin! I am making a move! Fear me!" << std::endl;
  board->move(validInput, this->mark);
}

int Goblin::validator(int potentiallyInvalidInput)
{
  int validInput = potentiallyInvalidInput;

  // TODO: Be careful! This will need to change if you are allowing users to select their own marks.
  while ((board->getValue(validInput) == "X" || board->getValue(validInput) == "O") || (validInput < 0 || validInput > 9))
  {
    std::cout << "Invalid move, Please try again: ";
    std::cin >> validInput;
  }
  return validInput;
}
