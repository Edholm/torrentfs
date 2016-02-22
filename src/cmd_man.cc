#include <string>
#include <iostream>

#include "cmd_man.h"
#include "cmds.h"

CmdMan::CmdMan() {
    usage = "Usage: man [OPTION...] PAGE";
    man = "man is the program that you use to read documentation on other commands";
}

void CmdMan::Run(std::vector<std::string> argv) {
    if(argv.size() == 1) {
        std::cout << "What manual page do you want?" << std::endl;
    } else {
        try {
            cmd_map.at(argv[1])->Man();
        } catch(std::out_of_range& e) {
            std::cout << "No manual entry for \"" << argv[1] << "\"" << std::endl;
        }
    }
}
