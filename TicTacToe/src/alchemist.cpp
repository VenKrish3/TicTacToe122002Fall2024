#include <iostream>

#include "alchemist.hpp"

using namespace std;

alchemist::alchemist(Board *board, std::string mark)
{
  this->board = board;
  this->mark = mark;
}

std::string alchemist::getMark()
{
  return mark;
}

void alchemist::prompt()
{
	cout << "I am the alchemist!" << endl;
	cout << "You think you can beat me? Unlikely!" << endl;
	cout << "(1) Make a move" << endl;
	cout << "(2) Use your special power to move a mark over" << endl;
}

int alchemist::selectOneOrTwo()
{
  int option;
  cin >> option;
  return option;
}

void alchemist::move()
{
	  if (selectOneOrTwo() == 1)
	  {
	    cout << "Enter a move!" << endl;
	    int userInput;
	    cin >> userInput;
	    int validInput = this->validator(userInput);
	    board->move(validInput, this->mark);
	  }
	  else
	  {
		  int location;
		  cout << "choose your initial location: " << endl;
		  cin >> location;
		  validator(stoi(board->getValue(location)));

		  int secondLocation;
		  cout << "choose your second location: " << endl;
		  cin >> secondLocation;
		  validator(stoi(board->getValue(secondLocation)));

		  while(board->getValue(secondLocation) == this->getMark())
		  {
			  cout << "can't swap with own mark, choose second location again: " << endl;
			  cin >> secondLocation;
		  }

		  cout << "swapped!" << endl;
		  string temp = board->getValue(secondLocation);
		  board->move(secondLocation, this->mark);
		  board->move(location,temp);
	  }
}

int alchemist::validator(int potentiallyInvalidInput)
{
  int validInput = potentiallyInvalidInput;

  // TODO: Be careful! This will need to change if you are allowing users to select their own marks.
  while (validInput < 0 || validInput > 9)
  {
    std::cout << "Invalid move, Please try again: ";
    std::cin >> validInput;
  }
  return validInput;
}
