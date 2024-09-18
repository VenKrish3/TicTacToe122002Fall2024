#include <iostream>

#include "board.cpp"
#include "rules.cpp"
#include "board_printer.cpp"

using namespace std;

int main() {
    Board board;
    Rules *rules = new Rules(&board);
    BoardPrinter *boardPrinter = new BoardPrinter(&board);
    cout << boardPrinter->print() << endl;

    int userInput;

    while(rules->inProgress()) {
        cout << "Make your move!" << endl;
        
        userInput = rules->validator(cin);
        board.move(userInput, rules->currentTurn());
        cout << boardPrinter->print() << endl;
    }

    cout << rules->status() << " wins the game!" << endl;
}
