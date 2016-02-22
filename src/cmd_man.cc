#include <string>
#include <iostream>

#include "base_cmd.h"
#include "cmd_man.h"
#include "cmds.h"

CmdMan::CmdMan() :
    BaseCmd("man is the program that you use to read documentation on other commands",
            "Usage: man [OPTION...] PAGE") {}

void CmdMan::Run(std::vector<std::string> &argv) {
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

void CmdMan::ConstructArguments() {

}
