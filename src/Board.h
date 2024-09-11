//
// Created by Malik T on 08/09/2024.
//

#ifndef INFINITE_BOARD_H
#define INFINITE_BOARD_H

#include "Types.h"
#include "Util.h"
#include "Zobrist.h"

#include <string.h>

void board_init(Board* b);
void board_put(Board*, PieceType, Square);
void board_rm(Board*, PieceType, Square);
BitBoard board_get_pieces(Board*, PieceType);
PieceType board_get_square(Board*, Square);
#endif //INFINITE_BOARD_H
