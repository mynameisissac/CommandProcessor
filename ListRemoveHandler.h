//
// Created by kshou on 2021/11/6.
//

#ifndef COMMANDPROCESSOR_LISTREMOVEHANDLER_H
#define COMMANDPROCESSOR_LISTREMOVEHANDLER_H

#include "ListHandler.h"

class ListRemoveHandler : public ListHandler {
    private:
        //store the parameter of blacklist remove
        string nameToRemove;
    public:
        //constructor
        explicit ListRemoveHandler(const string &userInput, const string &listName);

        // validate the input, including checking if the parameter is input correctly, return the errorCode
        int validateInput(const string &userInput) override;

        void handle_command() override;
};


#endif //COMMANDPROCESSOR_LISTREMOVEHANDLER_H
