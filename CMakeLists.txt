cmake_minimum_required(VERSION 3.12)
project(Ozzy)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ozzy include/board.h src/console.cpp include/console.h include/castling.h include/color.h include/consolecolor.h src/consoleutils.cpp include/consoleutils.h src/evaluation.cpp include/evaluation.h src/feninfo.cpp include/feninfo.h src/fenreader.cpp include/fenreader.h include/flag.h src/game.cpp include/game.h src/generator.cpp include/generator.h src/move.cpp include/move.h src/moveinfo.cpp include/moveinfo.h src/movelist.cpp include/movelist.h src/ozzy.cpp include/ozzy.h src/perft.cpp include/perft.h include/piece.h src/search.cpp include/search.h src/square.cpp include/square.h src/utils.cpp include/utils.h src/magicmoves.cpp include/magicmoves.h src/board.cpp)