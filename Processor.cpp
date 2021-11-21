//
// Created by kshou on 2021/10/26.
//

#include <iostream>
#include "Processor.h"
#include <string>
#include <algorithm>

using namespace std;

// definition of static variables
// the two lists
// which are ListHandler class static data member
vector<string> ListHandler::blacklist;
vector<string> ListHandler::whitelist;



/**
 *  process the command : validate the input and choose which CommandHandler to assign for handler
 * @return a pointer to dynamic CommandHandler object
 */
CommandHandler *Processor::response() const {

    // validate the input and find the correct commandType
    commandType typeOfCommand = getCommandType(current_user_input);

    // choose which handler to assign
    if (typeOfCommand == commandType::ping)                 // command : add
        return new PingHandler(inTheList(pingAlias, 1, current_user_input));
    else if (typeOfCommand == commandType::say)             // command : say
        return new SayHandler(current_user_input, inTheList(sayAlias, 3, current_user_input));
    else if (typeOfCommand == commandType::add)             // command : add
        return new AddHandler(current_user_input,
                              inTheList(addAlias, 2, current_user_input));  // NOLINT(bugprone-branch-clone)
    else if (typeOfCommand == commandType::subtract)        // command : subtract
        return new AddHandler(current_user_input, inTheList(subtractAlias, 2, current_user_input));
    else if (typeOfCommand == commandType::help)            // command : help
        return new HelpHandler(current_user_input, inTheList(helpAlias, 2, current_user_input));
    else if (typeOfCommand == commandType::quit)           // command : quit
        return new QuitHandler(programTermination);
    else if (typeOfCommand == commandType::blacklist)      // command : blacklist
        return new BlacklistHandler(current_user_input);
    else if (typeOfCommand == commandType::whitelist)      // command : whitelist
        return new WhiteListHandler(current_user_input);
    else                                                   // command : undefined
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
