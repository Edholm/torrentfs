#include <iostream>
#include <string>
#include <cstdlib>
#include <readline/readline.h>
#include <readline/history.h>
#include <boost/algorithm/string.hpp>

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
    vector<string> argv;
    boost::split(argv, cmd, boost::is_space());
    for(auto cc : cmds) {
        if(cc->ShouldTrigger(argv[0])) {
             cc->Run(argv);
             return;
        }
    }
    cout << "torrentsh: command not found: " << cmd << endl;
}
