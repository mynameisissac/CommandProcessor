//
// Created by kshou on 2021/10/26.
//

#include "AddHandler.h"
#include <iostream>


// a helper function checking if a string is in a valid decimal number format
bool validDecimal(const string &str) {
    for (char i: str) // NOLINT(readability-use-anyofallof)
        if (i != '.' && (i < '0' || i > '9'))
            return false;

    return true;
}

// constructor of the AddHandler
// assign the decimal values and the sign
AddHandler::AddHandler(const string &user_input)
        : InvalidCommandHandler("Usage: add <decimal1> <decimal2>", false), signOfdecimal_2(1) {
    int posOfSpace1 = (int) user_input.find(' ');                              // the position of the first white space
    int posOfSpace2 = (int) user_input.find(' ', posOfSpace1 + 1);        // the position of the second white space

    if ((posOfSpace1 == string::npos) || posOfSpace1 == user_input.length() - 1)  // not providing first decimal
        errorCode = 1;
    else if (posOfSpace2 == string::npos || posOfSpace2 == user_input.length() - 1)     // not providing second decimal
        errorCode = 2;
    else if (!validDecimal(user_input.substr(posOfSpace1 + 1, posOfSpace2 - posOfSpace1 - 1))
             || !validDecimal(user_input.substr(posOfSpace2 + 1)))
        errorCode = 3;
    else {
        decimal_1 = std::stof(user_input.substr(posOfSpace1 + 1, posOfSpace2 - posOfSpace1 - 1));
        decimal_2 = std::stof(user_input.substr(posOfSpace2 + 1));
    }
    if (user_input.rfind("subtract", 0) != string::npos) {
        help_text = "Usage: subtract <decimal1> <decimal2>";
        signOfdecimal_2 = -1;
    }
}

void AddHandler::handle_command() {

    if (errorCode != 0) {           // if it has error
        if (errorCode == 1)
            std::cout << "No values provided." << std::endl;
        else if (errorCode == 2)
            std::cout << "Two values required." << std::endl;
        else if (errorCode == 3)
            std::cout << "Invalid value." << std::endl;

        InvalidCommandHandler::handle_command();            // this call the handle_command of base class which print the error help text
    } else {
        // calculate the result of addition/subtraction to output
        float response_result =
                decimal_1 + decimal_2 * (float) signOfdecimal_2;   // abs() for converting negative result to positive
        std::cout << response_result << std::endl;
    }
}