/*
 * PrinterForResults.cpp
 *
 *  Created on: Dec 12, 2024
 *      Author: Turbo
 */
#include "PrinterForResults.hpp"
#include <iostream>
#include <fstream>

using namespace std;

PrinterForResults::PrinterForResults(int p1Wins, int p2Wins)
{
	counterForP1+=p1Wins;
	counterForP2+=p2Wins;
}

void PrinterForResults::addP1()
{
	counterForP1++;
}
void PrinterForResults::addP2()
{
	counterForP2++;
}

void PrinterForResults::printer()
{
	fstream fileName("TicTacToeResults");
	if(fileName.is_open())
	{
		ofstream fileName2("TicTacToe results");
		fileName2 << "P1 wins: " << this->counterForP1 << "\n" << "P2 wins :" << this->counterForP2 << endl;
		fileName2.close();
	}
	else
	{
		ofstream fileName2("TicTacToe results (1)");
		fileName2 << "P1 wins: " <<  this->counterForP1 << "\n" << "P2 wins :" << this->counterForP2 << endl;
		fileName2.close();
	}
	fileName.close();
}

