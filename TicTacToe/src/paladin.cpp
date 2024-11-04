#include <iostream>
#include <string>
#include "ctype.h"


#include "paladin.hpp"

using namespace std;

Paladin::Paladin(Board *board, string mark)
{
  this->board = board;
  this->mark = mark;
}

string Paladin::getMark()
{
  return mark;
}

void Paladin::prompt()
{
	cout << "I am the paladin! " << endl;
	cout << "Do you want to..." << endl;
	cout << "(1) Make a move" << endl;
	cout << "(2) Use your special power to move a mark over" << endl;
}

int Paladin::selectOneOrTwo()
{
  int option;
  cin >> option;
  return option;
}

void Paladin::move()
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
	  cout << "choose your location: " << endl;
	  cin >> location;
	  int goodLocation = validator(location);

	  string movement;
	  cout << "which way do you want to push/move? (WASD): " << endl;
	  cin >> movement;
	  while(movement != "")
	  {
		  while(!isalpha((int)movement[0]) || movement.length() >= 2)
		  {
			  cout << "invalid move; ";
			  cin >> movement;
		  }
		  switch((int)(toupper(movement[0])))
		  {
		  	  cout << "it went through this" << endl;
	  	  	  case 87: // W
	  	  		  if((goodLocation-3) <= 0)
	  	  		  {
	  	  			  // player wants to move up at border
	  	  			  cout << "Invalid Move (can't push border) try again: " << endl;
	  	  			  cin >> movement;
	  	  			  cout << movement;
	  	  		  }
	  	  		  else if((goodLocation >= 4 && goodLocation <= 6) && (!isdigit((stoi(board->getValue(goodLocation-3))))))
	  	  		  {
	  	  			  // player wants to move other mark up but is in the middle
	  	  			 cout << "Invalid Move (can't squish other marks) try again: " << endl;
		  	  		 cin >> movement;
		  	  		 cout << movement;
	  	  		  }
	  	  		  else if(goodLocation > 6 && (!isdigit(stoi(board->getValue(goodLocation-6))) && !isdigit((stoi(board->getValue(goodLocation-3))))))
	  	  		  {
	  	  			  //player wants to move mark but both spaces above are occupied.
	  	  			 cout << "Invalid Move (can't move 2 units) try again: " << endl;
	  	  			 cin >> movement;
	  	  			 cout << movement;
	  	  		  }
	  	  		  else if(!isdigit((stoi(board->getValue(goodLocation-3)))))
	  	  		  {
	  	  			  //player is successful in getting to move a mark.
	  	  			  cout << "move successful!" << endl;
  	  			  	  goodLocation--;
			  		  board[goodLocation-6].move(goodLocation, board->getValue(goodLocation-3));
			  		  board[goodLocation-3].move(goodLocation, this->getMark());
	  	  			  board[goodLocation].move(goodLocation, to_string(goodLocation));
	  	  		  }
	  	  		  else
	  	  		  {
  	  			  	  goodLocation--;
	  	  			  cout << "move successful!" << endl;
	  	  			  board[goodLocation-3].move(goodLocation, this->getMark());
	  	  			  board[goodLocation].move(goodLocation, to_string(goodLocation));
	  	  		  }
	  	  		  break;

			  case 65:  // A
	  	  		  if(goodLocation == 1 || goodLocation == 4 || goodLocation == 7 )
	  	  		  {
	  	  			  // player wants to move left at border
	  	  			  cout << "Invalid Move (can't push border) try again: " << endl;
	  	  			  cin >> movement;
	  	  			  cout << movement;
	  	  		  }
	  	  		  else if((goodLocation == 2 || goodLocation == 5 || goodLocation == 8 ) && (!isdigit((stoi(board->getValue(goodLocation-1))))))
	  	  		  {
	  	  			  // player wants to move other mark left but is in the middle
	  	  			 cout << "Invalid Move (can't squish other marks) try again: " << endl;
		  	  		 cin >> movement;
		  	  		 cout << movement;
	  	  		  }
	  	  		  else if((goodLocation == 3 || goodLocation == 6 || goodLocation == 9) && (!isdigit(stoi(board->getValue(goodLocation-2))) && !isdigit((stoi(board->getValue(goodLocation-1))))))
	  	  		  {
	  	  			  //player wants to move mark but both spaces left are occupied.
	  	  			 cout << "Invalid Move (can't move 2 units) try again: " << endl;
	  	  			 cin >> movement;
	  	  			 cout << movement;
	  	  		  }
	  	  		  else if(!isdigit((stoi(board->getValue(goodLocation-1)))))
	  	  		  {
	  	  			  //player is successful in getting to move a mark.
	  	  			  cout << "move successful!" << endl;
  	  			  	  goodLocation--;
			  		  board[goodLocation-2].move(goodLocation, board->getValue(goodLocation-1));
			  		  board[goodLocation-1].move(goodLocation, this->getMark());
	  	  			  board[goodLocation].move(goodLocation, to_string(goodLocation));
	  	  		  }
	  	  		  else
	  	  		  {
	  	  			  cout << "move successful!" << endl;
	  	  			  board[goodLocation-1].move(goodLocation, this->getMark());
	  	  			  board[goodLocation].move(goodLocation, to_string(goodLocation));
	  	  		  }
	  	  		  break;

			  case 83: //  S
	  	  		  if((goodLocation + 3) > 9)
	  	  		  {
	  	  			  // player wants to move up at border
	  	  			  cout << "Invalid Move (can't push border) try again: " << endl;
	  	  			  cin >> movement;
	  	  			  cout << movement;
	  	  		  }
	  	  		  else if((goodLocation >= 4 && goodLocation <= 6) && (!isdigit((stoi(board->getValue(goodLocation+3))))))
	  	  		  {
	  	  			  // player wants to move other mark up but is in the middle
	  	  			 cout << "Invalid Move (can't squish other marks) try again: " << endl;
		  	  		 cin >> movement;
		  	  		 cout << movement;
	  	  		  }
	  	  		  else if(goodLocation < 6 && (!isdigit(stoi(board->getValue(goodLocation+6))) && !isdigit((stoi(board->getValue(goodLocation+3))))))
	  	  		  {
	  	  			  //player wants to move mark but both spaces above are occupied.
	  	  			 cout << "Invalid Move (can't move 2 units) try again: " << endl;
	  	  			 cin >> movement;
	  	  			 cout << movement;
	  	  		  }
	  	  		  else if(!isdigit((stoi(board->getValue(goodLocation+3)))))
	  	  		  {
	  	  			  //player is successful in getting to move a mark.
	  	  			  cout << "move successful!" << endl;
  	  			  	  goodLocation--;
			  		  board[goodLocation+6].move(goodLocation, board->getValue(goodLocation+3));
			  		  board[goodLocation+3].move(goodLocation, this->getMark());
	  	  			  board[goodLocation].move(goodLocation, to_string(goodLocation));
	  	  		  }
	  	  		  else
	  	  		  {
  	  			  	  goodLocation--;
	  	  			  cout << "move successful!" << endl;
	  	  			  board[goodLocation-3].move(goodLocation, this->getMark());
	  	  			  board[goodLocation].move(goodLocation, to_string(goodLocation));
	  	  		  }
	  	  		  break;

			  case 68: //  D
	  	  		  if(goodLocation == 3 || goodLocation == 6 || goodLocation == 9 )
	  	  		  {
	  	  			  // player wants to move left at border
	  	  			  cout << "Invalid Move (can't push border) try again: " << endl;
	  	  			  cin >> movement;
	  	  			  cout << movement;
	  	  		  }
	  	  		  else if((goodLocation == 2 || goodLocation == 5 || goodLocation == 8 ) && (!isdigit((stoi(board->getValue(goodLocation+1))))))
	  	  		  {
	  	  			  // player wants to move other mark left but is in the middle
	  	  			 cout << "Invalid Move (can't squish other marks) try again: " << endl;
		  	  		 cin >> movement;
		  	  		 cout << movement;
	  	  		  }
	  	  		  else if((goodLocation == 1 || goodLocation == 4 || goodLocation == 7) && (!isdigit(stoi(board->getValue(goodLocation+2))) && !isdigit((stoi(board->getValue(goodLocation+1))))))
	  	  		  {
	  	  			  //player wants to move mark but both spaces left are occupied.
	  	  			 cout << "Invalid Move (can't move 2 units) try again: " << endl;
	  	  			 cin >> movement;
	  	  			 cout << movement;
	  	  		  }
	  	  		  else if(!isdigit((stoi(board->getValue(goodLocation+1)))))
	  	  		  {
	  	  			  //player is successful in getting to move a mark.
	  	  			  cout << "move successful!" << endl;
  	  			  	  goodLocation--;
			  		  board[goodLocation+2].move(goodLocation, board->getValue(goodLocation+1));
			  		  board[goodLocation+1].move(goodLocation, this->getMark());
	  	  			  board[goodLocation].move(goodLocation, to_string(goodLocation));
	  	  		  }
	  	  		  else
	  	  		  {
	  	  			  cout << "move successful!" << endl;
	  	  			  board[goodLocation+1].move(goodLocation, this->getMark());
	  	  			  board[goodLocation].move(goodLocation, to_string(goodLocation));
	  	  		  }
	  	  		  break;

			  default:
				  cout << "it didn't work" << endl;
				  break;
		  }
	  }

  }
}

int Paladin::validator(int potentiallyInvalidInput)
{
  int validInput = potentiallyInvalidInput;

  // TODO: Be careful! This will need to change if you are allowing users to select their own marks.
  while((board->getValue(validInput) == this->getMark()) || (validInput < 0 || validInput > 9))
  {
    cout << "Invalid move, Please try again: ";
    cin >> validInput;
  }
  return validInput;
}
