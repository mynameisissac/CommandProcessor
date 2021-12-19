//
// Created by kshou on 2021/12/19.
//

#include "../include/Confirmation.h"
#include <iostream>
#include <utility>

// default constructor
Confirmation::Confirmation() = default;

// conversion constructor
Confirmation::Confirmation(std::string promptText) : promptText(std::move(promptText)) {}

bool Confirmation::operator()() const {
    // ask for user confirmation
    std::cout << promptText;
    std::string userResponse;
    std::cin >> userResponse;

    if (userResponse == "y" || userResponse == "Y")
        return true;
    else
        return false;

}