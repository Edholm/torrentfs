#ifndef TORRENTSH_BASE_CMD_H_
#define TORRENTSH_BASE_CMD_H_

#include <boost/core/noncopyable.hpp>
#include <string>
#include <vector>

class BaseCmd : private boost::noncopyable {
protected:
    std::string man, usage;
public:
    void Usage();
    void Man();
    virtual void Run(std::vector<std::string>) = 0;
};

#endif
