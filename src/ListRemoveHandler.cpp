//
// Created by kshou on 2021/11/6.
//

#include "../include/ListHandler/ListRemoveHandler.h"
#include "../include/ListHandler/ListAddHandler.h"        // to use the global function bool validParameter(const string& parameter) in that headerfile
#include "../include/ListHandler/BlacklistHandler.h"
#include "../include/ListHandler/WhiteListHandler.h"
#include <iostream>
#include <algorithm>

// conversion constructor
ListRemoveHandler::ListRemoveHandler(const string& userInput, const string& listName)
        : ListHandler("Usage: " + listName + " remove <name>", listName) {
    // check if the input is valid, and assign value to data member nameToAdd
    errorCode = ListRemoveHandler::validateInput(userInput);
}


// validate the input, including checking if the parameter is input correctly
// return the errorCode
// assign the data member nameToAdd if no invalid input (i.e. errorCode == 0)
int
ListRemoveHandler::validateInput(
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

void ListRemoveHandler::handle_command() {
    // check if there is invalid user input
    if (errorCode != 0) {
        if (errorCode == 1)
            std::cout << "No name provided." << std::endl;
        else if (errorCode == 2)
            std::cout << "Invalid name." << std::endl;
        InvalidCommandHandler::handle_command();            // print the command specific help text NOLINT(bugprone-parent-virtual-call)
    }
        // remove the name from the list if input is all valid
    else {
        // declare a pointer to the list
        vector<string> *listptr = nullptr;
        if (listName == "blacklist")
            listptr = &blacklist;
        else if (listName == "whitelist")
            listptr = &whitelist;

        if (listptr != nullptr) {   // avoid dereferencing nullptr
            // check if the name exist in the list
            auto iteratorOfNamePos = std::find(listptr->begin(), listptr->end(),
                                               nameToRemove);
            if (iteratorOfNamePos != listptr->end()) {
                // remove the target position element
                listptr->erase(iteratorOfNamePos);
                std::cout << nameToRemove << " removed from " << listName << '.' << std::endl;
            } else // the name not exist in the list
                std::cout << nameToRemove << " is not in the " << listName << '.' << std::endl;
        }
    }
}