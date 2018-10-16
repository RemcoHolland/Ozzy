//
// Created by Remco on 10/11/2018.
//

#include "../include/moveinfo.h"


MoveInfo::MoveInfo(int captured_piece, uint64_t enpassant_square, int castling_rights) {
    MoveInfo::captured_piece = captured_piece;
    MoveInfo::enpassant_square = enpassant_square;
    MoveInfo::castling_rights = castling_rights;
}

MoveInfo::~MoveInfo() {
}

int MoveInfo::getCapturedPiece() {
    return captured_piece;
}

uint64_t MoveInfo::getEnpassantSquare() {
    return enpassant_square;
}

int MoveInfo::getCastlingRights() {
    return castling_rights;
}
