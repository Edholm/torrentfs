#include <iostream>
#include <string>
#include <cstdlib>
#include <readline/readline.h>
#include <readline/history.h>
#include <boost/algorithm/string.hpp>

#include "cmds.h"
#include "repl.h"

/*
 * Used for building a list of strings starting with _txt_.
 * State is zero on first call, non-zero on for subsequent calls.
 * Returns a NULL pointer to the caller when there are no more matches.
 */
char* cmd_generator(const char *txt, const int state) {
    static size_t length = 0;
    static auto it       = cmd_map.cbegin();
    std::string name;
    if(state == 0) {
        length = std::strlen(txt);
        it = cmd_map.cbegin();
    }

    while(it != cmd_map.cend()) {
        name = it->first;
        it++;
        if(name.compare(0, length, txt) == 0) {
            return strdup(name.c_str());
        }
    }
    return NULL;
}

/* Provide custom completion for readline */
static char** auto_completion(const char* txt, int start, int end __attribute__ ((unused))) {
    // This prevents appending space to the end of the matching word
    //rl_completion_append_character = '\0';
    char **matches = (char**)NULL;
    if(start == 0) {
        matches = rl_completion_matches(txt, &cmd_generator);
    }
    return matches;
}

ReadEvalPrint::ReadEvalPrint() {}

void ReadEvalPrint::Loop() {
    rl_attempted_completion_function = auto_completion;
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

void ReadEvalPrint::Eval(char *cmdline) {
    char *argv = cmdline;

    // Split the string in two at the first space
    while(*argv) {
        if(*argv == ' ') {
            *argv = '\0';
            argv++;
            break;
        }
        argv++;
    }
    Eval(cmdline, argv);
}

void ReadEvalPrint::Eval(const std::string& cmd, const std::string& argv) {
    if(cmd.empty()) {
         return;
    }

    auto targv = boost::trim_copy(argv);
    std::vector<std::string> args_list;
    if(!targv.empty()) {
        boost::split(args_list, targv, boost::is_space(), boost::token_compress_on);
    }
    try {
         cmd_map.at(cmd)->Run(args_list);
    } catch(std::out_of_range& e) {
        std::cout << "torrentsh: command not found: " << cmd << std::endl;
    }
}

