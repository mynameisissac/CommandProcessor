//
// Created by kshou on 2021/11/5.
//

#ifndef COMMANDPROCESSOR_BLACKLISTHANDLER_H
#define COMMANDPROCESSOR_BLACKLISTHANDLER_H

#include "InvalidCommandHandler.h"
#include "SubCommandHandler.h"
#include "BlacklistAddHandler.h"
#include <vector>

using std::vector;

class BlacklistHandler : public InvalidCommandHandler {
    private:
        // the list storing the blacklisted name
        // it is static as all BlacklistHandler share the same list
        static vector<string> blacklist;
        // the subCommandHandler handle further process
        SubCommandHandler *subCommandHandler;

        // allow BlacklistAddHandler to
        friend class BlacklistAddHandler;

    public:
        explicit BlacklistHandler(const string &user_input);   // conversion constructor
        // validate whether the user_input is correct
        // i.e. the sub-command is correctly inputted and,
        // assign the correct handler to subCommandHandler if the input is valid
        bool validateInput(const string &user_input);

        void handle_command() override;

        // destructor to release memory of dynamic SubCommandHandler
        virtual ~BlacklistHandler();
};


#endif //COMMANDPROCESSOR_BLACKLISTHANDLER_H
