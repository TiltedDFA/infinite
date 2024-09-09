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
        ['P'] = wp,
        ['N'] = wn,
        ['B'] = wb,
        ['R'] = wr,
        ['Q'] = wq,
        ['K'] = wk,
        ['p'] = bp,
        ['n'] = bn,
        ['b'] = bb,
        ['r'] = br,
        ['q'] = bq,
        ['k'] = bk,
};

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