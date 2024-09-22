#include <iostream>

#include "board.cpp"
#include "rules.cpp"
#include "game.cpp"
#include "board_printer.cpp"

using namespace std;

int main() {
    Board board;
    Rules *rules = new Rules(&board);
    BoardPrinter *boardPrinter = new BoardPrinter(&board);
    Game *game = new Game(rules, &board, boardPrinter);
    
    game->start();
}
