//
// Created by kshou on 2021/10/31.
//

#include "HelpHandler.h"
#include <iostream>

using std::string;


// conversion constructor
// Note that here the error message(Invalid handler help text) of HelpHandler is not the usage help text,
// which is different from typical InvalidCommandHandler's help text (they are usage help text)
HelpHandler::HelpHandler(const string &user_input)
        : InvalidCommandHandler("add\nhelp\nping\nquit\nsay\nsubtract", 1), commandType() {
    if (user_input.length() > 4)       //  if there exist parameter i.e. user_input is valid then no error
        errorCode = 0;

    if (user_input.find("ping") != string::npos)        // if the required command is ping
        commandType = "ping";
    else if (user_input.find("say") != string::npos)
        commandType = "say";
    else if (user_input.find("add") != string::npos)
        commandType = "add";
    else if (user_input.find("subtract") != string::npos)
        commandType = "subtract";
    else if (user_input.find("help", 4) != string::npos)
        commandType = "help";
    else if (user_input.find("quit") != string::npos)
        commandType = "quit";
}

// overrided from Command Handler
void HelpHandler::handle_command() {
    // check if user_input is invalid
    if (errorCode != 0 || commandType.empty()) {
        // if no parameter is given
        InvalidCommandHandler::handle_command();        // print error message
    } else {
        InvalidCommandHandler *handler = nullptr;
        if (commandType == "ping")                  // help ping
            handler = new PingHandler();
        else if (commandType == "say")              // help say
            handler = new SayHandler();
        else if (commandType == "add")              // help add
            handler = new AddHandler(1);
        else if (commandType == "subtract")         // help subtract
            handler = new AddHandler(-1);
        else if (commandType == "quit")             // help quit
            handler = new QuitHandler();
        else {                                     // help help
            std::cout << "Usage: help [<command>]" << std::endl;        // print HelpHandler's usage help_text
            return;                 // early return
        }
        handler->InvalidCommandHandler::handle_command();           // print their help_text
        delete handler;         // avoid memory leak
    }
}