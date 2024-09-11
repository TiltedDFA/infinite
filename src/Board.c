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
    const BoardAccessors ret = {.colour = (uint64_t*)b + ((pt & 8)>>3), .pieces = ((uint64_t*)b + 2) + (pt & ~8)};
    return ret;
}
void board_init(Board* b)
{
    memset(b, 0, sizeof(Board));
    for(int i = 0; i < 64; ++i) b->pieces[i] = pt_none;
}
void board_put(Board* b, PieceType pt, Square sq)
{
    const BoardAccessors ba = strip_board(b, pt);
    b->pieces[sq] = pt;
    *(ba.colour) |= MAKEPIECE(sq);
    *(ba.pieces) |= MAKEPIECE(sq);
}
void board_rm(Board* b, PieceType pt, Square sq)
{
    const BoardAccessors ba = strip_board(b, pt);

    assert(b->pieces[sq] != pt_none);

    b->pieces[sq] = pt_none;
    *(ba.colour) ^= MAKEPIECE(sq);
    *(ba.pieces) ^= MAKEPIECE(sq);

}
BitBoard board_get_pieces(Board* b, PieceType pt)
{
    const BoardAccessors ba = strip_board(b, pt);
    return *(ba.colour) & *(ba.pieces);
}
inline PieceType board_get_square(Board* b, Square sq)
{
    return b->pieces[sq];
}
