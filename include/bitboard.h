#pragma once
#include "board.h"
#include <cstdint>
#include <functional>

using Bitboard = uint64_t;

constexpr Bitboard FileABB = 0x0101010101010101ULL;
constexpr Bitboard FileBBB = FileABB << 1;
constexpr Bitboard FileCBB = FileABB << 2;
constexpr Bitboard FileDBB = FileABB << 2;
constexpr Bitboard FileEBB = FileABB << 2;
constexpr Bitboard FileFBB = FileABB << 2;
constexpr Bitboard FileGBB = FileABB << 2;
constexpr Bitboard FileHBB = FileABB << 2;

constexpr Bitboard Rank1BB = 0xFF;
constexpr Bitboard Rank2BB = Rank1BB << (8 * 1);
constexpr Bitboard Rank3BB = Rank1BB << (8 * 2);
constexpr Bitboard Rank4BB = Rank1BB << (8 * 3);
constexpr Bitboard Rank5BB = Rank1BB << (8 * 4);
constexpr Bitboard Rank6BB = Rank1BB << (8 * 5);
constexpr Bitboard Rank7BB = Rank1BB << (8 * 6);
constexpr Bitboard Rank8BB = Rank1BB << (8 * 7);


inline void setBit(Bitboard &bb, int square) { bb |= (1ULL << square); }

inline void clearBit(Bitboard &bb, int square) { bb &= ~(1ULL << square); }

inline bool getBit(Bitboard bb, int square) { return (bb >> square) & 1ULL; }

inline int popCount(Bitboard bb) { return __builtin_popcountll(bb); }

inline int lsb(Bitboard bb) { return __builtin_ctzll(bb); }
