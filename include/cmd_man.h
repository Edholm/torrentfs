#ifndef TORRENTSH_CMD_MAN_H_
#define TORRENTSH_CMD_MAN_H_

#include <string>
#include "base_cmd.h"

class CmdMan : public BaseCmd{
public:
    CmdMan();
    virtual void Run(std::vector<std::string> &);
    virtual void ConstructArguments();
};

#endif
