//
// Created by kshou on 2021/12/19.
//

#ifndef COMMANDPROCESSOR_CONFIRMATION_H
#define COMMANDPROCESSOR_CONFIRMATION_H


#include <string>

// function object class
class Confirmation {
    private:
        std::string promptText = "Are you sure you want to continue (y/N)? ";

    public:
        Confirmation();       // default constructor
        explicit Confirmation(std::string promptText);

        bool operator()() const;    // overload operator()
};


#endif //COMMANDPROCESSOR_CONFIRMATION_H
