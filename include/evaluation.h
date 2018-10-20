//
// Created by Remco on 10/11/2018.
//

#ifndef OZZY_EVALUATION_H
#define OZZY_EVALUATION_H


#include "board.h"

#pragma once

class Evaluation {
public:
    Evaluation();

    int getScore(Board);

    ~Evaluation();

private:
    const int PAWN_VALUE = 1;
    const int KNIGHT_VALUE = 3;
    const int BISHOP_VALUE = 3;
    const int ROOK_VALUE = 5;
    const int QUEEN_VALUE = 9;
    const int KING_VALUE = 100;

    int materialScore(Board);

    int popCount(uint64_t);
};


#endif //OZZY_EVALUATION_H
