//
// Created by Malik T on 08/09/2024.
//

#ifndef INFINITE_POSITION_H
#define INFINITE_POSITION_H
#include "Types.h"
#include "Board.h"

#define STARTING_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
#define KIWIPETE "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -"
#define PERFTPOS3 "8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - -"
#define PERFTPOS4 "r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1"
#define PERFTPOS5 "rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8"
#define PERFTPOS6 "r4rk1/1pp1qppp/p1np1n2/2b1p1B1/2B1P1b1/P1NP1N2/1PP1QPPP/R4RK1 w - - 0 10"
#define TRICKYENDGAMEPOS "8/k7/3p4/p2P1p2/P2P1P2/8/8/K7 w - - 0 1"

Position position_create(void);
void position_destroy(Position*);
void position_clear(Position*);
ZobKey position_make_zob_key(Position* pos);
void position_make_move(Position*, Move);
void position_load_fen(Position*, char*);
#endif //INFINITE_POSITION_H
