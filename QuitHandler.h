//
// Created by kshou on 2021/11/1.
//

#ifndef COMMANDPROCESSOR_QUITHANDLER_H
#define COMMANDPROCESSOR_QUITHANDLER_H

#include "InvalidCommandHandler.h"


class QuitHandler : public InvalidCommandHandler {
    private:
        // pointer point to a location where store the program end indicator
        // pass from the main
        bool *const programEndIndicator;
    public:
        // default constructor
        QuitHandler();

        // conversion constructor
        explicit QuitHandler(bool *programEndIndicator);

        void handle_command() override;
};


#endif //COMMANDPROCESSOR_QUITHANDLER_H
