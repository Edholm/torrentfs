#include <iostream>

#include "base_cmd.h"

void BaseCmd::Usage() {
    std::cout << usage << std::endl;
}

void BaseCmd::Man() {
    std::cout << man << std::endl;
}
