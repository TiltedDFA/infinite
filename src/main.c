#include <stdio.h>
#include "Board.h"
#include "Position.h"
#include "Util.h"
#include "Zobrist.h"

int main(void) {
    zobrist_init();
    printf("Hello, World!\n");
    Position val = position_create();
    position_load_fen(&val, STARTING_FEN);
    util_print_pos(&val);
    position_load_fen(&val, KIWIPETE);
    util_print_pos(&val);
    position_load_fen(&val, PERFTPOS3);
    util_print_pos(&val);
    position_load_fen(&val, PERFTPOS4);
    util_print_pos(&val);
    position_destroy(&val);
    return 0;
}
