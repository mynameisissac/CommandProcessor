#include <iostream>
#include <vector>
#include "Processor.h"

using namespace std;

// print the start message
void startPrint() {
    cout << "Command Processor\nType 'quit' to exit" << endl;
}

int main() {
    startPrint();
    auto *testing = new Processor();       // create a dynamic processor object to process the command
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
