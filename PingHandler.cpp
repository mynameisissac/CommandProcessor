//
// Created by kshou on 2021/10/26.
//

#include "PingHandler.h"
#include <iostream>

void PingHandler::handle_command() {
    std::cout << response_text << std::endl;
}


PingHandler::PingHandler()
        : InvalidCommandHandler("Usage: ping", 0) {}