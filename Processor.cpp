//
// Created by kshou on 2021/10/26.
//

#include <iostream>
#include "Processor.h"
using namespace std;

bool Processor :: validateInput(string user_input) const
{
    for(string s : command_list){
        if (user_input.rfind(s,0) != string::npos)
            return true;
    }
    return false;
}

void Processor :: response() const
{
    string user_input = getRecord();
    if (!validateInput(user_input))             // if user input is not valid
        cout << help_text << endl;

    if (user_input.rfind("say",0) != string::npos) {
        cout << user_input.substr(4) << endl;
        return;
    }


    for (int i=0; i < command_list.size(); i ++){
        if (command_list[i] == user_input) {
            cout << response_list[i] << endl;
        }
    }

}

Processor ::Processor(vector<string> command_list, vector<string> response_list)
    : command_list(command_list), response_list(response_list)
{
}

void Processor :: getInput(){
    string input = "";
    getline(cin, input);
    user_input_record.push_back(input);
}

string Processor :: getRecord() const{
    return getRecord(user_input_record.size()-1);
}

string Processor :: getRecord(int index) const{
    return user_input_record[index];
}
