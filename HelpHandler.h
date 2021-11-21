//
// Created by kshou on 2021/10/31.
//

#ifndef COMMANDPROCESSOR_HELPHANDLER_H
#define COMMANDPROCESSOR_HELPHANDLER_H

#include "common.h"
#include "InvalidCommandHandler.h"
#include "PingHandler.h"
#include "SayHandler.h"
#include "AddHandler.h"
#include "QuitHandler.h"
#include <string>

class HelpHandler : public InvalidCommandHandler {
    private:
        // a string to store which command to help with
        // e.g. commandType = "ping", "say", "add", ...
        commandType commandToHelp;
        // store the userInput
        string userInput;
    public:
        explicit HelpHandler(const string &user_input, const string &nameOnCall);

        void handle_command() override;
};


#endif //COMMANDPROCESSOR_HELPHANDLER_H
