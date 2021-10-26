//
// Created by kshou on 2021/10/26.
//

#include "InvalidCommandHandler.h"
#include <iostream>

void InvalidCommandHandler::handle_command() {
    std::cout << help_text << std::endl;
}