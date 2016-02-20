#include <iostream>
#include <string>
#include <cstdlib>
#include <readline/readline.h>
#include <readline/history.h>
#include <boost/algorithm/string.hpp>

#include "cmds.h"
#include "repl.h"

ReadEvalPrint::ReadEvalPrint() {}

void ReadEvalPrint::Loop() {
    while (true) {
        char* cmd = Read();
        if(cmd == NULL) {
            std::cout << std::endl;
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
    std::vector<std::string> argv;
    boost::split(argv, cmd, boost::is_space());
    if(argv[0].empty()) {
         return;
    }

    try {
         cmd_map.at(argv[0])->Run(argv);
    } catch(std::out_of_range& e) {
        std::cout << "torrentsh: command not found: " << cmd << std::endl;
    }
}
