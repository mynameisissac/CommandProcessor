//
// Created by kshou on 2021/11/5.
//

#include "BlacklistAddHandler.h"
#include "BlacklistHandler.h"
#include <iostream>


// constructor
BlacklistAddHandler::BlacklistAddHandler(const string &userInput)
        : SubCommandHandler("Usage: blacklist add <nameToAdd>", "BlacklistHandler") {
    // check if the input is valid, and assign value to data member nameToAdd
    errorCode = validateInput(userInput);
}


// helper function to check if the parameter string contains invalid characters
bool validParameter(const string &parameter) {
    for (char c: parameter) // NOLINT(readability-use-anyofallof)
        if ((c < '0' || c > '9') && (c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && c != '_')
            return false;

    return true;
}

// validate the input, including checking if the parameter is input correctly
// return the errorCode
// assign the data member nameToAdd if no invalid input (i.e. errorCode == 0)
int
BlacklistAddHandler::validateInput(const string &userInput) { // NOLINT(readability-convert-member-functions-to-static)

    // substr the parameter part
    int posOfSpace = (int) userInput.find(' ');
    string parameter = userInput.substr(posOfSpace + 1);
    // if nothing provided after add
    if (posOfSpace == string::npos || posOfSpace == userInput.size() - 1)
        return 1;                   // return 1 to errorCode
    else if (!validParameter(parameter))
        return 2;                   // return 2 to errorCode
    // if no invalid input of parameter
    nameToAdd = parameter;
    return 0;
}


void BlacklistAddHandler::handle_command() {
    // check if there is invalid user input
    if (errorCode != 0) {
        if (errorCode == 1)
            std::cout << "No name provided." << std::endl;
        else if (errorCode == 2)
            std::cout << "Invalid nameToAdd." << std::endl;
        InvalidCommandHandler::handle_command();            // print the command specific help text
    }
        // add the name into the list if input is all valid
    else {
        // push the name into the list
        BlacklistHandler::blacklist.push_back(nameToAdd);
        std::cout << nameToAdd << " added to blacklist." << std::endl;
    }
}