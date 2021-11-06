//
// Created by kshou on 2021/11/6.
//

#include "BlacklistListHandler.h"
#include "BlacklistHandler.h"
#include <iostream>

// constructor
BlacklistListHandler::BlacklistListHandler()
        : SubCommandHandler("Usage: blacklist list", "BlacklistHandler") {}

void BlacklistListHandler::handle_command() {
    // check if the blacklist is empty
    if (BlacklistHandler::blacklist.empty())
        std::cout << "Blacklist is empty." << std::endl;

        // otherwise, print the nameToAdd in the list line by line
    else
        for (const string &name: BlacklistHandler::blacklist)
            std::cout << name << std::endl;
}