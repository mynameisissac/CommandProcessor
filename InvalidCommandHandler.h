//
// Created by kshou on 2021/10/26.
//

#ifndef COMMANDPROCESSOR_INVALIDCOMMANDHANDLER_H
#define COMMANDPROCESSOR_INVALIDCOMMANDHANDLER_H

#include "CommandHandler.h"
#include <string>

using std::string;

class InvalidCommandHandler : public CommandHandler {
    protected:
        string help_text = "Command not recognized.";          // help_text to display
        // different error may occur, start from 1
        // 0 means no error
        int errorCode = 1;
    public:
        InvalidCommandHandler() = default;                    // default constructor
        explicit InvalidCommandHandler(string help_text, int errorCode = 1);     // conversion constructor
        void handle_command() override;
};


#endif //COMMANDPROCESSOR_INVALIDCOMMANDHANDLER_H
