//
// Created by kshou on 2021/11/6.
//

#include "../include/ListHandler/ListListHandler.h"
#include "../include/ListHandler/BlacklistHandler.h"
#include "../include/ListHandler/WhiteListHandler.h"
#include <iostream>

// constructor
ListListHandler::ListListHandler(const string& listName)
        : ListHandler("Usage: " + listName + " list", listName) {}

// overrided function
int ListListHandler::validateInput(const string& user_input) {
    return 0;       // do nothing
}

void ListListHandler::handle_command() {
    // assign the correct list to listptr
    vector<string> *listptr = nullptr;
    if (listName == "blacklist")
        listptr = &blacklist;
    else if (listName == "whitelist")
        listptr = &whitelist;

    if (listptr != nullptr) {
        // check if the list is empty
        if (listptr->empty())
            std::cout << listName << " is empty." << std::endl;
            // otherwise, print the name in the list line by line
        else
            for (const string &name: (*listptr))
                std::cout << name << std::endl;
    }
}