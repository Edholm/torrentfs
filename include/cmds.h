#ifndef TORRENTSH_CMDS_H_
#define TORRENTSH_CMDS_H_
#include "base_cmd.h"
#include "cmd_man.h"

using namespace std;

vector<BaseCmd*> cmds =  {
    new CmdMan()
};

#endif
