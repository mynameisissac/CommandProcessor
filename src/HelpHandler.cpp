//
// Created by kshou on 2021/10/31.
//

#include "../include/HelpHandler.h"
#include <iostream>

using std::string;


// conversion constructor
// Note that here the error message(Invalid handler help text) of HelpHandler is not the usage help text,
// which is different from typical InvalidCommandHandler's help text (they are usage help text)
HelpHandler::HelpHandler(const string &user_input, const string &nameOnCall)
        : InvalidCommandHandler("add\nhelp\nping\nquit\nsay\nsubtract", 1) {
    // assign the inherited data members, i.e. which alias used to call helpHandler
    this->nameOnCall = nameOnCall;
    parameter = user_input.substr(nameOnCall.length() + 1);
    if (user_input.length() >
        nameOnCall.length())       //  if there exist parameter i.e. user_input is valid then no error
        errorCode = 0;

    // assign the correct commandType to help with
    commandToHelp = getCommandType(parameter);
    //std::cout << "help result: " << (commandToHelp == commandType::undefined) << std:: endl;
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
            handler = new PingHandler(inTheList(pingAlias, 1, parameter));
        else if (commandToHelp == commandType::say)              // help say
            handler = new SayHandler(inTheList(sayAlias, 3, parameter));
        else if (commandToHelp == commandType::add)              // help add
            handler = new AddHandler(inTheList(addAlias, 2, parameter));
        else if (commandToHelp == commandType::subtract)         // help subtract
            handler = new AddHandler(inTheList(subtractAlias, 2, parameter));
        else if (commandToHelp == commandType::quit)             // help quit
            handler = new QuitHandler(inTheList(quitAlias, 3, parameter));
        else {                                     // help help/man help/man man
            string newNameOnCall = inTheList(helpAlias, 2, parameter);
            std::cout << "Usage: " + newNameOnCall + " [<command>]"
                      << std::endl;        // print HelpHandler's usage help_text
            return;                 // early return
        }
        handler->InvalidCommandHandler::handle_command();           // print their help_text
        delete handler;         // avoid memory leak
    }
}