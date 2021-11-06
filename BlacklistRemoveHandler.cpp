//
// Created by kshou on 2021/11/6.
//

#include "BlacklistRemoveHandler.h"
#include "BlacklistAddHandler.h"        // to use the global function bool validParameter(const string& parameter) in that headerfile
#include "BlacklistHandler.h"
#include <iostream>
#include <algorithm>

// conversion constructor
BlacklistRemoveHandler::BlacklistRemoveHandler(const string &userInput)
        : SubCommandHandler("Usage: blacklist remove <nameToAdd>", "BlacklistHandler") {
    // check if the input is valid, and assign value to data member nameToAdd
    errorCode = validateInput(userInput);
}


// validate the input, including checking if the parameter is input correctly
// return the errorCode
// assign the data member nameToAdd if no invalid input (i.e. errorCode == 0)
int
BlacklistRemoveHandler::validateInput(
        const string &userInput) { // NOLINT(readability-convert-member-functions-to-static)

    // substr the parameter part
    int posOfSpace = (int) userInput.find(' ');
    string parameter = userInput.substr(posOfSpace + 1);
    // if nothing provided after add
    if (posOfSpace == string::npos || posOfSpace == userInput.size() - 1)
        return 1;                   // return 1 to errorCode
    else if (!validParameter(parameter))
        return 2;                   // return 2 to errorCode
    // if no invalid input of parameter
    nameToRemove = parameter;
    return 0;
}

void BlacklistRemoveHandler::handle_command() {
    // check if there is invalid user input
    if (errorCode != 0) {
        if (errorCode == 1)
            std::cout << "No name provided." << std::endl;
        else if (errorCode == 2)
            std::cout << "Invalid name." << std::endl;
        InvalidCommandHandler::handle_command();            // print the command specific help text
    }
        // remove the name from the list if input is all valid
    else {
        // check if the name exist in the list
        auto iteratorOfNamePos = std::find(BlacklistHandler::blacklist.begin(), BlacklistHandler::blacklist.end(),
                                           nameToRemove);
        if (iteratorOfNamePos != BlacklistHandler::blacklist.end()) {
            // remove the target position element
            BlacklistHandler::blacklist.erase(iteratorOfNamePos);
            std::cout << nameToRemove << " removed from blacklist." << std::endl;
        } else // the name not exist in the list
            std::cout << nameToRemove << " is not in the blacklist." << std::endl;
    }
}