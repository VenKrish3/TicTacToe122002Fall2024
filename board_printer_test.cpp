#include <cassert>

#include "board.cpp"
#include "board_printer.cpp"

int main() {
    Board board;
    BoardPrinter *boardPrinter = new BoardPrinter(&board);
    
    assert(boardPrinter->print() == " 1 | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 ");

    board.move(1, "X");
    assert(boardPrinter->print() == " X | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 ");

    board.move(2, "O");
    assert(boardPrinter->print() == " X | O | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 ");

    board.move(3, "W");
    assert(boardPrinter->print() == " X | O | W \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 ");
}
