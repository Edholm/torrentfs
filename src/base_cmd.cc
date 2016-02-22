#include <iostream>
#include <boost/program_options.hpp>

#include "base_cmd.h"

namespace po = boost::program_options;

BaseCmd::BaseCmd(const std::string &m, const std::string& u) :
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
    po::store(po::command_line_parser(argv)
            .options(opt_desc.add(hid_opt_desc)) // FIXME
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
