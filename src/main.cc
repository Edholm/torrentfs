#include <iostream>
#include "repl.h"

int main(int argc, char const* argv[]) {
    ReadEvalPrint repl;
    repl.Loop();
    return 0;
}
