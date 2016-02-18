#include <string>
#include <iostream>
#include "cmd_man.h"

bool CmdMan::ShouldTrigger(const std::string cmd) {
    return cmd == "man" || cmd == "info";
}

void CmdMan::Run(std::vector<std::string> argv) {
    for(auto a : argv) {
        std::cout << "Got: " << a << std::endl;
    }
    std::cout << "You've requested a manual!" << std::endl;
}
