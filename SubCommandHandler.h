//
// Created by kshou on 2021/11/5.
//

#ifndef COMMANDPROCESSOR_SUBCOMMANDHANDLER_H
#define COMMANDPROCESSOR_SUBCOMMANDHANDLER_H

#include "InvalidCommandHandler.h"

class SubCommandHandler : public InvalidCommandHandler {
    private:
        // store the class type name of the base class of the sub-command handler
        string baseClassType;

    public:
        // constructor
        SubCommandHandler(const string &help_text);
};


#endif //COMMANDPROCESSOR_SUBCOMMANDHANDLER_H
