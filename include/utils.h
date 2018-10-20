//
// Created by Remco on 10/11/2018.
//

#ifndef OZZY_UTILS_H
#define OZZY_UTILS_H


#pragma once

#include <cstdint>

class Utils {
public:
    Utils();

    static uint64_t getPower(int);

    static uint64_t getLSB(uint64_t);

    static uint64_t clearLSB(uint64_t);

    static uint64_t flipBitVertical(uint64_t);

    static uint64_t flip1BBVertical(uint64_t);

    static int getLS1B(uint64_t);

    ~Utils();

private:

};


#endif //OZZY_UTILS_H
