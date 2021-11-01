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
    bool *const programTermination = new bool;
    auto *testing = new Processor(programTermination);       // create a dynamic processor object to process the command
    CommandHandler *handler;                                          // handler is to handle different kinds of command
    while (!(*programTermination)) {
        testing->readInput();                           // read the input first
        handler = testing->response();                  // response() will assign suitable CommandHandler to handler
        handler->handle_command();                      // different handler handle command differently depends on the command
        delete handler;                                 // avoid memory leak
    }

    // avoid memory leak
    delete testing;
    delete programTermination;
    return 0;
}
