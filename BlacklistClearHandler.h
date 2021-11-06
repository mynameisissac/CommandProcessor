//
// Created by kshou on 2021/11/6.
//

#ifndef COMMANDPROCESSOR_BLACKLISTCLEARHANDLER_H
#define COMMANDPROCESSOR_BLACKLISTCLEARHANDLER_H

#include "SubCommandHandler.h"


class BlacklistClearHandler : public SubCommandHandler {
    public:
        // constructor
        BlacklistClearHandler();

        void handle_command() override;
};


#endif //COMMANDPROCESSOR_BLACKLISTCLEARHANDLER_H
