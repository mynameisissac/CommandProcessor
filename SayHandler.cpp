//
// Created by kshou on 2021/10/26.
//

#include "SayHandler.h"
#include <iostream>


// default constructor
SayHandler::SayHandler(const string &nameOnCall)
        : InvalidCommandHandler("Usage: " + nameOnCall + " <text>", 0) {
}

void SayHandler::handle_command() {
    if (errorCode == 1) {                        // if user input is invalid
        std::cout << "No text provided." << std::endl;
        InvalidCommandHandler::handle_command();        // call the handle_command() in the base class
    } else
        std::cout << response_text << std::endl;
}


// constructor that initialize the response_text and nameOnCall
SayHandler::SayHandler(const string &user_input, const string &nameOnCall)
        : InvalidCommandHandler("Usage: " + nameOnCall + " <text>", 0) {
    // assign the name used for calling SayHandler
    this->nameOnCall = nameOnCall;
    if (user_input.length() ==
        nameOnCall.length()) {           // if user only input "say" or "ehco" or "print" without following any words
        errorCode = 1;
        response_text.clear();              // clear the string object to indicate user input invalid
    } else                                    // else get the word after "say" keyword
        response_text = user_input.substr(nameOnCall.length() + 1);
}

