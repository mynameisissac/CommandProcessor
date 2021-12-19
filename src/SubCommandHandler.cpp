//
// Created by kshou on 2021/11/5.
//

#include "../include/SubCommandHandler.h"


SubCommandHandler::SubCommandHandler(const string &help_text, string baseHandlerType)
        : InvalidCommandHandler(help_text, 0), baseHandlerType(std::move(baseHandlerType)) {}