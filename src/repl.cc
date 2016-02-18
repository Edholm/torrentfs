#include <iostream>
#include <string>
#include <cstdlib>
#include <readline/readline.h>
#include <readline/history.h>

#include "repl.h"
#include "cmds.h"

using namespace std;

ReadEvalPrint::ReadEvalPrint() {}

void ReadEvalPrint::Loop() {
    while (true) {
        char* cmd = Read();
        if(cmd == NULL) {
            cout << endl;
            exit(0);
        }
        Eval(cmd);
        free(cmd);
    }
}

/*
 * Don't forget to free the return value when you're done with it
 */
char* ReadEvalPrint::Read() {
    const char* PS1 = "$ ";
    char* cmd = readline(PS1);
    if(cmd && *cmd) {
         add_history(cmd);
    }
    return cmd;
}

void ReadEvalPrint::Eval(char* cmd) {
    for(auto cc : cmds) {
        if(cc->ShouldTrigger(cmd)) {
             cc->Run(vector<string>());
             return;
        }
    }
    cout << "torrentsh: command not found: " << cmd << endl;
}
