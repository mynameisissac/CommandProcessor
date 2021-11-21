//
// Created by kshou on 2021/10/26.
//

#ifndef COMMANDPROCESSOR_COMMANDHANDLER_H
#define COMMANDPROCESSOR_COMMANDHANDLER_H
#include <string>

/**
 * CommandHandler class is the interface/abstract base class of all command handlers
 */
class CommandHandler {
    protected:
        // every command handler may be called by different names (they can have alias)
        std::string nameOnCall;

    public:
        CommandHandler() = default;                   // default constructor of the interface
        virtual void handle_command() = 0;          // pure virtual function that handle different kinds of command
        virtual ~CommandHandler();                 // the destructor of interface should be virtual
};


#endif //COMMANDPROCESSOR_COMMANDHANDLER_H
