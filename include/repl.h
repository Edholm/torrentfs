#ifndef TORRENTSH_REPL_H_

class ReadEvalPrint {
    char* Read();
    void Eval(char *);

public:
    ReadEvalPrint();
    void Loop();
};

#endif // TORRENTSH_REPL_H_
