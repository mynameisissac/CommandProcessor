//
// Created by kshou on 2021/11/6.
//

#ifndef COMMANDPROCESSOR_LISTCLEARHANDLER_H
#define COMMANDPROCESSOR_LISTCLEARHANDLER_H

#include "ListHandler.h"


class ListClearHandler : public ListHandler {
    private:
        // list clear requires user confirmation
        bool confirmed = false;
    public:
        //  conversion constructor
        explicit ListClearHandler(const string& listName);

        ListClearHandler(const string& userInput, const string& listName);

        int validateInput(const string& userInput) override;

        void handle_command() override;
};


#endif //COMMANDPROCESSOR_LISTCLEARHANDLER_H
