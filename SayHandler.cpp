//
// Created by kshou on 2021/10/26.
//

#include "SayHandler.h"
#include <iostream>

void SayHandler::handle_command() {
    std::cout << response_text << std::endl;
}


// constructor that initialize the response_text
SayHandler::SayHandler(const string &user_input)
        : response_text(user_input.substr(4)) {
}

