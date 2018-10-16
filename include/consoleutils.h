//
// Created by Remco on 10/11/2018.
//

#ifndef OZZY_CONSOLEUTILS_H
#define OZZY_CONSOLEUTILS_H


#pragma once

#include "piece.h"
#include "consolecolor.h"
#include "utils.h"
#include "move.h"
#include "board.h"
#include "movelist.h"
#include "flag.h"

class ConsoleUtils {
public:
    ConsoleUtils();
    static char getPieceChar(uint64_t, Board);
    static char getPromotion(int);
    static int getSquare(char, char);
    static char getRank(int);
    static char getFile(int);
    ~ConsoleUtils();
};


#endif //OZZY_CONSOLEUTILS_H
