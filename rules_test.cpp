#include <cassert>
#include <iostream>

#include "board.hpp"
#include "rules.hpp"

using namespace std;

int main() {
    cout << "Starting the tests" << endl;

    Board board;
    Rules *rules = new Rules(&board);

    assert(rules->in_progress());

    board.move(1, "X");
    assert(rules->in_progress());

    board.move(2, "X");
    assert(rules->in_progress());

    board.move(3, "X");
    assert(!rules->in_progress());

    board.clear();

    board.move(1, "O");
    assert(rules->in_progress());

    board.move(2, "O");
    assert(rules->in_progress());

    board.move(3, "O");
    assert(!rules->in_progress());

    board.clear();

    board.move(1, "F");
    assert(rules->in_progress());

    board.move(4, "F");
    assert(rules->in_progress());

    board.move(7, "F");
    assert(!rules->in_progress());

    board.clear();

    board.move(2, "P");
    assert(rules->in_progress());

    board.move(5, "P");
    assert(rules->in_progress());

    board.move(8, "P");
    assert(!rules->in_progress());

    cout << "All of the tests passed!" << endl;
}