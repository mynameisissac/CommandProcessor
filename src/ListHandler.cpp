//
// Created by kshou on 2021/11/11.
//

#include "../include/ListHandler/ListHandler.h"


ListHandler::ListHandler(const string &help_text, string listName)
        : InvalidCommandHandler(help_text, 0), listName(std::move(listName)) {}


