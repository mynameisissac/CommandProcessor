//
// Created by kshou on 2021/11/11.
//

#ifndef COMMANDPROCESSOR_LISTHANDLER_H
#define COMMANDPROCESSOR_LISTHANDLER_H

#include "InvalidCommandHandler.h"
#include <vector>

using std::vector;

// an abstract base class for different kind of list handler
class ListHandler : public InvalidCommandHandler {
    protected:
        // name of the list e.g. blacklist, whitelist
        // to tell this handler handling which list
        string listName;

        // the two static lists as all listHandler share the same lists
        static vector<string> blacklist;
        static vector<string> whitelist;

    public:
        // conversion constructor
        explicit ListHandler(const string &help_text, string listName);

        // pure virtual function
        virtual void handle_command() override = 0;         // NOLINT(modernize-use-override)
        virtual int validateInput(const string &user_input) = 0;
};


#endif //COMMANDPROCESSOR_LISTHANDLER_H
