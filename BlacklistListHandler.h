//
// Created by kshou on 2021/11/6.
//

#ifndef COMMANDPROCESSOR_BLACKLISTLISTHANDLER_H
#define COMMANDPROCESSOR_BLACKLISTLISTHANDLER_H

#include "SubCommandHandler.h"

class BlacklistListHandler : public SubCommandHandler {
    public:
        //constructor
        BlacklistListHandler();

        void handle_command() override;
};


#endif //COMMANDPROCESSOR_BLACKLISTLISTHANDLER_H
