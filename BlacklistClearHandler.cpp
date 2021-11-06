//
// Created by kshou on 2021/11/6.
//

#include "BlacklistClearHandler.h"
#include "BlacklistHandler.h"
#include <iostream>

// constructor
BlacklistClearHandler::BlacklistClearHandler()
        : SubCommandHandler("Usage: blacklist clear", "BlacklistHandler") {}


void BlacklistClearHandler::handle_command() {
    // clear the blacklist
    BlacklistHandler::blacklist.clear();
    std::cout << "Blacklist cleared." << std::endl;
}