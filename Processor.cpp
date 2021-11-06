//
// Created by kshou on 2021/10/26.
//

#include <iostream>
#include "Processor.h"
#include <string>
#include <algorithm>

using namespace std;

// definition of the BlacklistHandler class static data member
vector<string> BlacklistHandler::blacklist;

/**
 *  process the command : validate the input and choose which CommandHandler to assign for handler
 * @return a pointer to dynamic CommandHandler object
 */
CommandHandler *Processor::response() const {

    // choose which handler to assign
    if (current_user_input == "ping")           // command : add
        return new PingHandler();
    else if (current_user_input.rfind("say", 0) != string::npos)             // command : say
        return new SayHandler(current_user_input);
    else if (current_user_input.rfind("add", 0) != string::npos)            // command : add
        return new AddHandler(current_user_input); // NOLINT(bugprone-branch-clone)
    else if (current_user_input.rfind("subtract", 0) != string::npos)      // command : subtract
        return new AddHandler(current_user_input);
    else if (current_user_input.rfind("help", 0) != string::npos)           // command : help
        return new HelpHandler(current_user_input);
    else if (current_user_input.rfind("quit", 0) != string::npos)           // command : quit
        return new QuitHandler(programTermination);
    else if (current_user_input.rfind("blacklist", 0) != string::npos)      // command : blacklist
        return new BlacklistHandler(current_user_input);
    else
        return new InvalidCommandHandler();         // if the input is invalid
}


// constructor of the processor to initialize programTermination
Processor::Processor(bool *programTermination)
        : programTermination(programTermination) {
    // set the program end indicator to false
    (*programTermination) = false;
}


/**
 * read the user input and store the result into the vector data member
 */
void Processor::readInput() {
    string input;
    cout << "\n> ";
    getline(cin, input);
    current_user_input = input;
    user_input_record.push_back(input);
}


// a default accessor of the user_input_record which return the top most command
string Processor::getRecord() const {
    return getRecord((int) user_input_record.size() - 1);
}

string Processor::getRecord(int index) const {
    return user_input_record[index];
}

// accessor to get the current user input which is being processed
string Processor::getCurrentInput() const {
    return current_user_input;
}
