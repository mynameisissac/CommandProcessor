//
// Created by kshou on 2021/11/5.
//

#ifndef COMMANDPROCESSOR_BLACKLISTADDHANDLER_H
#define COMMANDPROCESSOR_BLACKLISTADDHANDLER_H

#include "SubCommandHandler.h"

class BlacklistAddHandler : public SubCommandHandler {
    private:

    public:
        explicit BlacklistAddHandler(const string &userInput);

        // validate the input, including checking if the parameter is input correctly, return the errorCode
        int validateInput(const string &userInput);

        void handle_command() override;
};


#endif //COMMANDPROCESSOR_BLACKLISTADDHANDLER_H
