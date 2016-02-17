#include <iostream>
#include <string>
#include <cstdlib>
#include <readline/readline.h>
#include <readline/history.h>

#include "repl.h"

using namespace std;

void ReadEvalPrint::loop() {
    while (true) {
        char* cmd = read();
        if(cmd == NULL) {
            cout << endl;
            exit(0);
        }
        eval(cmd);
        free(cmd);
    }
}

/*
 * Don't forget to free the return value when you're done with it
 */
char* ReadEvalPrint::read() {
    const char* PS1 = "$ ";
    char* cmd = readline(PS1);
    if(cmd && *cmd) {
         add_history(cmd);
    }
    return cmd;
}

void ReadEvalPrint::eval(char* cmd) {
    cout << "You wanted: " << cmd << endl;
}
