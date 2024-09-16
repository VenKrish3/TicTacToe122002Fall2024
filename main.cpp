#include <iostream>

#include "display_board.hpp"
#include "board.hpp"

using namespace std;

int main() {
    Board board;
    DisplayBoard *displayBoard = new DisplayBoard(&board);

    cout << displayBoard->generate();

    board.move(1, "X");

    cout << displayBoard->generate();

    board.move(3, "O");

    cout << displayBoard->generate();
}