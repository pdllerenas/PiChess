#include "../include/board.h"
#include "../include/bitboard.h"
#include <cstddef>
#include <iostream>

void Board::loadFEN(const std::string &fen) {
  std::fill(std::begin(bitboards), std::end(bitboards), 0ULL);

  std::fill(std::begin(occupancies), std::end(occupancies), 0ULL);

  size_t pos = 0;
  int sq = 56;

  for (; pos < fen.size(); ++pos) {
    char c = fen[pos];
    if (c == ' ')
      break;
    if (c == '/') {
      sq -= 16;
      continue;
    }
    if (isdigit(c)) {
      sq += c - '0';
      continue;
    }
    if (sq == 0 && c == 'w') {
      whiteToMove = true;
    }
    Piece piece = NO_PIECE;
    switch (c) {
      case 'P': piece = W_PAWN; break;
      case 'N': piece = W_KNIGHT; break;
      case 'B': piece = W_BISHOP; break;
      case 'R': piece = W_ROOK; break;
      case 'Q': piece = W_QUEEN; break;
      case 'K': piece = W_KING; break;
      case 'p': piece = B_PAWN; break;
      case 'n': piece = B_KNIGHT; break;
      case 'b': piece = B_BISHOP; break;
      case 'r': piece = B_ROOK; break;
      case 'q': piece = B_QUEEN; break;
      case 'k': piece = B_KING; break;
    }
    if (piece != NO_PIECE) {
      setBit(bitboards[piece], sq);
    }
    sq++;
  }
  ++pos;
  whiteToMove = (fen[pos] == 'w');

  ++pos;
  if (fen[pos] == '-') {
    pos++;
  }
  else {
    while (fen[pos] != ' ') {
      switch (fen[pos]) {
        case 'K': 
          castling |= (1 << 0); break;
        case 'Q':
          castling |= (1 << 1); break;
        case 'k':
          castling |= (1 << 2); break;
        case 'q':
          castling |= (1 << 3); break;
      }
    }
  }

  ++pos;
  if (fen[pos] == '-') {
    enpassant = SQ_NONE;
    pos++;
  }
  else {
    int file = fen[pos] - 'a';
    int rank = fen[pos + 1] - '1';
    enpassant = (Square)(rank * 8 + file);
    pos += 2;
  }
  ++pos;

}
