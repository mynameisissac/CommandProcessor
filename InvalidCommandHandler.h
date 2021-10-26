//
// Created by kshou on 2021/10/26.
//

#ifndef COMMANDPROCESSOR_INVALIDCOMMANDHANDLER_H
#define COMMANDPROCESSOR_INVALIDCOMMANDHANDLER_H

#include "CommandHandler.h"
#include <string>

using std::string;

class InvalidCommandHandler : public CommandHandler {
    private:
        const string help_text = "Command not recognized.";       // help_text to display
    public:
        void handle_command() override;
};


#endif //COMMANDPROCESSOR_INVALIDCOMMANDHANDLER_H
