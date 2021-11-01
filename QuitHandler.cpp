//
// Created by kshou on 2021/11/1.
//

#include "QuitHandler.h"

// default constructor
QuitHandler::QuitHandler()
        : InvalidCommandHandler("Usage: quit", 0), programEndIndicator(nullptr) {}


// conversion constructor
// programEndIndicator is a constant pointer
QuitHandler::QuitHandler(bool *programEndIndicator)
        : InvalidCommandHandler("Usage: quit", 0), programEndIndicator(programEndIndicator) {
}

void QuitHandler::handle_command() {
    // set the program terminate indicator to true
    (*programEndIndicator) = true;
}