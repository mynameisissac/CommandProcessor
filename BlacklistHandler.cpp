//
// Created by kshou on 2021/11/5.
//

#include "BlacklistHandler.h"


// conversion constructor
BlacklistHandler::BlacklistHandler(const string &user_input)
        : InvalidCommandHandler(
        "Usage: blacklist add <nameToAdd>\nUsage: blacklist clear\nUsage: blacklist list\nUsage: blacklist remove <nameToAdd>",
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
    // substring the subCommand part (including the parameter)
    int posOfSpace1 = (int) user_input.find(' ');                              // the position of the first white space
    int posOfSpace2 = (int) user_input.find(' ', posOfSpace1 + 1);        // the position of the second white space
    string subCommand = user_input.substr(posOfSpace1 + 1);
    string subCommandName = user_input.substr(posOfSpace1 + 1, posOfSpace2 - posOfSpace1 - 1);
    if (subCommandName == "add") {                     // sub-command : add        NOLINT(bugprone-branch-clone)
        subCommandHandler = new BlacklistAddHandler(subCommand);
        return true;
    } else if (subCommandName == "clear") {            // sub-command : clear
        subCommandHandler = new BlacklistClearHandler();
        return true;
    } else if (subCommandName == "list") {             // sub-command : list
        subCommandHandler = new BlacklistListHandler();
        return true;
    } else if (subCommandName == "remove") {           // sub-command : remove
        subCommandHandler = new BlacklistRemoveHandler(subCommand);
        return true;
    }

    return false;
}

void BlacklistHandler::handle_command() {
    // print help_text if there is input error
    if (errorCode != 0)
        InvalidCommandHandler::handle_command();
    else
        // process the sub-command
        subCommandHandler->handle_command();
}


// destructor
BlacklistHandler::~BlacklistHandler() {
    // release memory
    delete subCommandHandler;
}