//
// Created by Malik T on 09/09/2024.
//
#include "Util.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char pt_to_char[] = {
        'P',
        'B',
        'N',
        'R',
        'K',
        'Q',
        '?',
        '?',
        'p',
        'b',
        'n',
        'r',
        'k',
        'q',
        '-'
};
void util_print_board(Board* board)
{
    printf("  a b c d e f g h\n");
    for (int rank = 0; rank < 8 ; ++rank)
    {
        printf("%d ", rank + 1);
        for (int file = 0; file < 8; ++file)
        {
            const int square = rank * 8 + file;
            const PieceType piece = board_get_square(board, square);
            printf("%c ", pt_to_char[piece]);
        }
        printf("%d\n", rank + 1);
    }
    printf("  a b c d e f g h\n");
}
