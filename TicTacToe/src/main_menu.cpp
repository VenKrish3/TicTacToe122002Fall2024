#include <iostream>

#include "battle_tic_tac_toe.hpp"
#include "board.hpp"
#include "rules.hpp"
#include "tic_tac_toe.hpp"
#include "board_printer.hpp"
#include "main_menu.hpp"

#include "alchemist.hpp"
#include "paladin.hpp"

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

void MainMenu::start()
{
  printWelcomeMessage();
  buildAndPlayGame(selectOneOrTwo());
  printPlayAgainMessage();
  playAgainOrExit();
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
    int playerSelection;
    cout << "This might be a good time to allow each player to choose their marks!" << endl;
    cout << "But I am just going to hardcode X and O for now..." << endl;
    cout << "Also, helpful note for those of you reading this - be sure to update Peasant #validator to handle custom marks!" << endl;
    cout << "Choose your characters! (paladin = 1, alchemist = 2)" << endl;
    cout << "P1 is ... ";
    cin >> playerSelection;
    cout << "P1, pick your mark! " << endl;
    string markChosen;
    while(markChosen.length() >= 2 && (!isdigit(stoi(markChosen)) || markChosen == "/" || markChosen == "\\" || markChosen != " " || markChosen != "," || markChosen != "." || markChosen != ";" || markChosen != ":"))
    {
    	cout << "Sorry, that isn't allowed try again" << endl;
    	cin >> markChosen;
    }
    Player *playerOne;
	Player *playerTwo;
    if(playerSelection == 1)
    {
    	playerOne = new alchemist(board, markChosen);
    }
    else
    {
    	playerOne = new Paladin(board, "X");
    }
    cout << "P2 is ... ";
    cin >> playerSelection;
    cout << "P2, pick your mark! " << endl;
    while(markChosen.length() >= 2 && (!isdigit(stoi(markChosen)) || markChosen == "/" || markChosen == "\\" || markChosen != " " || markChosen != "," || markChosen != "." || markChosen != ";" || markChosen != ":"))
    {
    	cout << "Sorry, that isn't allowed try again" << endl;
    	cin >> markChosen;
    }
    if(playerSelection == 1)
    {
    	playerTwo = new alchemist(board, "X");
    }
    else
    {
    	playerTwo = new Paladin(board, "X");
    }

    BattleTicTacToe *battleTicTacToe = new BattleTicTacToe(rules, board, boardPrinter, playerOne, playerTwo);
    battleTicTacToe->start();
    delete battleTicTacToe;
    delete playerOne;
    delete playerTwo;
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
