#include <iostream>
#include <vector>
#include "Processor.h"

using namespace std;


int main() {
    // the list of command available for this processor
    vector<string> commandList = {"ping", "say", "add", "subtract", "quit"};

    auto *testing = new Processor(commandList);       // create a dynamic processor object to process the command
    CommandHandler *handler;                                          // handler is to handle different kinds of command
    testing->readInput();                               // read the first input
    while (testing->getCurrentInput() != "quit") {
        handler = testing->response();                  // response() will assign suitable CommandHandler to handler
        handler->handle_command();                      // different handler handle command differently depends on the command
        delete handler;                                 // avoid memory leak
        testing->readInput();
    }

    delete testing;             // avoid memory leak
    return 0;
}
