//
// Created by kshou on 2021/11/5.
//

#ifndef COMMANDPROCESSOR_BLACKLISTHANDLER_H
#define COMMANDPROCESSOR_BLACKLISTHANDLER_H

#include "InvalidCommandHandler.h"
#include "BlacklistSubCommandHandler.h"
#include <vector>

using std::vector;

class BlacklistHandler : public InvalidCommandHandler {
    private:
        // the list storing the blacklisted name
        vector<string> blacklist;
        // the subCommandHandler handle further process
        BlacklistSubCommandHandler *subCommandHandler;

    public:
        explicit BlacklistHandler(const string &user_input);   // conversion constructor
        // validate whether the user_input is correct
        // i.e. the sub-command is correctly inputted and,
        // assign the correct handler to subCommandHandler if the input is valid
        bool validateInput(const string &user_input);

        void handle_command() override;
};


#endif //COMMANDPROCESSOR_BLACKLISTHANDLER_H
