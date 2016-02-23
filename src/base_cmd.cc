#include <iostream>
#include <boost/program_options.hpp>

#include "base_cmd.h"

namespace po = boost::program_options;

BaseCmd::BaseCmd(const std::string &m, const std::string& u) :
            all_opt_desc(po::options_description("All options")),
            man(m), usage(u),
            opt_desc(po::options_description("General options")),
            hid_opt_desc(po::options_description("Hidden")) {
    opt_desc.add_options()
        ("help,h", "Show help message");
}

void BaseCmd::Man() {
    std::cout << man << std::endl;
}

int BaseCmd::Run(const std::vector<std::string> &argv) {
    if(!opts_combined) {
        all_opt_desc.add(opt_desc).add(hid_opt_desc);
        opts_combined = true;
    }
    po::store(po::command_line_parser(argv)
            .options(all_opt_desc)
            .positional(pos_opt_desc)
            .allow_unregistered()
            .run(), var_map);
    po::notify(var_map);

    if(var_map.count("help")) {
        std::cout << usage << std::endl;
        std::cout << opt_desc;
        return 1;
    }
    return 0;
}
