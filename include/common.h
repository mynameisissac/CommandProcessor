//
// Created by kshou on 2021/11/21.
//

#ifndef COMMANDPROCESSOR_COMMON_H
#define COMMANDPROCESSOR_COMMON_H

#include <string>

using std::string;

// define all the available commands here
enum class commandType {
    ping,
    say,        // echo, print
    add,        // plus
    subtract,   // minus
    blacklist,  // denylist
    whitelist,  // allowlist
    help,       // man
    quit,       // exit, stop
    undefined   // exceptional case
};

// use const arrays of string to store all the command alias list
const string pingAlias[] = {"ping"};
const string sayAlias[] = {"say", "echo", "print"};
const string addAlias[] = {"add", "plus"};
const string subtractAlias[] = {"subtract", "minus"};
const string blacklistAlias[] = {"blacklist", "denylist"};
const string whitelistAlias[] = {"whitelist", "allowlist"};
const string helpAlias[] = {"help", "man"};
const string quitAlias[] = {"quit", "exit", "stop"};

/**
 * helper function for validateInput(const string&), search whether target is included in the strings in the list
 * @param stringList the list of string to search in
 * @param size the size of the list
 * @param target the string to be searched
 * @return that alias if found, empty string if not found
 */
inline string inTheList(const string stringList[], int size,
                        const string &target) {        // inline keyword for putting function definition in header file
    for (int i = 0; i < size; ++i)
        if (target.rfind(stringList[i], 0) != string::npos)
            return stringList[i];
    return {};               // target not found in the list, return empty string
}

// a function validate current user input and return the corresponding commandType
inline commandType getCommandType(const string &userInput) {
    if (!inTheList(pingAlias, 1, userInput).empty())
        return commandType::ping;
    else if (!inTheList(sayAlias, 3, userInput).empty())
        return commandType::say;
    else if (!inTheList(addAlias, 2, userInput).empty())
        return commandType::add;
    else if (!inTheList(subtractAlias, 2, userInput).empty())
        return commandType::subtract;
    else if (!inTheList(blacklistAlias, 2, userInput).empty())
        return commandType::blacklist;
    else if (!inTheList(whitelistAlias, 2, userInput).empty())
        return commandType::whitelist;
    else if (!inTheList(helpAlias, 2, userInput).empty())
        return commandType::help;
    else if (!inTheList(quitAlias, 3, userInput).empty())
        return commandType::quit;
    else
        return commandType::undefined;              // undefined means invalid commandInput
}


#endif //COMMANDPROCESSOR_COMMON_H
