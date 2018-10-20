//
// Created by Remco on 10/11/2018.
//

#ifndef OZZY_FENREADER_H
#define OZZY_FENREADER_H


#pragma once

#include <string>
#include <cstdint>
#include "piece.h"
#include "utils.h"
#include "feninfo.h"
#include "color.h"
#include "castling.h"
#include "utils.h"
#include "consoleutils.h"

using std::string;

class FenReader {
public:
    FenReader();

    // c++ can't return an array, only return a pointer to the array
    static FenInfo read(string fen);

    ~FenReader();

private:
    static int getPiece(char);

    static int getCastlingRight(char);

    static uint64_t getEnpassantSquare(char, char);

    static int getNumber(char);
};

#endif //OZZY_FENREADER_H
