//
// Created by kshou on 2021/11/13.
//

#ifndef COMMANDPROCESSOR_WHITELISTHANDLER_H
#define COMMANDPROCESSOR_WHITELISTHANDLER_H

#include "../InvalidCommandHandler.h"
#include "ListHandler.h"
#include "ListAddHandler.h"
#include "ListClearHandler.h"
#include "ListListHandler.h"
#include "ListRemoveHandler.h"
#include <vector>

using std::vector;

class WhiteListHandler : public ListHandler {
    private:
        // the subCommandHandler handle further process
        ListHandler *subCommandHandler;

    public:

        explicit WhiteListHandler(const string &user_input);   // conversion constructor

        // validate whether the user_input is correct
        // i.e. the sub-command is correctly inputted and (return 0 if no error, 1 if has error),
        // assign the correct handler to subCommandHandler if the input is valid
        int validateInput(const string &user_input) override;

        void handle_command() override;

        // destructor to release memory of dynamic SubCommandHandler
        virtual ~WhiteListHandler() override; // NOLINT(modernize-use-override)

};


#endif //COMMANDPROCESSOR_WHITELISTHANDLER_H
