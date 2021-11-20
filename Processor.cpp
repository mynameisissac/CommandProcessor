//
// Created by kshou on 2021/10/26.
//

#include <iostream>
#include "Processor.h"
#include <string>
#include <algorithm>

using namespace std;

// definition of the two lists
// which are ListHandler class static data member
vector<string> ListHandler::blacklist;
vector<string> ListHandler::whitelist;


/**
 * helper function for validateInput(const string&), search whether target is included in the strings in the list
 * @param stringList the list of string to search in
 * @param size the size of the list
 * @param target the string to be searched
 * @return true if found, false if not found
 */
bool inTheList(const string stringList[], int size, const string &target) {
    for (int i = 0; i < size; ++i)
        if (target.rfind(stringList[i], 0) != string::npos)
            return true;
    return false;               // target not found in the list
}

/**
 * validate the current user input and pick the correct command Handler Type
 * @return the suitable commandType for commandHandler
 */
commandType Processor::validateInput(const string &userInput) {
    // use const static array of string to store all the command alias list
    const static string pingAlias[] = {"ping"};
    const static string sayAlias[] = {"say", "echo", "print"};
    const static string addAlias[] = {"add", "plus"};
    const static string subtractAlias[] = {"subtract", "minus"};
    const static string blacklistAlias[] = {"blacklist", "denylist"};
    const static string whitelistAlias[] = {"whitelist", "allowlist"};
    const static string helpAlias[] = {"help", "man"};
    const static string quitAlias[] = {"quit", "exit", "stop"};

    if (inTheList(pingAlias, 1, userInput))
        return commandType::ping;
    else if (inTheList(sayAlias, 3, userInput))
        return commandType::say;
    else if (inTheList(addAlias, 2, userInput))
        return commandType::add;
    else if (inTheList(subtractAlias, 2, userInput))
        return commandType::subtract;
    else if (inTheList(blacklistAlias, 2, userInput))
        return commandType::blacklist;
    else if (inTheList(whitelistAlias, 2, userInput))
        return commandType::whitelist;
    else if (inTheList(helpAlias, 2, userInput))
        return commandType::help;
    else if (inTheList(quitAlias, 3, userInput))
        return commandType::quit;
    else
        return commandType::undefined;              // undefined means invalid commandInput
}


/**
 *  process the command : validate the input and choose which CommandHandler to assign for handler
 * @return a pointer to dynamic CommandHandler object
 */
CommandHandler *Processor::response() const {

    // validate the input and find the correct commandType
    commandType typeOfCommand = validateInput(current_user_input);

    // choose which handler to assign
    if (typeOfCommand == commandType::ping)                 // command : add
        return new PingHandler();
    else if (typeOfCommand == commandType::say)             // command : say
        return new SayHandler(current_user_input);
    else if (typeOfCommand == commandType::add)             // command : add
        return new AddHandler(current_user_input);  // NOLINT(bugprone-branch-clone)
    else if (typeOfCommand == commandType::subtract)        // command : subtract
        return new AddHandler(current_user_input);
    else if (typeOfCommand == commandType::help)            // command : help
        return new HelpHandler(current_user_input);
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
