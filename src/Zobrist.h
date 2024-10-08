//
// Created by Malik T on 09/09/2024.
//

#ifndef INFINITE_ZOBRIST_H
#define INFINITE_ZOBRIST_H
#include "Types.h"
#include "Random.h"

extern ZobKey ZOBRIST_PIECES[12][64];
extern ZobKey ZOBRIST_EP_KEYS[64];
extern ZobKey ZOBRIST_CASTLE_KEYS[16];
extern ZobKey ZOBRIST_SIDE_KEY;

void zobrist_init(void);
ZobKey zobrist_from_board(Board*);
#endif //INFINITE_ZOBRIST_H
