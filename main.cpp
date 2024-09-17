#include <iostream>

#include "board.hpp"
#include "rules.hpp"
#include "board_printer.hpp"

using namespace std;

int main() {
    Board board;
    Rules *rules = new Rules(&board);
    BoardPrinter *boardPrinter = new BoardPrinter(&board);
    cout << boardPrinter->print() << endl;

    bool inProgress = true;
    int userInput;

    while(inProgress) {
        cin >> userInput;
        board.move(userInput, "X");
        cout << boardPrinter->print() << endl;
    }
}