//
// Created by kshou on 2021/11/5.
//

#include "BlacklistHandler.h"
#include "BlacklistAddHandler.h"

// conversion constructor
BlacklistHandler::BlacklistHandler(const string &user_input)
        : InvalidCommandHandler(
        "Usage: blacklist add <name>\nUsage: blacklist clear\nUsage: blacklist list\nUsage: blacklist remove <name>",
        0), subCommandHandler(nullptr) {
    // if the user_input is invalid, assign errorCode to be 1
    if (!validateInput(user_input))
        errorCode = 1;

}

// check if the user input is valid and
// assign the correct handler to subCommandHandler if the input is valid
bool
BlacklistHandler::validateInput(const string &user_input)  // NOLINT(readability-convert-member-functions-to-static)
{
    string subCommand;
    subCommand = user_input.substr(user_input.find(' ') + 1);
    if (subCommand.substr(0, 3) == "add") {
        subCommandHandler = new BlacklistAddHandler();
        return true;
    } else if (subCommand.substr(0, 5) == "clear") {
        subCommandHandler;
        return true;
    } else if (subCommand.substr(0, 4) == "list") {
        subCommandHandler;
        return true;
    } else if (subCommand.substr(0, 6) == "remove") {
        subCommandHandler;
        return true;
    }

    return false;
}


void BlacklistHandler::handle_command() {
    // print help_text if there is input error
    if (errorCode != 0)
        InvalidCommandHandler::handle_command();
    else {
        return;
    }

}