#include <unordered_map>
#include <string>
#include <memory>

#include "base_cmd.h"
#include "cmd_man.h"

std::unordered_map<std::string, std::shared_ptr<BaseCmd>> cmd_map {
    {"man", std::make_shared<CmdMan>()}
};
