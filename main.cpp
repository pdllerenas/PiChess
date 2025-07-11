#include "include/board.h"
#include "include/movegen.h"
#include <iostream>

int main() {
  Board board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  auto moves = generatePawnMoves(board);
  for (auto &m : moves) {
    std::cout << "From: " << m.from << "To: " << m.to << std::endl;
  }
	return 0;
}


