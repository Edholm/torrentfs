#include <string>
#include <iostream>

#include "base_cmd.h"
#include "cmd_man.h"
#include "cmds.h"

CmdMan::CmdMan() :
    BaseCmd("man is the program that you use to read documentation on other commands",
            "Usage: man [OPTION...] PAGE") {
        hid_opt_desc.add_options()
            ("page", po::value<std::vector<std::string>>(), "Manual page");
        pos_opt_desc.add("page", -1);
    }

int CmdMan::Run(const std::vector<std::string> &argv) {
    if(BaseCmd::Run(argv)) { return 1; }

    if(!var_map.count("page")) {
        std::cout << "What manual page do you want?" << std::endl;
    } else {
        try {
            for(auto page : var_map["page"].as<std::vector<std::string>>()) {
                cmd_map.at(page)->Man();
            }
        } catch(std::out_of_range& e) {
            std::cout << "No manual entry for \"" << argv[1] << "\"" << std::endl;
        }
    }
    return 0;
}
