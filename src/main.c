#include <stdio.h>
#include "Board.h"
#include "Position.h"

int main(void) {
    printf("Hello, World!\n");
    Position val = position_create();
    position_load_fen(&val, STARTING_FEN);
    position_destroy(&val);
    return 0;
}
