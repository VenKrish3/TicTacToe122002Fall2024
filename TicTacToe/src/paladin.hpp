#pragma once

#include <string>
#include "board.hpp"
#include "player.hpp"

class Paladin : public Player
{
private:
  Board *board;
  std::string mark;
  int validator(int);
  int selectOneOrTwo();

public:
  Paladin(Board *, std::string);
  std::string getMark() override;
  void move() override;
  void prompt() override;
};
