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

    int userInput;

    while(rules->in_progress()) {
        cout << "Make your move!" << endl;
        cin >> userInput;
        board.move(userInput, "X");
        cout << boardPrinter->print() << endl;
    }
}