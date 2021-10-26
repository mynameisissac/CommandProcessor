//
// Created by kshou on 2021/10/26.
//

#include "AddHandler.h"
#include <iostream>


// constructor of the AddHandler
// assign the decimal values and the sign
AddHandler::AddHandler(const string &user_input)
        : signOfdecimal_2(1) {
    int posOfSpace1 = (int) user_input.find(' ');                              // the position of the first white space
    int posOfSpace2 = (int) user_input.find(' ', posOfSpace1 + 1);        // the position of the second white space
    decimal_1 = std::stof(user_input.substr(posOfSpace1 + 1, posOfSpace2 - posOfSpace1 - 1));
    decimal_2 = std::stof(user_input.substr(posOfSpace2 + 1));
    if (user_input.rfind("subtract", 0) != string::npos)
        signOfdecimal_2 = -1;
}

void AddHandler::handle_command() {
    // calculate the result of addition/subtraction to output
    float response_result =
            decimal_1 + decimal_2 * (float) signOfdecimal_2;   // abs() for converting negative result to positive
    std::cout << response_result << std::endl;
}