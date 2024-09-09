//
// Created by Malik T on 08/09/2024.
//

#ifndef INFINITE_POSITION_H
#define INFINITE_POSITION_H
#include "Types.h"
#include "Board.h"

#define STARTING_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

Position position_create(void);
void position_destroy(Position*);
void position_clear(Position*);
void position_load_fen(Position*, char*);
#endif //INFINITE_POSITION_H
