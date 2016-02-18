#include <string>
#include <iostream>

#include "cmd_man.h"
#include "cmds.h"

CmdMan::CmdMan() {
    usage = "Usage: man [OPTION...] PAGE";
    man = "man is the program that you use to read documentation on other commands";
}

bool CmdMan::ShouldTrigger(const std::string cmd) {
    return cmd == "man" || cmd == "info";
}

void CmdMan::Run(std::vector<std::string> argv) {
    if(argv.size() == 1) {
        std::cout << "What manual page do you want?" << std::endl;
        Usage();
        Man();
    } else {
        for(auto c : cmds) {
            if(c->ShouldTrigger(argv[1])) {
                c->Man();
                break;
            }
        }
    }
}
