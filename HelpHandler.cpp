//
// Created by kshou on 2021/10/31.
//

#include "HelpHandler.h"
#include <iostream>

using std::string;


// conversion constructor
// Note that here the error message(Invalid handler help text) of HelpHandler is not the usage help text,
// which is different from typical InvalidCommandHandler's help text (they are usage help text)
HelpHandler::HelpHandler(const string &user_input, const string &nameOnCall)
        : InvalidCommandHandler("add\nhelp\nping\nquit\nsay\nsubtract", 1), userInput(user_input) {
    // assign the inherited data members, i.e. which alias used to call helpHandler
    this->nameOnCall = nameOnCall;
    if (user_input.length() > 4)       //  if there exist parameter i.e. user_input is valid then no error
        errorCode = 0;

    // assign the correct commandType to help with
    commandToHelp = getCommandType(user_input);
}

// overrided from Command Handler
void HelpHandler::handle_command() {
    // check if user_input is invalid
    if (errorCode != 0 || commandToHelp == commandType::undefined) {
        // if no parameter is given
        InvalidCommandHandler::handle_command();        // print error message
    } else {
        InvalidCommandHandler *handler = nullptr;
        if (commandToHelp == commandType::ping)        // help ping
            handler = new PingHandler(inTheList(pingAlias, 1, userInput));
        else if (commandToHelp == commandType::say)              // help say
            handler = new SayHandler(inTheList(sayAlias, 3, userInput));
            /*else if (commandType == "add")              // help add
                handler = new AddHandler(1);
            else if (commandType == "subtract")         // help subtract
                handler = new AddHandler(-1);*/
        else if (commandToHelp == commandType::quit)             // help quit
            handler = new QuitHandler();
        else {                                     // help help/man help/man man
            std::cout << "Usage: " + nameOnCall + " [<command>]"
                      << std::endl;        // print HelpHandler's usage help_text
            return;                 // early return
        }
        handler->InvalidCommandHandler::handle_command();           // print their help_text
        delete handler;         // avoid memory leak
    }
}