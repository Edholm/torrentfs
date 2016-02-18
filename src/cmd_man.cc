#include <string.h>
#include <iostream>
#include "cmd_man.h"

bool CmdMan::ShouldTrigger(const char* cmd) {
    return strcmp(cmd, "man") == 0;
}

void CmdMan::Run(std::vector<std::string> argv) {
    std::cout << "You've requested a manual!" << std::endl;
}
