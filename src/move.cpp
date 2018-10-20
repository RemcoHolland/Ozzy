//
// Created by Remco on 10/11/2018.
//

#include "../include/move.h"

Move::Move() {
}

Move::Move(uint64_t from, uint64_t to) {
    Move::piece = NO_PIECE;
    Move::from = from;
    Move::to = to;
    Move::flag = Flag::NO_FLAG;
    Move::promotion = NO_PIECE;
}

Move::Move(int piece, uint64_t from, uint64_t to, Flag flag) {
    Move::piece = piece;
    Move::from = from;
    Move::to = to;
    Move::flag = flag;
    Move::promotion = NO_PIECE;
}

Move::Move(int piece, uint64_t from, uint64_t to, Flag flag, int promotion) {
    Move::piece = piece;
    Move::from = from;
    Move::to = to;
    Move::flag = flag;
    Move::promotion = promotion;
}

bool Move::operator==(const Move other) {
    return from == other.from && to == other.to;
}

int Move::getPiece() {
    return piece;
}

uint64_t Move::getFrom() {
    return from;
}

uint64_t Move::getTo() {
    return to;
}

Flag Move::getFlag() {
    return flag;
}

int Move::getPromotion() {
    return promotion;
}

Move::~Move() {
}