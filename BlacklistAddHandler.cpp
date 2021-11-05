//
// Created by kshou on 2021/11/5.
//

#include "BlacklistAddHandler.h"
#include <iostream>


// constructor
BlacklistAddHandler::BlacklistAddHandler(const string &userInput)
        : SubCommandHandler("Usage: blacklist add <name>") {
    // check if the input is valid, and assign value to data member name
    errorCode = validateInput(userInput);

}

// validate the input, including checking if the parameter is input correctly
// return the errorCode
int
BlacklistAddHandler::validateInput(const string &userInput) { // NOLINT(readability-convert-member-functions-to-static)
    // substr the parameter part
    string parameter = userInput.substr(userInput.find(' ') + 1);
}

void BlacklistAddHandler::handle_command() {
    std::cout << "blacklist add is called" << std::endl;
}