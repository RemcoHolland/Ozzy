//
// Created by Remco on 10/11/2018.
//

#ifndef OZZY_SQUARE_H
#define OZZY_SQUARE_H


#pragma once
#include "color.h"
#include "board.h"
#include "magicmoves.h"
#include "utils.h"
#include "piece.h"

class Square {
public:
    Square();
    static bool isAttacked(int, Board, uint64_t);
    ~Square();
};


#endif //OZZY_SQUARE_H
