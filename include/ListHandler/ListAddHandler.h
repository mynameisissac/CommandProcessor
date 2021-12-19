//
// Created by kshou on 2021/11/5.
//

#ifndef COMMANDPROCESSOR_LISTADDHANDLER_H
#define COMMANDPROCESSOR_LISTADDHANDLER_H

#include "../InvalidCommandHandler.h"
#include "ListHandler.h"

class ListAddHandler : public ListHandler {
    private:
        // store the parameter of blacklist add
        string nameToAdd;
        // list Add requires user confirmation
        bool confirmed = false;
    public:
        explicit ListAddHandler(const string& userInput, const string& listName);

        // validate the input, including checking if the parameter is input correctly, return the errorCode
        int validateInput(const string& userInput) override;

        void handle_command() override;
};

// helper function to check if the parameter string contains invalid characters
bool validParameter(const string &parameter);


#endif //COMMANDPROCESSOR_LISTADDHANDLER_H
