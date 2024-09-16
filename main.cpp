#include <iostream>

#include "board.hpp"
#include "board_printer.hpp"

using namespace std;

int main() {
    Board board;
    BoardPrinter *boardPrinter = new BoardPrinter(&board);
    cout << boardPrinter->print() << endl;

    bool endOfGame = false;
    int userInput;

    while(!endOfGame) {
        cin >> userInput;
        board.move(userInput, "X");
        cout << boardPrinter->print() << endl;
    }
}