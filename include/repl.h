#ifndef TORRENTSH_REPL_H_

class ReadEvalPrint {
    char* Read();
    void Eval(char *);

public:
    void Loop();
};

#endif // TORRENTSH_REPL_H_
