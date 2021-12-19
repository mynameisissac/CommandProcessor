//
// Created by kshou on 2021/10/26.
//

#ifndef COMMANDPROCESSOR_INVALIDCOMMANDHANDLER_H
#define COMMANDPROCESSOR_INVALIDCOMMANDHANDLER_H

#include "CommandHandler.h"
#include <string>

using std::string;

// store and handle the case which need command specific help text
class InvalidCommandHandler : public CommandHandler {
    protected:
        // command specific help_text to display when some invalid input occur
        string help_text = "Command not recognized.";

        // different error may occur, start from 1
        // 0 means no error
        // this errorCode is basically for the derived class of InvalidCommandHandler
        int errorCode = 1;
    public:
        InvalidCommandHandler() = default;                    // default constructor
        explicit InvalidCommandHandler(string help_text, int errorCode = 1);     // conversion constructor
        void handle_command() override;
};


#endif //COMMANDPROCESSOR_INVALIDCOMMANDHANDLER_H
