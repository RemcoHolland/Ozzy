//
// Created by Remco on 10/11/2018.
//

#ifndef OZZY_GAME_H
#define OZZY_GAME_H


#pragma once

#include <string>
#include <list>
#include <algorithm>
#include "board.h"
#include "console.h"
#include "consoleutils.h"
#include "movelist.h"
#include "search.h"
#include "color.h"
#include "fenreader.h"
#include "feninfo.h"

class Game {

public:
    Game();

    void play();

    ~Game();

private:
    int color = WHITE;
    uint64_t nodes = 0;
    double searchTime = 0;
    std::clock_t startTime;
    int half_moves = 0;
    int full_moves = 0;

    void changeColor();

    Move getUserMove(string);

    Move getEngineMove(int, Board);

    bool isLegalMove(Movelist, Move);

    Move getLegalMove(Movelist, Move);

    bool endOfGame();

    void startClock();

    void stopClock();
};


#endif //OZZY_GAME_H
