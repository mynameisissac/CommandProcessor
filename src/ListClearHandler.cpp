//
// Created by kshou on 2021/11/6.
//

#include "../include/ListHandler/ListClearHandler.h"
#include "../include/Confirmation.h"
#include <iostream>

// constructor
ListClearHandler::ListClearHandler(const string& listName)
        : ListHandler("Usage: " + listName + " clear", listName) {}


int ListClearHandler::validateInput(const string& user_input) {
    return 0;       // do nothing, coz no parameter to validate
}


// requires confirmation
void ListClearHandler::handle_command() {

    if (!Confirmation()())      // use function object Confirmation to confirm with user decision
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