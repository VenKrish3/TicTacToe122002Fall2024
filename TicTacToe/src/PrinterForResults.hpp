/*
 * PrinterForResults.hpp
 *
 *  Created on: Dec 12, 2024
 *      Author: Turbo
 */

#ifndef PRINTERFORRESULTS_HPP_
#define PRINTERFORRESULTS_HPP_
#include <string>

using namespace std;

class PrinterForResults
{
private:
	int counterForP1, counterForP2;
public:
	PrinterForResults(int, int);
	int getP1Wins();
	int getP2Wins();
	void printer();
};

#endif /* PRINTERFORRESULTS_HPP_ */
