//
// Created by Remco on 10/11/2018.
//

#ifndef OZZY_CONSOLE_H
#define OZZY_CONSOLE_H


#pragma once

#include <iostream>
#include <string>
#include <regex>

#include "consolecolor.h"
#include "consoleutils.h"
#include "perft.h"

using std::string;

class Console {
public:
    Console();
    static void printBoard(int, Board, bool);
    static void printNodes(uint64_t, double);
    static string getUserInput(int, Board);
    ~Console();

private:
    static bool isValidInput(string);
    static void calculatePerft(bool, int, Board, string);
};


#endif //OZZY_CONSOLE_H
