//
// Created by kshou on 2021/10/26.
//

#ifndef COMMANDPROCESSOR_ADDHANDLER_H
#define COMMANDPROCESSOR_ADDHANDLER_H

#include "InvalidCommandHandler.h"
#include "common.h"
#include <string>

using std::string;

class AddHandler : public InvalidCommandHandler {
    private:
        float decimal_1;
        float decimal_2;
        int signOfdecimal_2;        // signOfdecimal_2 will be -1 if the command prompt to do subtract, 1 if it is add

    public:

        explicit AddHandler(
                const string &nameOnCall);              // a conversion constructor which only consider the sign (do add or subtract)
        explicit AddHandler(const string &user_input,
                            const string &nameOnCall);              // conversion constructor takes a string
        void printErrorMessage();                       // print the error help_text when the user input is invalid
        void handle_command() override;

};


#endif //COMMANDPROCESSOR_ADDHANDLER_H
