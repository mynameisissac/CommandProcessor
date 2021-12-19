//
// Created by kshou on 2021/11/6.
//

#include "../include/ListHandler/ListClearHandler.h"
#include "../include/Confirmation.h"
#include <iostream>

// constructor
ListClearHandler::ListClearHandler(const string& listName)
        : ListHandler("Usage: " + listName + " clear", listName) {}

ListClearHandler::ListClearHandler(const string& userInput, const string& listName)
        : ListHandler("Usage: " + listName + " clear", listName) {
    errorCode = ListClearHandler::validateInput(userInput);
}

int ListClearHandler::validateInput(const string& userInput) {
    // check if has "-Y" pre-confirm message in parameter string
    if (userInput.find(" -Y") != string::npos
        || userInput.find(" -y") != string::npos)
        confirmed = true;

    return 0;       // always return 0 for errorCode, coz no parameter to validate
}


// requires confirmation
void ListClearHandler::handle_command() {

    if (!confirmed && !Confirmation()())      // use function object Confirmation to confirm with user decision
        return;

    // clear the list
    if (listName == "blacklist") {
        blacklist.clear();
        std::cout << "Blacklist cleared." << std::endl;
    } else if (listName == "whitelist") {
        whitelist.clear();
        std::cout << "whitelist cleared." << std::endl;
    }

}