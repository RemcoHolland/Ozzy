//
// Created by Remco on 10/11/2018.
//

#ifndef OZZY_SEARCH_H
#define OZZY_SEARCH_H


#include <list>
#include "move.h"
#include "evaluation.h"
#include "color.h"
#include "movelist.h"
#include "square.h"
#include "moveinfo.h"

#pragma once
class Search {
public:
    Search();
    uint64_t getNodes();
    Move getBestMove(int, Board);
    ~Search();

private:
    const int MAX_INT = 999;
    const int SEARCH_DEPTH = 3;

    uint64_t nodes = 0;
    int negaMax(int, Board, int);
    Move bestMove;
};

#endif //OZZY_SEARCH_H
