#pragma once

#include "board.h"
#include <vector>
#include <cstdint>

struct Move {
  int from;
  int to;
  int promotion;
};

std::vector<Move> generatePawnMoves(const Board &board);
