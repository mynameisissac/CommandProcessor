//
// Created by kshou on 2021/11/1.
//

#include "../include/QuitHandler.h"
#include "../include/Confirmation.h"

// default constructor
QuitHandler::QuitHandler(const string &nameOnCall)
        : InvalidCommandHandler("Usage: " + nameOnCall, 0), programEndIndicator(nullptr) {
    this->nameOnCall = nameOnCall;
}


// conversion constructor
// programEndIndicator is a constant pointer
QuitHandler::QuitHandler(bool *programEndIndicator, const string &nameOnCall)
        : InvalidCommandHandler("Usage: " + nameOnCall, 0), programEndIndicator(programEndIndicator) {
    this->nameOnCall = nameOnCall;
}

// requires user confirmation
void QuitHandler::handle_command() {

    if (!Confirmation()())      // use function object Confirmation to confirm with user decision
        return;

    // set the program terminate indicator to true
    (*programEndIndicator) = true;
}