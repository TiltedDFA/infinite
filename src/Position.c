//
// Created by Malik T on 08/09/2024.
//
#include "Position.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

inline Position position_create(void)
{
    Position p;
    p.state_info = (StateInfo*) malloc(sizeof(StateInfo));
    board_init(&(p.board));

    return p;
}
void position_destroy(Position* p)
{
    free(p->state_info);
}
void position_clear(Position* p)
{
    board_init(&(p->board));
    p->state_info->castling_right = 0;
    p->state_info->en_passant_sq = 0;
    p->state_info->half_moves = 0;
    p->state_info->zobrist_key = 0;
    p->whites_turn = 0;
    p->full_moves = 0;
}
const PieceType CHAR_TO_PIECE[] = {
        ['P'] = pt_wp,
        ['N'] = pt_wn,
        ['B'] = pt_wb,
        ['R'] = pt_wr,
        ['Q'] = pt_wq,
        ['K'] = pt_wk,
        ['p'] = pt_bp,
        ['n'] = pt_bn,
        ['b'] = pt_bb,
        ['r'] = pt_br,
        ['q'] = pt_bq,
        ['k'] = pt_bk,
};
ZobKey position_make_zob_key(Position* pos)
{
    ZobKey ret = 0ULL;
    for (PieceType t = pt_wp; t <= pt_wq; ++t) {
        BitBoard pieces = board_get_pieces(&pos->board, t);
        while (pieces) {
            ret ^= ZOBRIST_PIECES[t][FindLSB(pieces)];
            pieces = PopLSB(pieces);
        }
    }
    for (PieceType t = pt_bp; t <= pt_bq; ++t) {
        BitBoard pieces = board_get_pieces(&pos->board, t);
        while (pieces) {
            ret ^= ZOBRIST_PIECES[t - 2][FindLSB(pieces)];
            pieces = PopLSB(pieces);
        }
    }
    if(pos->state_info->en_passant_sq)
        ret ^= ZOBRIST_EP_KEYS[pos->state_info->en_passant_sq];

    ret ^= ZOBRIST_SIDE_KEY * pos->whites_turn;
    return ret;
}
INLINE PieceType CharToPieceType(const char c)
{
    assert((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    return CHAR_TO_PIECE[(int)c];
}
void position_load_fen(Position* p, char* fen)
{
    position_clear(p);

    for(int i = 0; i < 64; ++i)
    {
        if(*fen == '/')
        {
            --i;
        }
        else if(*fen >= '0' && *fen <= '9')
        {
            i += *fen - '1';
        }
        else if ((*fen >= 'a' && *fen <= 'z') || (*fen >= 'A' && *fen <= 'Z'))
        {
            board_put(&(p->board), CharToPieceType(*fen), i);
        }
        ++fen;
    }
    ++fen;
    p->whites_turn = (*fen++ == 'w' ? TRUE : FALSE);

    while(*(++fen) != ' ')
    {
        switch (*fen)
        {
            case 'K': p->state_info->castling_right |= 8; break;
            case 'Q': p->state_info->castling_right |= 4; break;
            case 'k': p->state_info->castling_right |= 2; break;
            case 'q': p->state_info->castling_right |= 1; break;
        }
    }
    if(*fen == '-')
    {
        p->state_info->en_passant_sq = 0;
    }
    else
    {
        const int file = *fen++ - 'a';
        const int row = *fen++ - '0';
        p->state_info->en_passant_sq = row * 8 + file;
    }

    while (*fen && *fen != ' ') fen++;
    sscanf(fen, " %hu %s", &p->full_moves, &p->state_info->half_moves);

}