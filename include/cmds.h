#ifndef TORRENTSH_CMDS_H_
#define TORRENTSH_CMDS_H_

#include <memory>
#include <string>
#include <unordered_map>
#include "base_cmd.h"

extern std::unordered_map<std::string, std::shared_ptr<BaseCmd>> cmd_map;

#endif
