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

    auto pages = var_map["page"].as<std::vector<std::string>>();
    if(pages.empty()) {  // FIXME: never zero...
        std::cout << "What manual page do you want?" << std::endl;
    } else {
        for(auto page : pages) {
            try {
                    cmd_map.at(page)->Man();
            } catch(std::out_of_range& e) {
                std::cout << "No manual entry for \"" << page << "\"" << std::endl;
            }
        }
    }
    return 0;
}
