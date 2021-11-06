//
// Created by kshou on 2021/11/5.
//

#ifndef COMMANDPROCESSOR_BLACKLISTADDHANDLER_H
#define COMMANDPROCESSOR_BLACKLISTADDHANDLER_H

#include "SubCommandHandler.h"

class BlacklistAddHandler : public SubCommandHandler {
    private:
        // store the parameter of blacklist add
        string nameToAdd;
    public:
        explicit BlacklistAddHandler(const string &userInput);

        // validate the input, including checking if the parameter is input correctly, return the errorCode
        int validateInput(const string &userInput);

        void handle_command() override;
};

// helper function to check if the parameter string contains invalid characters
bool validParameter(const string &parameter);


#endif //COMMANDPROCESSOR_BLACKLISTADDHANDLER_H
