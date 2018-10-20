//
// Created by Remco on 10/11/2018.
//

#include "../include/search.h"


Search::Search() {
}

int counter = 0;

uint64_t Search::getNodes() {
    return nodes;
}

Move Search::getBestMove(int color, Board board) {
    negaMax(color, board, SEARCH_DEPTH);
    return bestMove;
}

//Improvement: make a root negaMax, see chess programming network.
int Search::negaMax(int color, Board board, int depth) {
    if (depth == 0) {
        nodes++;
        Evaluation evaluation = Evaluation();
        // -color | 1 changes to 1 or -1 when color is either 0 or 1
        return (-color | 1) * evaluation.getScore(board);
    }
    int max = -MAX_INT;
    Movelist movelist = Movelist();
    movelist.generateMoves(color, board);
    std::list<Move> moves = movelist.getMoves();

    for (std::list<Move>::iterator it = moves.begin(); it != moves.end(); ++it) {
        Move move = *it;

        MoveInfo moveInfo = board.makeMove(color, move);

        if (!Square::isAttacked(color, board, board.getPiece(color == WHITE ? WHITE_KING : BLACK_KING))) {
            int score = -negaMax(color ^ 1, board, depth - 1);
            if (score > max) {
                max = score;
                if (depth == SEARCH_DEPTH) {
                    bestMove = move;
                }
            }
        }
        board.unmakeMove(color, move, moveInfo);
    }
    return max;
}

Search::~Search() {
}
