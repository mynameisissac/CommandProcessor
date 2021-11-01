//
// Created by kshou on 2021/10/26.
//

#include "SayHandler.h"
#include <iostream>

// default constructor
SayHandler::SayHandler()
        : InvalidCommandHandler("Usage: say <text>", 0) {
}

void SayHandler::handle_command() {
    if (errorCode == 1) {                        // if user input is invalid
        std::cout << "No text provided." << std::endl;
        InvalidCommandHandler::handle_command();        // call the handle_command() in the base class
    } else
        std::cout << response_text << std::endl;
}


// constructor that initialize the response_text
SayHandler::SayHandler(const string &user_input)
        : InvalidCommandHandler("Usage: say <text>", 0) {
    if (user_input.length() == 3) {           // if user only input "say" without following any words
        errorCode = 1;
        response_text.clear();              // clear the string object to indicate user input invalid
    } else                                    // else get the word after "say" keyword
        response_text = user_input.substr(4);
}

