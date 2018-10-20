//
// Created by Remco on 10/11/2018.
//

#include "../include/fenreader.h"

FenReader::FenReader() {
}

FenInfo FenReader::read(string fen) {

    char white_space = ' ';

    uint64_t piece_list[TOTAL_PIECES] = {0};
    int color = 0;
    int castling_rights = 0;
    uint64_t enpassant_square = 0;
    int half_moves = 0;
    int full_moves = 0;

    unsigned int i = 0;

    int rank = 7;
    int file = 0;

    for (; i < fen.length(); i++) {

        if (fen[i] == '/') {
            rank--;
            file = 0;
        } else if (fen[i] >= 49 && fen[i] <= 56) {
            file += (fen[i] - 48);
        } else if (fen[i] == white_space) {
            i++;
            break;
        } else {
            int piece = getPiece(fen[i]);
            piece_list[piece] += Utils::getPower(rank * 8 + file);
            file++;
        }
    }

    for (; i < fen.length(); i++) {
        if (fen[i] == white_space) {
            i++;
            break;
        } else {
            fen[i] == 'w' ? color = WHITE : color = BLACK;
        }
    }

    for (; i < fen.length(); i++) {
        if (fen[i] == white_space) {
            i++;
            break;
        } else {
            castling_rights |= getCastlingRight(fen[i]);
        }
    }

    for (; i < fen.length(); i++) {
        if (fen[i] == white_space) {
            i++;
            break;
        } else {
            enpassant_square = getEnpassantSquare(fen[i], fen[i + 1]);
        }
    }

    for (; i < fen.length(); i++) {
        if (fen[i] == white_space) {
            i++;
            break;
        } else {
            half_moves = 10 * half_moves + getNumber(fen[i]);
        }
    }

    for (; i < fen.length(); i++) {
        if (fen[i] == white_space) {
            break;
        } else {
            full_moves = 10 * full_moves + getNumber(fen[i]);
        }
    }

    FenInfo fenInfo = FenInfo(piece_list, color, castling_rights, enpassant_square, half_moves, full_moves);

    return fenInfo;
}

FenReader::~FenReader() {
}

int FenReader::getPiece(char pieceChar) {
    int piece = NO_PIECE;
    if (pieceChar == 'P')
        piece = WHITE_PAWN;
    else if (pieceChar == 'N')
        piece = WHITE_KNIGHT;
    else if (pieceChar == 'B')
        piece = WHITE_BISHOP;
    else if (pieceChar == 'R')
        piece = WHITE_ROOK;
    else if (pieceChar == 'Q')
        piece = WHITE_QUEEN;
    else if (pieceChar == 'K')
        piece = WHITE_KING;
    else if (pieceChar == 'p')
        piece = BLACK_PAWN;
    else if (pieceChar == 'n')
        piece = BLACK_KNIGHT;
    else if (pieceChar == 'b')
        piece = BLACK_BISHOP;
    else if (pieceChar == 'r')
        piece = BLACK_ROOK;
    else if (pieceChar == 'q')
        piece = BLACK_QUEEN;
    else if (pieceChar == 'k')
        piece = BLACK_KING;
    return piece;
}

int FenReader::getCastlingRight(char castling_char) {
    int castling_right = 0;
    if (castling_char == 'K') {
        castling_right = KING_SIDE;
    } else if (castling_char == 'Q') {
        castling_right = QUEEN_SIDE;
    } else if (castling_char == 'k') {
        castling_right = KING_SIDE << BLACK;
    } else if (castling_char == 'q') {
        castling_right = QUEEN_SIDE << BLACK;
    }
    return castling_right;
}

uint64_t FenReader::getEnpassantSquare(char file, char rank) {
    uint64_t enpassant_square = 0;
    if (file != '-') {
        enpassant_square = Utils::getPower(ConsoleUtils::getSquare(file, rank));
    }
    return enpassant_square;
}

int FenReader::getNumber(char number) {
    return number - 48;
}