//
// Created by Remco on 10/11/2018.
//

#ifndef OZZY_MOVE_H
#define OZZY_MOVE_H


#pragma once

#include <cstdint>
#include "piece.h"
#include "flag.h"

class Move {
public:
    Move();

    Move(uint64_t, uint64_t);

    Move(int, uint64_t, uint64_t, Flag);

    Move(int, uint64_t, uint64_t, Flag, int);

    int getPiece();

    uint64_t getFrom();

    uint64_t getTo();

    Flag getFlag();

    int getPromotion();

    bool operator==(const Move other);

    ~Move();

private:
    int piece;
    uint64_t from;
    uint64_t to;
    Flag flag;
    int promotion;
};

#endif //OZZY_MOVE_H
