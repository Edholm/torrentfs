#include <iostream>
#include "repl.h"

int main(int argc, char const* argv[]) {
    ReadEvalPrint repl = ReadEvalPrint() ;
    repl.loop();
    return 0;
}
