//
// Created by kshou on 2021/10/26.
//

#ifndef COMMANDPROCESSOR_PINGHANDLER_H
#define COMMANDPROCESSOR_PINGHANDLER_H

#include "CommandHandler.h"
#include <string>

using std::string;

/**
 * derived class from the interface CommandHandler
 */
class PingHandler : public CommandHandler {
    private:
        // text of corresponding response output
        // with initialized value
        string response_text{"pong"};

    public:
        void handle_command() override;
};


#endif //COMMANDPROCESSOR_PINGHANDLER_H
