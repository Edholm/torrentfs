#ifndef TORRENTSH_REPL_H_
#define TORRENTSH_REPL_H_
#include <string>
#include <vector>

class ReadEvalPrint {
    char* Read();
    void Eval(char *);
    std::vector<std::string> CmdToArgv(char *);

public:
    ReadEvalPrint();
    void Loop();
};

#endif // TORRENTSH_REPL_H_
