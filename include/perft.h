//
// Created by Remco on 10/11/2018.
//

#ifndef OZZY_PERFT_H
#define OZZY_PERFT_H


#pragma once

#include <iostream>

#include "board.h"
#include "movelist.h"
#include "utils.h"
#include "consoleutils.h"

class Perft {
public:
    Perft(bool, int);

    uint64_t calculate(int, Board);

    ~Perft();

private:
    bool divide = false;
    uint64_t nodes = 0;
    uint64_t root_nodes = 0;
    int search_depth = 0;

    void negaMax(int, Board, int);

    void printRootNodes(Move);
};

#endif //OZZY_PERFT_H
