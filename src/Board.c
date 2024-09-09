#include "Board.h"

//
// Created by Malik T on 08/09/2024.
//
typedef struct
{
    BitBoard* colour;
    BitBoard* pieces;
} BoardAccessors;
INLINE BoardAccessors strip_board(Board* b, PieceType pt)
{
    const BoardAccessors ret = {.colour = (uint64_t*)b + (pt & 8), .pieces = ((uint64_t*)b + 2) + (pt & ~8)};
    return ret;
}
void board_init(Board* b)
{
    memset(b, 0, sizeof(Board));
}
void board_put(Board* b, PieceType pt, Square sq)
{
    const BoardAccessors ba = strip_board(b, pt);

    *(ba.colour) |= MAKEPIECE(sq);
    *(ba.pieces) |= MAKEPIECE(sq);
}
void board_rm(Board* b, PieceType pt, Square sq)
{
    const BoardAccessors ba = strip_board(b, pt);

    assert(!(*ba.colour & MAKEPIECE(sq)));
    assert(!(*ba.pieces & MAKEPIECE(sq)));

    *(ba.colour) ^= MAKEPIECE(sq);
    *(ba.pieces) ^= MAKEPIECE(sq);
}
BitBoard board_get_pieces(Board* b, PieceType pt)
{
    const BoardAccessors ba = strip_board(b, pt);
    return *(ba.colour) & *(ba.pieces);
}