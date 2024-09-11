//
// Created by Malik T on 09/09/2024.
//
#include "Zobrist.h"

ZobKey ZOBRIST_PIECES[12][64];
ZobKey ZOBRIST_EP_KEYS[64];
ZobKey ZOBRIST_CASTLE_KEYS[16];
ZobKey ZOBRIST_SIDE_KEY;

void zobrist_init(void)
{
    for(int i = 0; i < 12; ++i)
    {
        for(int j = 0; j < 64; ++j)
        {
            ZOBRIST_PIECES[i][j] = RandomU64();
        }
    }
    for(int i = 0; i < 64; ++i)
    {
        ZOBRIST_EP_KEYS[i] = RandomU64();
    }
    for(int i = 0; i < 16; ++i)
    {
        ZOBRIST_CASTLE_KEYS[i] = RandomU64();
    }
    ZOBRIST_SIDE_KEY = RandomU64();
}
