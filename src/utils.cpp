//
// Created by Remco on 10/11/2018.
//

#include "../include/utils.h"


const uint64_t power[64] =
        {
                1U, 2U, 4U, 8U, 16U, 32U, 64U, 128U,
                256U, 512U, 1024U, 2048U, 4096U, 8192U, 16384U, 32768U,
                65536U, 131072U, 262144U, 524288U, 1048576U, 2097152U, 4194304U, 8388608U,
                16777216U, 33554432U, 67108864U, 134217728U, 268435456U, 536870912U, 1073741824U, 2147483648U,
                4294967296U, 8589934592U, 17179869184U, 34359738368U, 68719476736U, 137438953472U, 274877906944U, 549755813888U,
                1099511627776U, 2199023255552U, 4398046511104U, 8796093022208U, 17592186044416U, 35184372088832U, 70368744177664U, 140737488355328U,
                281474976710656U, 562949953421312U, 1125899906842624U, 2251799813685248U, 4503599627370496U, 9007199254740992U, 18014398509481984U, 36028797018963968U,
                72057594037927936U, 144115188075855872U, 288230376151711744U, 576460752303423488U, 1152921504606846976U, 2305843009213693952U, 4611686018427387904U, 9223372036854775808U
        };

const int index64[64] = {
        0, 47, 1, 56, 48, 27, 2, 60,
        57, 49, 41, 37, 28, 16, 3, 61,
        54, 58, 35, 52, 50, 42, 21, 44,
        38, 32, 29, 23, 17, 11, 4, 62,
        46, 55, 26, 59, 40, 36, 15, 53,
        34, 51, 20, 43, 31, 22, 10, 45,
        25, 39, 14, 33, 19, 30, 9, 24,
        13, 18, 8, 12, 7, 6, 5, 63
};

Utils::Utils() {
}

uint64_t Utils::getPower(int exp) {
    return power[exp];
}

uint64_t Utils::getLSB(uint64_t bb) {
    return bb & (0 - bb);
}

uint64_t Utils::clearLSB(uint64_t bb) {
    return bb & (bb - 1);
}

uint64_t Utils::flipBitVertical(uint64_t bit) {
    return bit ^ 56;
}

uint64_t Utils::flip1BBVertical(uint64_t bb) {
    const uint64_t k1 = uint64_t(0x00FF00FF00FF00FF);
    const uint64_t k2 = uint64_t(0x0000FFFF0000FFFF);
    bb = ((bb >> 8) & k1) | ((bb & k1) << 8);
    bb = ((bb >> 16) & k2) | ((bb & k2) << 16);
    bb = (bb >> 32) | (bb << 32);
    return bb;
}

/**
* getLS1B
* @author Kim Walisch (2012)
* @param squares bitboard to scan
* @precondition bb != 0
* @return index (0..63) of least significant one bit
*/
int Utils::getLS1B(uint64_t bb) {
    const uint64_t debruijn64 = uint64_t(0x03f79d71b4cb0a89);
    return index64[((bb ^ (bb - 1)) * debruijn64) >> 58];
}

Utils::~Utils() {
}