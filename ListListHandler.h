//
// Created by kshou on 2021/11/6.
//

#ifndef COMMANDPROCESSOR_LISTLISTHANDLER_H
#define COMMANDPROCESSOR_LISTLISTHANDLER_H

#include "ListHandler.h"

// ListListHandler means the "list" command Handler for lists
class ListListHandler : public ListHandler {
    public:
        // conversion constructor
        explicit ListListHandler(const string &listName);

        int validateInput(const string &user_input) override;

        void handle_command() override;
};


#endif //COMMANDPROCESSOR_LISTLISTHANDLER_H
