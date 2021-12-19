//
// Created by kshou on 2021/10/26.
//

#ifndef COMMANDPROCESSOR_PINGHANDLER_H
#define COMMANDPROCESSOR_PINGHANDLER_H

#include "InvalidCommandHandler.h"
#include <string>

using std::string;

/**
 * derived class from the interface CommandHandler
 */
class PingHandler : public InvalidCommandHandler {
    private:
        // text of corresponding response output
        // with initialized value
        string response_text{"pong"};

    public:

        PingHandler() = default;    // default constructor
        explicit PingHandler(const string &nameOnCall);          // conversion constructor
        void handle_command() override;
};


#endif //COMMANDPROCESSOR_PINGHANDLER_H
