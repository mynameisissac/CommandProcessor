//
// Created by kshou on 2021/10/26.
//

#ifndef COMMANDPROCESSOR_SAYHANDLER_H
#define COMMANDPROCESSOR_SAYHANDLER_H

#include "InvalidCommandHandler.h"
#include <string>

using std::string;

class SayHandler : public InvalidCommandHandler {
    private:
        string response_text;
    public:
        explicit SayHandler(const string &user_input);     // constructor, explicit to avoid implicit conversion
        void handle_command() override;
};


#endif //COMMANDPROCESSOR_SAYHANDLER_H
