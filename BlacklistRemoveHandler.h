//
// Created by kshou on 2021/11/6.
//

#ifndef COMMANDPROCESSOR_BLACKLISTREMOVEHANDLER_H
#define COMMANDPROCESSOR_BLACKLISTREMOVEHANDLER_H

#include "SubCommandHandler.h"

class BlacklistRemoveHandler : public SubCommandHandler {
    private:
        //store the parameter of blacklist remove
        string nameToRemove;
    public:
        //constructor
        explicit BlacklistRemoveHandler(const string &userInput);

        // validate the input, including checking if the parameter is input correctly, return the errorCode
        int validateInput(const string &userInput);

        void handle_command() override;
};


#endif //COMMANDPROCESSOR_BLACKLISTREMOVEHANDLER_H
