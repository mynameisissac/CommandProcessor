//
// Created by kshou on 2021/10/26.
//

#include "InvalidCommandHandler.h"
#include <iostream>
#include <utility>

/**
 * the conversion constructor
 * @param help_text a string object passed by value
 */
InvalidCommandHandler::InvalidCommandHandler(string help_text, int errorCode)
        : help_text(std::move(help_text)), errorCode(errorCode) {
}


void InvalidCommandHandler::handle_command() {
    std::cout << help_text << std::endl;
}