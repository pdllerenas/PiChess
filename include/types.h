#pragma once
#include <cstdlib>


enum Direction : int8_t {
  NORTH = 8,
  EAST = 1,
  SOUTH = -NORTH,
  WEST = -EAST,

  NORTH_EAST = NORTH + EAST,
  SOUTH_EAST = SOUTH + EAST,
  SOUTH_WEST = SOUTH + WEST, 
  NORTH_WEST = NORTH + WEST
};


enum Rank : int8_t {
  RANK_1,
  RANK_2, 
  RANK_3,
  RANK_4,
  RANK_5,
  RANK_6,
  RANK_7,
  RANK_8,
  RANK_NB
};


enum File : int8_t {
  FILE_1,
  FILE_2,
  FILE_3,
  FILE_4,
  FILE_5,
  FILE_6,
  FILE_7,
  FILE_8,
  FILE_NB
};


enum PieceType : int8_t {
  NO_PIECE_TYPE, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING 
};


enum Color : int8_t {
  WHITE, BLACK, COLOR_NB = 2
};

