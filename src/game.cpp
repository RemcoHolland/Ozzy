//
// Created by Remco on 10/11/2018.
//

#include "../include/game.h"


Game::Game() {
}

void Game::play() {

    FenInfo fenInfo = FenReader::read("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    color = fenInfo.getColor();
    half_moves = fenInfo.getHalfMoves();
    full_moves = fenInfo.getFullMoves();

    Board board = Board(fenInfo);
    bool illegalMove = false;

    while (!endOfGame()) {
        Console::printBoard(color, board, illegalMove);
        Console::printNodes(nodes, searchTime);

        Movelist movelist = Movelist();
        movelist.generateMoves(color, board);

        string input = Console::getUserInput(color, board);

        Move move;
        if (input == "e") {
            illegalMove = false;
            move = getEngineMove(color, board);
        } else {
            move = getUserMove(color, board, input);

            if (!isLegalMove(movelist, move)) {
                illegalMove = true;
                continue;
            }
            move = getLegalMove(movelist, move);
        }
        MoveInfo moveInfo = board.makeMove(color, move);
        if (Square::isAttacked(color, board, board.getPiece(color == WHITE ? WHITE_KING : BLACK_KING))) {
            board.unmakeMove(color, move, moveInfo);
            illegalMove = true;
            continue;
        }
        illegalMove = false;
        changeColor();
    }
}

void Game::changeColor() {
    color ^= 1;
}

Move Game::getUserMove(int side, Board board, string input) {
    uint64_t from, to;
    Move move;

    from = Utils::getPower(ConsoleUtils::getSquare(input[0], input[1]));
    to = Utils::getPower(ConsoleUtils::getSquare(input[2], input[3]));

    nodes = 0;
    move = Move(from, to);

    return move;
}

Move Game::getEngineMove(int side, Board board) {
    Search search = Search();

    startClock();
    Move move = search.getBestMove(side, board);
    stopClock();

    nodes = search.getNodes();
    return move;
}

bool Game::isLegalMove(Movelist movelist, Move move) {
    bool legal = false;
    if (movelist.containsMove(move)) {
        legal = true;
    }
    return legal;
}

Move Game::getLegalMove(Movelist movelist, Move user_move) {
    std::list<Move> moves = movelist.getMoves();
    for (std::list<Move>::iterator it = moves.begin(); it != moves.end(); ++it) {
        Move move = *it;
        if (move == user_move) {
            return move;
        }
    }
    return user_move;
}

bool Game::endOfGame() {
    return false;
}

void Game::startClock() {
    startTime = std::clock();
}

void Game::stopClock() {
    searchTime = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
}

Game::~Game() {
}
