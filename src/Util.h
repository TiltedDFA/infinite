//
// Created by Malik T on 09/09/2024.
//

#ifndef INFINITE_UTIL_H
#define INFINITE_UTIL_H
#include "Types.h"
#include "Board.h"
#define PopLSB(x) ((x) & (x - 1))
#define FindLSB(x) ((x) ? __builtin_ctzll(x) : 0)

void util_print_board(Board *);
INLINE void util_print_pos(Position* pos)
{
    util_print_board(&pos->board);
}

#endif //INFINITE_UTIL_H
