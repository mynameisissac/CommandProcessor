//
// Created by kshou on 2021/11/5.
//

#ifndef COMMANDPROCESSOR_BLACKLISTADDHANDLER_H
#define COMMANDPROCESSOR_BLACKLISTADDHANDLER_H

#include "BlacklistSubCommandHandler.h"

class BlacklistAddHandler : public BlacklistSubCommandHandler {
    private:

    public:
        BlacklistAddHandler();

        void handle_command() override;
};


#endif //COMMANDPROCESSOR_BLACKLISTADDHANDLER_H
