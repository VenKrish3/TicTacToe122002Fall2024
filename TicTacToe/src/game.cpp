/*#include <iostream>

#include "game.hpp" 

Game::Game(Rules *rules, Board *board, BoardPrinter *boardPrinter) {
    this->rules = rules;
    this->board = board;
    this->boardPrinter = boardPrinter;
}

void Game::start() {
    int userInput;
    cout << boardPrinter->print() << endl;
    while(this->rules->inProgress()) {
        cout << "Make your move!" << endl;
        cin >> userInput;
        int validInput = rules->validator(userInput);
        board->move(validInput, this->getCurrentMark());
        cout << boardPrinter->print() << endl;
        this->toggleMark();
    }

    cout << rules->status() << endl;
}

void Game::toggleMark() {
    if(this->currentMark == "X") {
        this->currentMark = "O";
    } else {
        this->currentMark = "X";
    }
}

string Game::getCurrentMark() {
    return this->currentMark;
}
*/
