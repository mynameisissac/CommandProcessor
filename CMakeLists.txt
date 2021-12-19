cmake_minimum_required(VERSION 3.20)
project(CommandProcessor)

set(CMAKE_CXX_STANDARD 11)

add_executable(CommandProcessor
        src/main.cpp
        src/Processor.cpp include/Processor.h
        src/CommandHandler.cpp include/CommandHandler.h
        src/PingHandler.cpp include/PingHandler.h
        src/SayHandler.cpp include/SayHandler.h
        src/AddHandler.cpp include/AddHandler.h
        src/InvalidCommandHandler.cpp include/InvalidCommandHandler.h
        src/HelpHandler.cpp include/HelpHandler.h
        src/QuitHandler.cpp include/SubCommandHandler.h
        src/ListClearHandler.cpp include/QuitHandler.h
        src/BlacklistHandler.cpp include/ListHandler/BlacklistHandler.h
        src/ListAddHandler.cpp include/ListHandler/ListAddHandler.h
        src/SubCommandHandler.cpp include/ListHandler/ListClearHandler.h
        src/ListListHandler.cpp include/ListHandler/ListListHandler.h
        src/ListRemoveHandler.cpp include/ListHandler/ListRemoveHandler.h
        src/ListHandler.cpp include/ListHandler/ListHandler.h
        src/WhiteListHandler.cpp include/ListHandler/WhiteListHandler.h
        include/common.h
        src/ConfirmationHandler.cpp include/ConfirmationHandler.h)

