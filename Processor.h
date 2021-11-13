//
// Created by kshou on 2021/10/26.
//

#ifndef COMMANDPROCESSOR_PROCESSOR_H
#define COMMANDPROCESSOR_PROCESSOR_H

#include <iostream>
#include "CommandHandler.h"
#include "PingHandler.h"
#include "SayHandler.h"
#include "AddHandler.h"
#include "QuitHandler.h"
#include "InvalidCommandHandler.h"
#include "HelpHandler.h"
#include "ListHandler.h"
#include "BlacklistHandler.h"
#include "WhiteListHandler.h"
#include <vector>

using std::string;
using std::vector;


class Processor {

    private:
        vector<string> user_input_record;       // storing user input record
        //int run_index;                        // indicate which command is going to be processed
        string current_user_input;              // the user input which is currently going to be processed
        bool *const programTermination;         // indicator of when the main program end
    public:
        explicit Processor(bool *programTermination);        // conversion constructor
        CommandHandler *response() const;      // process the command
        void readInput();                                   // read user input command

        // accessor
        string getRecord(int index) const;                  // return the index-th user input record
        string getRecord() const;

        string getCurrentInput() const;                     // return the current_user_input
};

#endif //COMMANDPROCESSOR_PROCESSOR_H
