cmake_minimum_required(VERSION 3.20)
project(CommandProcessor)

set(CMAKE_CXX_STANDARD 11)

add_executable(CommandProcessor main.cpp Processor.cpp Processor.h CommandHandler.cpp CommandHandler.h PingHandler.cpp PingHandler.h SayHandler.cpp SayHandler.h AddHandler.cpp AddHandler.h InvalidCommandHandler.cpp InvalidCommandHandler.h HelpHandler.cpp HelpHandler.h QuitHandler.cpp QuitHandler.h BlacklistHandler.cpp BlacklistHandler.h ListAddHandler.cpp ListAddHandler.h SubCommandHandler.cpp SubCommandHandler.h ListClearHandler.cpp ListClearHandler.h ListListHandler.cpp ListListHandler.h ListRemoveHandler.cpp ListRemoveHandler.h ListHandler.cpp ListHandler.h WhiteListHandler.cpp WhiteListHandler.h)

