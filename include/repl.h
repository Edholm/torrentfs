#ifndef TORRENTSH_REPL_H_

class ReadEvalPrint {
    char* read();
    void eval(char *);

public:
    void loop();
};

#endif // TORRENTSH_REPL_H_
