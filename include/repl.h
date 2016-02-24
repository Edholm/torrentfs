#ifndef TORRENTSH_REPL_H_
#define TORRENTSH_REPL_H_
#include <string>
#include <vector>

class ReadEvalPrint {
    char* Read();
    void Eval(char *);
    void Eval(const std::string&, const std::string&);

public:
    ReadEvalPrint();
    void Loop();
};

#endif // TORRENTSH_REPL_H_
