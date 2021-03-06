//
// Created by Remco on 10/11/2018.
//

#include "../include/evaluation.h"

Evaluation::Evaluation() {
}

int Evaluation::getScore(Board board) {
    return materialScore(board);
}

Evaluation::~Evaluation() {
}

int Evaluation::materialScore(Board board) {
    return
            popCount(board.getPiece(WHITE_PAWN)) * PAWN_VALUE +
            popCount(board.getPiece(WHITE_KNIGHT)) * KNIGHT_VALUE +
            popCount(board.getPiece(WHITE_BISHOP)) * BISHOP_VALUE +
            popCount(board.getPiece(WHITE_ROOK)) * ROOK_VALUE +
            popCount(board.getPiece(WHITE_QUEEN)) * QUEEN_VALUE +
            popCount(board.getPiece(WHITE_KING)) * KING_VALUE -
            (popCount(board.getPiece(BLACK_PAWN)) * PAWN_VALUE +
             popCount(board.getPiece(BLACK_KNIGHT)) * KNIGHT_VALUE +
             popCount(board.getPiece(BLACK_BISHOP)) * BISHOP_VALUE +
             popCount(board.getPiece(BLACK_ROOK)) * ROOK_VALUE +
             popCount(board.getPiece(BLACK_QUEEN)) * QUEEN_VALUE +
             popCount(board.getPiece(BLACK_KING)) * KING_VALUE);
}

int Evaluation::popCount(uint64_t pieces) {
    int count = 0;
    while (pieces) {
        count++;
        pieces &= pieces - 1; // reset LS1B
    }
    return count;
}