//
// Created by kshou on 2021/11/5.
//

#ifndef COMMANDPROCESSOR_SUBCOMMANDHANDLER_H
#define COMMANDPROCESSOR_SUBCOMMANDHANDLER_H

#include "InvalidCommandHandler.h"

class SubCommandHandler : public InvalidCommandHandler {
    private:
        // store the class type nameToAdd of the base handler of the sub-command handler
        string baseHandlerType;

    public:
        // constructor
        explicit SubCommandHandler(const string &help_text, string baseHandlerType);

        // no implementation of void handle_command();
};


#endif //COMMANDPROCESSOR_SUBCOMMANDHANDLER_H
