//
// Created by kshou on 2021/10/26.
//

#ifndef COMMANDPROCESSOR_COMMANDHANDLER_H
#define COMMANDPROCESSOR_COMMANDHANDLER_H


/**
 * CommandHandler class is the interface/abstract base class of all command handlers
 */
class CommandHandler {

    public:
        //CommandHandler() {}                      // default constructor of the interface
        virtual void handle_command() = 0;          // pure virtual function that handle different kinds of command
        virtual ~CommandHandler();                 // the destructor of interface should be virtual
};


#endif //COMMANDPROCESSOR_COMMANDHANDLER_H
