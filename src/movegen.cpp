#include "../include/movegen.h"
#include "../include/bitboard.h"

std::vector<Move> generatePawnMoves(const Board &board) {
  std::vector<Move> moves;

  Bitboard pawns, singlePushes, doublePushes, leftCaptures, rightCaptures;
  Bitboard enemyPieces = board.occupancies[board.whiteToMove ? 1 : 0];
  Bitboard empty = ~board.occupancies[2];

  if (board.whiteToMove) {
    pawns = board.bitboards[W_PAWN];

    // single pushes
    singlePushes = (pawns << 8) & empty;
    while (singlePushes) {
      int to = lsb(singlePushes);
      int from = to - 8;
      moves.push_back({from, to, 0});
      clearBit(singlePushes, to);
    }

    // double pushes
    doublePushes = ((pawns & Rank2BB) << 16) & empty & (empty << 8);
    while (doublePushes) {
      int to = lsb(doublePushes);
      int from = to - 16;
      moves.push_back({from, to, 0});
      clearBit(doublePushes, to);
    }

    // left captures
    leftCaptures = (pawns << 7) & enemyPieces & ~FileABB;
    while (leftCaptures) {
      int to = lsb(leftCaptures);
      int from = to - 7;
      moves.push_back({from, to, 0});
      clearBit(leftCaptures, to);
    }

    // right captures
    rightCaptures = (pawns << 9) & enemyPieces & ~FileHBB;
    while (rightCaptures) {
      int to = lsb(rightCaptures);
      int from = to - 9;
      moves.push_back({from, to, 0});
      clearBit(rightCaptures, to);
    }
    
    // enpassant
    if (board.enpassant != SQ_NONE) {
      Square epSquare = Square(1ULL << board.enpassant); 
      Square epLeft = Square((pawns << 7) & epSquare & ~FileABB);
      Square epRight = Square((pawns << 9) & epSquare & ~FileHBB);
      
      if (epLeft) {
        int from = board.enpassant + 9;
        moves.push_back({from, board.enpassant, 0});
      }
      if (epRight) {
        int from = board.enpassant + 7;
        moves.push_back({from, board.enpassant, 0});
      }
    }
  }

  return moves;
}
