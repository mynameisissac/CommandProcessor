//
// Created by kshou on 2021/10/26.
//

#ifndef COMMANDPROCESSOR_PROCESSOR_H
#define COMMANDPROCESSOR_PROCESSOR_H
#include <iostream>
#include <vector>
using std::string;
using std::vector;


class Processor {

private:
    vector<string> command_list;      // a vector storing all the command
    vector<string> response_list;      // a vector storing all the response output string
    vector<string> user_input_record;   // storing user input record
    //int run_index;                      // indicate which command is going to be processed
    const string help_text = "Command not recognized.";       // help_text to display

public:

    Processor(vector<string>command_list, vector<string> response_list);            // constructor
    bool validateInput(string user_input) const;
    void response() const;      // process the command
    void getInput();            // read user input command
    string getRecord(int index) const;             // return the index-th user input record
    string getRecord() const;

};



#endif //COMMANDPROCESSOR_PROCESSOR_H
