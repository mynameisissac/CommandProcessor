//
// Created by kshou on 2021/11/13.
//

#include "WhiteListHandler.h"


// conversion constructor
WhiteListHandler::WhiteListHandler(const string &user_input)
        : ListHandler(
        "Usage: whitelist add <name>\nUsage: whitelist clear\nUsage: whitelist list\nUsage: whitelist remove <name>",
        "whitelist"), subCommandHandler(nullptr) {
    // if the user_input is invalid, assign errorCode to be 1
    errorCode = WhiteListHandler::validateInput(user_input);

}

// check if the user input is valid and
// assign the correct handler to subCommandHandler if the input is valid
int
WhiteListHandler::validateInput(const string &user_input)  // NOLINT(readability-convert-member-functions-to-static)
{
    // substring the subCommand part (including the parameter)
    int posOfSpace1 = (int) user_input.find(' ');                              // the position of the first white space
    int posOfSpace2 = (int) user_input.find(' ', posOfSpace1 + 1);        // the position of the second white space
    string subCommand = user_input.substr(posOfSpace1 + 1);
    string subCommandName = user_input.substr(posOfSpace1 + 1, posOfSpace2 - posOfSpace1 - 1);
    if (subCommandName == "add") {                     // sub-command : add        NOLINT(bugprone-branch-clone)
        subCommandHandler = new ListAddHandler(subCommand, "whitelist");
        return 0;
    } else if (subCommandName == "clear") {            // sub-command : clear
        subCommandHandler = new ListClearHandler("whitelist");
        return 0;
    } else if (subCommandName == "list") {             // sub-command : list
        subCommandHandler = new ListListHandler("whitelist");
        return 0;
    } else if (subCommandName == "remove") {           // sub-command : remove
        subCommandHandler = new ListRemoveHandler(subCommand, "whitelist");
        return 0;
    }

    return 1;       // return 1 means error
}

void WhiteListHandler::handle_command() {
    // print help_text if there is input error
    if (errorCode != 0)
        InvalidCommandHandler::handle_command();    // NOLINT(bugprone-parent-virtual-call)
    else
        // process the list sub-command
        subCommandHandler->handle_command();
}


// destructor
WhiteListHandler::~WhiteListHandler() {
    // release memory
    delete subCommandHandler;
}