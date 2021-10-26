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
#include "InvalidCommandHandler.h"
#include <vector>

using std::string;
using std::vector;


class Processor {

    private:
        vector<string> command_list;            // a vector storing all the command
        vector<string> user_input_record;       // storing user input record
        //int run_index;                        // indicate which command is going to be processed
        string current_user_input;              // the user input which is currently going to be processed

    public:

        explicit Processor(vector<string> command_list);              // constructor
        bool validInput(const string &user_input) const;           // check if the user input is a valid command
        CommandHandler *response() const;      // process the command
        void readInput();                                   // read user input command

        // accessor
        string getRecord(int index) const;                  // return the index-th user input record
        string getRecord() const;

        string getCurrentInput() const;                     // return the current_user_input
};

#endif //COMMANDPROCESSOR_PROCESSOR_H
