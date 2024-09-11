//
// Created by Malik T on 08/09/2024.
//

#ifndef INFINITE_TYPES_H
#define INFINITE_TYPES_H
#include <inttypes.h>

#define BOOL uint8_t
#define TRUE 1
#define FALSE 0

#define LSHIFT(val, amnt) (val) << (amnt)
#define MAKEPIECE(sq) 1ULL << sq

#define INFINITE_DEBUG_MODE 0

#define INLINE static inline __attribute__((always_inline))

#if INFINITE_DEBUG_MODE
#else
#define NDEBUG
#endif
#include <assert.h>

typedef uint64_t BitBoard;
typedef uint8_t Square;
typedef uint64_t ZobKey;

typedef enum
{
    pt_wp = 0,
    pt_wb,
    pt_wn,
    pt_wr,
    pt_wk,
    pt_wq,
    pt_bp = 8,
    pt_bb,
    pt_bn,
    pt_br,
    pt_bk,
    pt_bq,
    pt_none
} PieceType;

typedef struct
{
    BitBoard white;
    BitBoard black;
    BitBoard pawns;
    BitBoard bishops;
    BitBoard knights;
    BitBoard rooks;
    BitBoard kings;
    BitBoard queens;
    PieceType pieces[64];
}Board;
//for things that can be forgotten about the state between moves
typedef struct
{
    uint8_t half_moves;
    uint8_t en_passant_sq;
    ZobKey zobrist_key;
    //pt_wk pt_wq pt_bk pt_bq
    uint8_t castling_right: 4;
}StateInfo;
typedef struct
{
    Board board;
    StateInfo* state_info;
    uint16_t full_moves;
    BOOL whites_turn;
}Position;
typedef enum
{
    Regular,
    Promotion,
    EnPassant,
    Castling
}MoveType;
typedef enum
{
    None = 0,
    Queen,
    Bishop,
    Knight,
    Rook,
}PromotionType;
typedef struct
{
    Square from : 6;
    Square to : 6;
    MoveType move_type;
    PromotionType prom_type;
} Move;

#endif //INFINITE_TYPES_H
