//
// Created by Remco on 10/11/2018.
//

#include "../include/consoleutils.h"

ConsoleUtils::ConsoleUtils() {
}

char ConsoleUtils::getPieceChar(uint64_t square, Board board) {
    char piece = ' ';
    if ((board.getPiece(WHITE_PAWN) & square) == square)
        piece = 'P';
    else if ((board.getPiece(WHITE_KNIGHT) & square) == square)
        piece = 'N';
    else if ((board.getPiece(WHITE_BISHOP) & square) == square)
        piece = 'B';
    else if ((board.getPiece(WHITE_ROOK) & square) == square)
        piece = 'R';
    else if ((board.getPiece(WHITE_QUEEN) & square) == square)
        piece = 'Q';
    else if ((board.getPiece(WHITE_KING) & square) == square)
        piece = 'K';
    else if ((board.getPiece(BLACK_PAWN) & square) == square)
        piece = 'p';
    else if ((board.getPiece(BLACK_KNIGHT) & square) == square)
        piece = 'n';
    else if ((board.getPiece(BLACK_BISHOP) & square) == square)
        piece = 'b';
    else if ((board.getPiece(BLACK_ROOK) & square) == square)
        piece = 'r';
    else if ((board.getPiece(BLACK_QUEEN) & square) == square)
        piece = 'q';
    else if ((board.getPiece(BLACK_KING) & square) == square)
        piece = 'k';
    return piece;
}

char ConsoleUtils::getPromotion(int piece) {
    char promotion = ' ';
    if (piece == WHITE_KNIGHT || piece == BLACK_KNIGHT)
        promotion = 'N';
    else if (piece == WHITE_BISHOP || piece == BLACK_BISHOP)
        promotion = 'B';
    if (piece == WHITE_ROOK || piece == BLACK_ROOK)
        promotion = 'R';
    else if (piece == WHITE_QUEEN || piece == BLACK_QUEEN)
        promotion = 'Q';
    return promotion;
}

int ConsoleUtils::getSquare(char file, char rank) {
    int square = (file - 97) + (rank - 49) * 8;	// 97 and 49 are ascii codes
    return square;
}

char ConsoleUtils::getRank(int square) {
    return (int)(square / 8) + 49;
}

char ConsoleUtils::getFile(int square) {
    return (int)(square % 8) + 97;;
}

ConsoleUtils::~ConsoleUtils() {
}