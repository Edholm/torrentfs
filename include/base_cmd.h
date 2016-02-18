#ifndef TORRENTSH_BASE_CMD_H_
#define TORRENTSH_BASE_CMD_H_

#include <string>
#include <vector>

class BaseCmd {
protected:
    std::string man, usage;
public:
    virtual bool ShouldTrigger(const char* cmd) = 0;
    void Usage();
    void Man();
    virtual void Run(std::vector<std::string>) = 0;
};

#endif
