#include <iostream>

#include "base_cmd.h"

BaseCmd::BaseCmd(const std::string &m, const std::string& u) : man(m), usage(u) {}

void BaseCmd::Usage() {
    std::cout << usage << std::endl;
}

void BaseCmd::Man() {
    std::cout << man << std::endl;
}
